`timescale 1ns / 1ps

module satellite_network;
    localparam int NUM_LINKS = 4;
    localparam int NUM_SATS  = 16;

    logic clk;
    logic reset;


    // ---------------- Satellite 0 ----------------
    laser_link_phy_if sat_0_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_0_egress  [NUM_LINKS] ();
    logic [7:0] sat_0_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (0),
        .FIB_FILE  ("../../utils/FIBS//SAT0_FIB.mem")
    ) sat_0 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_0_ingress),
        .laser_link_egress (sat_0_egress),
        .uplink_data       (sat_0_uplink_data)
    );


    // ---------------- Satellite 1 ----------------
    laser_link_phy_if sat_1_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_1_egress  [NUM_LINKS] ();
    logic [7:0] sat_1_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (1),
        .FIB_FILE  ("../../utils/FIBS//SAT1_FIB.mem")
    ) sat_1 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_1_ingress),
        .laser_link_egress (sat_1_egress),
        .uplink_data       (sat_1_uplink_data)
    );


    // ---------------- Satellite 2 ----------------
    laser_link_phy_if sat_2_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_2_egress  [NUM_LINKS] ();
    logic [7:0] sat_2_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (2),
        .FIB_FILE  ("../../utils/FIBS//SAT2_FIB.mem")
    ) sat_2 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_2_ingress),
        .laser_link_egress (sat_2_egress),
        .uplink_data       (sat_2_uplink_data)
    );


    // ---------------- Satellite 3 ----------------
    laser_link_phy_if sat_3_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_3_egress  [NUM_LINKS] ();
    logic [7:0] sat_3_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (3),
        .FIB_FILE  ("../../utils/FIBS//SAT3_FIB.mem")
    ) sat_3 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_3_ingress),
        .laser_link_egress (sat_3_egress),
        .uplink_data       (sat_3_uplink_data)
    );


    // ---------------- Satellite 4 ----------------
    laser_link_phy_if sat_4_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_4_egress  [NUM_LINKS] ();
    logic [7:0] sat_4_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (4),
        .FIB_FILE  ("../../utils/FIBS//SAT4_FIB.mem")
    ) sat_4 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_4_ingress),
        .laser_link_egress (sat_4_egress),
        .uplink_data       (sat_4_uplink_data)
    );


    // ---------------- Satellite 5 ----------------
    laser_link_phy_if sat_5_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_5_egress  [NUM_LINKS] ();
    logic [7:0] sat_5_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (5),
        .FIB_FILE  ("../../utils/FIBS//SAT5_FIB.mem")
    ) sat_5 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_5_ingress),
        .laser_link_egress (sat_5_egress),
        .uplink_data       (sat_5_uplink_data)
    );


    // ---------------- Satellite 6 ----------------
    laser_link_phy_if sat_6_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_6_egress  [NUM_LINKS] ();
    logic [7:0] sat_6_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (6),
        .FIB_FILE  ("../../utils/FIBS//SAT6_FIB.mem")
    ) sat_6 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_6_ingress),
        .laser_link_egress (sat_6_egress),
        .uplink_data       (sat_6_uplink_data)
    );


    // ---------------- Satellite 7 ----------------
    laser_link_phy_if sat_7_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_7_egress  [NUM_LINKS] ();
    logic [7:0] sat_7_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (7),
        .FIB_FILE  ("../../utils/FIBS//SAT7_FIB.mem")
    ) sat_7 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_7_ingress),
        .laser_link_egress (sat_7_egress),
        .uplink_data       (sat_7_uplink_data)
    );


    // ---------------- Satellite 8 ----------------
    laser_link_phy_if sat_8_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_8_egress  [NUM_LINKS] ();
    logic [7:0] sat_8_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (8),
        .FIB_FILE  ("../../utils/FIBS//SAT8_FIB.mem")
    ) sat_8 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_8_ingress),
        .laser_link_egress (sat_8_egress),
        .uplink_data       (sat_8_uplink_data)
    );


    // ---------------- Satellite 9 ----------------
    laser_link_phy_if sat_9_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_9_egress  [NUM_LINKS] ();
    logic [7:0] sat_9_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (9),
        .FIB_FILE  ("../../utils/FIBS//SAT9_FIB.mem")
    ) sat_9 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_9_ingress),
        .laser_link_egress (sat_9_egress),
        .uplink_data       (sat_9_uplink_data)
    );


    // ---------------- Satellite 10 ----------------
    laser_link_phy_if sat_10_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_10_egress  [NUM_LINKS] ();
    logic [7:0] sat_10_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (10),
        .FIB_FILE  ("../../utils/FIBS//SAT10_FIB.mem")
    ) sat_10 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_10_ingress),
        .laser_link_egress (sat_10_egress),
        .uplink_data       (sat_10_uplink_data)
    );


    // ---------------- Satellite 11 ----------------
    laser_link_phy_if sat_11_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_11_egress  [NUM_LINKS] ();
    logic [7:0] sat_11_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (11),
        .FIB_FILE  ("../../utils/FIBS//SAT11_FIB.mem")
    ) sat_11 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_11_ingress),
        .laser_link_egress (sat_11_egress),
        .uplink_data       (sat_11_uplink_data)
    );


    // ---------------- Satellite 12 ----------------
    laser_link_phy_if sat_12_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_12_egress  [NUM_LINKS] ();
    logic [7:0] sat_12_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (12),
        .FIB_FILE  ("../../utils/FIBS//SAT12_FIB.mem")
    ) sat_12 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_12_ingress),
        .laser_link_egress (sat_12_egress),
        .uplink_data       (sat_12_uplink_data)
    );


    // ---------------- Satellite 13 ----------------
    laser_link_phy_if sat_13_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_13_egress  [NUM_LINKS] ();
    logic [7:0] sat_13_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (13),
        .FIB_FILE  ("../../utils/FIBS//SAT13_FIB.mem")
    ) sat_13 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_13_ingress),
        .laser_link_egress (sat_13_egress),
        .uplink_data       (sat_13_uplink_data)
    );


    // ---------------- Satellite 14 ----------------
    laser_link_phy_if sat_14_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_14_egress  [NUM_LINKS] ();
    logic [7:0] sat_14_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (14),
        .FIB_FILE  ("../../utils/FIBS//SAT14_FIB.mem")
    ) sat_14 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_14_ingress),
        .laser_link_egress (sat_14_egress),
        .uplink_data       (sat_14_uplink_data)
    );


    // ---------------- Satellite 15 ----------------
    laser_link_phy_if sat_15_ingress [NUM_LINKS] ();
    laser_link_phy_if sat_15_egress  [NUM_LINKS] ();
    logic [7:0] sat_15_uplink_data;

    router_core #(
        .NUM_LINKS (NUM_LINKS),
        .NUM_SATS  (NUM_SATS),
        .SAT_ID    (15),
        .FIB_FILE  ("../../utils/FIBS//SAT15_FIB.mem")
    ) sat_15 (
        .clk               (clk),
        .reset             (reset),
        .laser_link_ingress(sat_15_ingress),
        .laser_link_egress (sat_15_egress),
        .uplink_data       (sat_15_uplink_data)
    );


    // ---------------- Physical links ----------------
    // One assign per direction: satellite A, link la  ->  satellite B, link lb.
    // Every undirected link appears in both nodes' edge lists, so both directions are generated.


    assign sat_1_ingress[0].data = sat_0_egress[1].data;

    assign sat_4_ingress[3].data = sat_0_egress[2].data;

    assign sat_3_ingress[1].data = sat_0_egress[0].data;

    assign sat_12_ingress[2].data = sat_0_egress[3].data;



    assign sat_0_ingress[1].data = sat_1_egress[0].data;

    assign sat_2_ingress[0].data = sat_1_egress[1].data;

    assign sat_5_ingress[3].data = sat_1_egress[2].data;

    assign sat_13_ingress[2].data = sat_1_egress[3].data;



    assign sat_1_ingress[1].data = sat_2_egress[0].data;

    assign sat_3_ingress[0].data = sat_2_egress[1].data;

    assign sat_6_ingress[3].data = sat_2_egress[2].data;

    assign sat_14_ingress[2].data = sat_2_egress[3].data;



    assign sat_2_ingress[1].data = sat_3_egress[0].data;

    assign sat_0_ingress[0].data = sat_3_egress[1].data;

    assign sat_7_ingress[3].data = sat_3_egress[2].data;

    assign sat_15_ingress[2].data = sat_3_egress[3].data;



    assign sat_0_ingress[2].data = sat_4_egress[3].data;

    assign sat_5_ingress[0].data = sat_4_egress[1].data;

    assign sat_8_ingress[3].data = sat_4_egress[2].data;

    assign sat_7_ingress[1].data = sat_4_egress[0].data;



    assign sat_1_ingress[2].data = sat_5_egress[3].data;

    assign sat_4_ingress[1].data = sat_5_egress[0].data;

    assign sat_6_ingress[0].data = sat_5_egress[1].data;

    assign sat_9_ingress[3].data = sat_5_egress[2].data;



    assign sat_2_ingress[2].data = sat_6_egress[3].data;

    assign sat_5_ingress[1].data = sat_6_egress[0].data;

    assign sat_7_ingress[0].data = sat_6_egress[1].data;

    assign sat_10_ingress[3].data = sat_6_egress[2].data;



    assign sat_3_ingress[2].data = sat_7_egress[3].data;

    assign sat_6_ingress[1].data = sat_7_egress[0].data;

    assign sat_4_ingress[0].data = sat_7_egress[1].data;

    assign sat_11_ingress[3].data = sat_7_egress[2].data;



    assign sat_4_ingress[2].data = sat_8_egress[3].data;

    assign sat_9_ingress[0].data = sat_8_egress[1].data;

    assign sat_12_ingress[3].data = sat_8_egress[2].data;

    assign sat_11_ingress[1].data = sat_8_egress[0].data;



    assign sat_5_ingress[2].data = sat_9_egress[3].data;

    assign sat_8_ingress[1].data = sat_9_egress[0].data;

    assign sat_10_ingress[0].data = sat_9_egress[1].data;

    assign sat_13_ingress[3].data = sat_9_egress[2].data;



    assign sat_6_ingress[2].data = sat_10_egress[3].data;

    assign sat_9_ingress[1].data = sat_10_egress[0].data;

    assign sat_11_ingress[0].data = sat_10_egress[1].data;

    assign sat_14_ingress[3].data = sat_10_egress[2].data;



    assign sat_7_ingress[2].data = sat_11_egress[3].data;

    assign sat_10_ingress[1].data = sat_11_egress[0].data;

    assign sat_8_ingress[0].data = sat_11_egress[1].data;

    assign sat_15_ingress[3].data = sat_11_egress[2].data;



    assign sat_8_ingress[2].data = sat_12_egress[3].data;

    assign sat_13_ingress[0].data = sat_12_egress[1].data;

    assign sat_0_ingress[3].data = sat_12_egress[2].data;

    assign sat_15_ingress[1].data = sat_12_egress[0].data;



    assign sat_9_ingress[2].data = sat_13_egress[3].data;

    assign sat_12_ingress[1].data = sat_13_egress[0].data;

    assign sat_14_ingress[0].data = sat_13_egress[1].data;

    assign sat_1_ingress[3].data = sat_13_egress[2].data;



    assign sat_10_ingress[2].data = sat_14_egress[3].data;

    assign sat_13_ingress[1].data = sat_14_egress[0].data;

    assign sat_15_ingress[0].data = sat_14_egress[1].data;

    assign sat_2_ingress[3].data = sat_14_egress[2].data;



    assign sat_11_ingress[2].data = sat_15_egress[3].data;

    assign sat_14_ingress[1].data = sat_15_egress[0].data;

    assign sat_12_ingress[0].data = sat_15_egress[1].data;

    assign sat_3_ingress[3].data = sat_15_egress[2].data;



endmodule