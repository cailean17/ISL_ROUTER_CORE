`timescale 1ns / 1ps

module router_core #(parameter NUM_LINKS = 4, parameter NUM_SATS = 16, parameter SAT_ID = 0, parameter string FIB_FILE = "SAT1_FIB.mem")(
    input clk,
    input reset,
    // Uncomment for Synth and Implementation
    // laser_link_phy_if laser_link_ingress[NUM_LINKS],
    // laser_link_phy_if laser_link_egress[NUM_LINKS]
    // Uncomment for satellite_network_tb simulation
    laser_link_phy_if laser_link_ingress[NUM_LINKS],
    laser_link_phy_if laser_link_egress[NUM_LINKS]
);
    link_adapter_rx_if link_adapter_ingress[NUM_LINKS] ();
    link_adapter_tx_if link_adapter_egress[NUM_LINKS+1] (); // Last link adapter egress is simulated downlink to ground - sinks all the packets whose destination was this router core
    downlink downlink (
        .clk                     (clk),
        .reset                   (reset),
        .s_axis_router_cmd_tvalid(link_adapter_egress[NUM_LINKS].s_axis_router_cmd_tvalid),
        .s_axis_router_cmd_tdata (link_adapter_egress[NUM_LINKS].s_axis_router_cmd_tdata),
        .s_axis_router_cmd_tready(link_adapter_egress[NUM_LINKS].s_axis_router_cmd_tready),
        .m_axis_tx_cmd_tready    (link_adapter_egress[NUM_LINKS].m_axis_tx_cmd_tready),
        .m_axis_tx_cmd_tdata     (link_adapter_egress[NUM_LINKS].m_axis_tx_cmd_tdata),
        .m_axis_tx_cmd_tvalid    (link_adapter_egress[NUM_LINKS].m_axis_tx_cmd_tvalid),
        .s_axis_tx_tdata         (link_adapter_egress[NUM_LINKS].s_axis_tx_tdata),
        .s_axis_tx_tvalid        (link_adapter_egress[NUM_LINKS].s_axis_tx_tvalid),
        .s_axis_tx_tlast         (link_adapter_egress[NUM_LINKS].s_axis_tx_tlast),
        .s_axis_tx_tready        (link_adapter_egress[NUM_LINKS].s_axis_tx_tready)
    );
    l3_buffer_if l3_buffers[NUM_LINKS] ();

    wire fib_write_en;
    wire [$clog2(NUM_SATS)-1:0]  fib_write_addr;
    wire [$clog2(NUM_LINKS):0] fib_write_data;
    reg  [$clog2(NUM_LINKS):0] registered_fib_outputs [NUM_LINKS];

    // Generate for Each Link:
    // - 1 Link Adapter for RX PHY
    // - 1 Link Adapter for TX PHY
    // - 1 L3 Buffer for each RX
    // - 1 FIB copy for each RX
    generate
        for(genvar i = 0; i < NUM_LINKS; i++) begin: main_gen
            link_adapter_rx RX (
                .clk(clk),
                .reset(reset),
                .ISERDES_in(laser_link_ingress[i].data),
                .s_axis_tready(link_adapter_ingress[i].s_axis_tready),
                .s_axis_tdata(link_adapter_ingress[i].s_axis_tdata),
                .s_axis_tvalid(link_adapter_ingress[i].s_axis_tvalid),
                .s_axis_tlast(link_adapter_ingress[i].s_axis_tlast),
                .s_axis_tuser(link_adapter_ingress[i].s_axis_tuser)
            );
            link_adapter_tx TX (
                .clk(clk),
                .reset(reset),
                .s_axis_router_cmd_tvalid(link_adapter_egress[i].s_axis_router_cmd_tvalid),
                .s_axis_router_cmd_tdata(link_adapter_egress[i].s_axis_router_cmd_tdata),
                .s_axis_router_cmd_tready(link_adapter_egress[i].s_axis_router_cmd_tready),
                .m_axis_tx_cmd_tready(link_adapter_egress[i].m_axis_tx_cmd_tready),
                .m_axis_tx_cmd_tdata(link_adapter_egress[i].m_axis_tx_cmd_tdata),
                .m_axis_tx_cmd_tvalid(link_adapter_egress[i].m_axis_tx_cmd_tvalid),
                .s_axis_tx_tready(link_adapter_egress[i].s_axis_tx_tready),
                .s_axis_tx_tdata(link_adapter_egress[i].s_axis_tx_tdata),
                .s_axis_tx_tvalid(link_adapter_egress[i].s_axis_tx_tvalid),
                .s_axis_tx_tlast(link_adapter_egress[i].s_axis_tx_tlast),

                .OSERDES_out(laser_link_egress[i].data)
            );
            l3_buffer L3_BUF (
                .clk(clk),
                .reset(reset),
                .s_axis_rx_tready(link_adapter_ingress[i].s_axis_tready),
                .s_axis_rx_tdata(link_adapter_ingress[i].s_axis_tdata),
                .s_axis_rx_tvalid(link_adapter_ingress[i].s_axis_tvalid),
                .s_axis_rx_tlast(link_adapter_ingress[i].s_axis_tlast),
                .s_axis_rx_tuser(link_adapter_ingress[i].s_axis_tuser),

                .m_axis_pkt_desc_tdata(l3_buffers[i].m_axis_pkt_desc_tdata),
                .m_axis_pkt_desc_tvalid(l3_buffers[i].m_axis_pkt_desc_tvalid),
                .m_axis_pkt_desc_tready(l3_buffers[i].m_axis_pkt_desc_tready),

                .s_axis_tx_cmd_tdata(l3_buffers[i].s_axis_tx_cmd_tdata),
                .s_axis_tx_cmd_tvalid(l3_buffers[i].s_axis_tx_cmd_tvalid),
                .s_axis_tx_cmd_tready(l3_buffers[i].s_axis_tx_cmd_tready),

                .m_axis_tx_tdata(l3_buffers[i].m_axis_tx_tdata),
                .m_axis_tx_tvalid(l3_buffers[i].m_axis_tx_tvalid),
                .m_axis_tx_tlast(l3_buffers[i].m_axis_tx_tlast),
                .m_axis_tx_tready(l3_buffers[i].m_axis_tx_tready)
            );
            // LUTRAM FIBS (UPDATED FROM GROUND STATION UPLINK) 1 COPY FOR EACH RX
            (* ram_style = "distributed" *) reg [$clog2(NUM_LINKS):0] FIB [NUM_SATS];
            initial begin
                $readmemh(FIB_FILE, FIB);
            end
            always @(posedge clk) begin
                if (reset) begin
                    // foreach (FIB[j]) begin
                    //     FIB[j] <= '0;
                    // end
                    registered_fib_outputs[i] <= 0;
                end else begin
                    if (fib_write_en) begin
                        FIB[fib_write_addr] <= fib_write_data;
                    end
                    if(l3_buffers[i].m_axis_pkt_desc_tvalid) begin
                        registered_fib_outputs[i] <= FIB[l3_buffers[i].m_axis_pkt_desc_tdata.dest_sat];
                    end
                end
            end
        end
    endgenerate

    // l3 buffer -> tx crossbar arbiters logic
    // egress link 0 -> 0100 (l3 buffer 2's packet desc requests egress 0)
    // egress link 1 -> 0111 (l3 buffer 0,1,2 requests egress 1)
    logic [NUM_LINKS-1:0] crossbar_arbiters_request_matrix [NUM_LINKS+1];
    logic [NUM_LINKS:0] crossbar_arbiters_grant_active_output;
    logic [$clog2(NUM_LINKS)-1:0] crossbar_arbiters_granted_idx_output [NUM_LINKS+1];
    generate
        for(genvar j = 0; j <= NUM_LINKS; j++) begin: crossbar_arbiter_gen
            crossbar_arbiter #(.NUM_LINKS(NUM_LINKS)) CB(
                .clk(clk),
                .reset(reset),
                .request_matrix(crossbar_arbiters_request_matrix[j]),
                .l3_buffers(l3_buffers),
                .link_adapter_egress(link_adapter_egress[j]),
                .grant_active(crossbar_arbiters_grant_active_output[j]),
                .granted_idx(crossbar_arbiters_granted_idx_output[j])
            );
        end

        for(genvar k = 0; k < NUM_LINKS; k++) begin: crossbar_arbiter_requests_gen
            always @(*) begin
                for (int e = 0; e <= NUM_LINKS; e++) begin
                    crossbar_arbiters_request_matrix[e][k] = 0;
                end
                if (l3_buffers[k].m_axis_pkt_desc_tvalid) begin
                    crossbar_arbiters_request_matrix[registered_fib_outputs[k]][k] = 1'b1;
                end
            end
        end

        // extract egresss packet descriptor interface axi ready signal to use without indexing the interface (because indexing interfaces with runtime variables (int) is illegal in Verilog)
        logic egress_s_axis_router_cmd_tready_signals [NUM_LINKS:0];
        for(genvar l = 0; l <= NUM_LINKS; l++) begin : crossbar_arbiter_signal_extract
            always @(*) begin
                egress_s_axis_router_cmd_tready_signals[l] = link_adapter_egress[l].s_axis_router_cmd_tready;
            end
        end

        // drive the ingress interface axi ready signals using crossbar outputs and 
        for (genvar m = 0; m < NUM_LINKS; m++) begin : demux_crossbar_arbiter
             always_comb begin
                l3_buffers[m].m_axis_pkt_desc_tready = 0;
                for (int j = 0; j <= NUM_LINKS; j++) begin
                    if(crossbar_arbiters_grant_active_output[j] && crossbar_arbiters_granted_idx_output[j] == m) begin
                        l3_buffers[m].m_axis_pkt_desc_tready = egress_s_axis_router_cmd_tready_signals[j];
                    end
                end
             end
        end
    endgenerate

    // tx -> l3_buffer arbiter 
    logic [NUM_LINKS:0] l3_buffer_arbiters_request_matrix [NUM_LINKS];
    logic [NUM_LINKS-1:0] l3_buffer_arbiters_grant_active_output;
    logic [$clog2(NUM_LINKS):0] l3_buffer_arbiters_granted_idx_output [NUM_LINKS];
    generate
        for(genvar j = 0; j < NUM_LINKS; j++) begin: l3_buffer_arbiter_gen
            l3_buffer_arbiter #(
                .NUM_LINKS(NUM_LINKS)
             ) l3_buffer_arbiter (
                .clk                (clk),
                .reset              (reset),
                .request_matrix     (l3_buffer_arbiters_request_matrix[j]),
                .link_adapter_egress(link_adapter_egress),
                .l3_buffer          (l3_buffers[j]),
                .grant_active       (l3_buffer_arbiters_grant_active_output[j]),
                .granted_idx        (l3_buffer_arbiters_granted_idx_output[j])
            );
        end
        for(genvar k = 0; k <= NUM_LINKS; k++) begin: l3_buffer_arbiter_requests_gen
            always @(*) begin
                for (int e = 0; e < NUM_LINKS; e++) begin
                    l3_buffer_arbiters_request_matrix[e][k] = 0;
                end
                if (link_adapter_egress[k].m_axis_tx_cmd_tvalid) begin
                    l3_buffer_arbiters_request_matrix[link_adapter_egress[k].m_axis_tx_cmd_tdata.buffer_id][k] = 1'b1;
                end
            end
        end
        logic [7:0] l3_buffer_m_axis_tx_tdata_signals [NUM_LINKS-1:0];
        logic l3_buffer_m_axis_tx_tvalid_signals [NUM_LINKS-1:0];
        logic l3_buffer_m_axis_tx_tlast_signals [NUM_LINKS-1:0];
        logic l3_buffer_s_axis_tx_cmd_tready_signals [NUM_LINKS-1:0];
        for(genvar l = 0; l < NUM_LINKS; l++) begin : l3_buffer_arbiter_signal_extract
            always_comb begin
                l3_buffer_m_axis_tx_tdata_signals[l] = l3_buffers[l].m_axis_tx_tdata;
                l3_buffer_m_axis_tx_tvalid_signals[l] = l3_buffers[l].m_axis_tx_tvalid;
                l3_buffer_m_axis_tx_tlast_signals[l] = l3_buffers[l].m_axis_tx_tlast;
                l3_buffer_s_axis_tx_cmd_tready_signals[l] = l3_buffers[l].s_axis_tx_cmd_tready;
            end
        end
        for(genvar m = 0; m <= NUM_LINKS; m++) begin : demux_l3_buffer_arbiter
            always_comb begin
                link_adapter_egress[m].s_axis_tx_tdata = 0;
                link_adapter_egress[m].s_axis_tx_tvalid = 0;
                link_adapter_egress[m].s_axis_tx_tlast = 0;
                link_adapter_egress[m].m_axis_tx_cmd_tready = 0;
                for(int i = 0; i < NUM_LINKS; i++) begin
                    if (l3_buffer_arbiters_grant_active_output[i] && l3_buffer_arbiters_granted_idx_output[i] == m) begin
                        link_adapter_egress[m].s_axis_tx_tdata = l3_buffer_m_axis_tx_tdata_signals[i];
                        link_adapter_egress[m].s_axis_tx_tvalid = l3_buffer_m_axis_tx_tvalid_signals[i];
                        link_adapter_egress[m].s_axis_tx_tlast = l3_buffer_m_axis_tx_tlast_signals[i];
                        link_adapter_egress[m].m_axis_tx_cmd_tready = l3_buffer_s_axis_tx_cmd_tready_signals[i];
                    end
                end
            end
        end

        logic link_adapter_egress_s_axis_tx_tready_signals [NUM_LINKS+1];
        for(genvar l = 0; l <= NUM_LINKS; l++) begin: link_adapter_egress_signal_extract
            always_comb begin
                link_adapter_egress_s_axis_tx_tready_signals[l] = link_adapter_egress[l].s_axis_tx_tready;
            end
        end

        for(genvar m = 0; m < NUM_LINKS; m++) begin: demux_link_adapter_egress
            always_comb begin
                l3_buffers[m].m_axis_tx_tready = 0;
                if(l3_buffer_arbiters_grant_active_output[m]) begin
                    l3_buffers[m].m_axis_tx_tready = link_adapter_egress_s_axis_tx_tready_signals[l3_buffer_arbiters_granted_idx_output[m]];
                end
            end
        end
    endgenerate
endmodule
