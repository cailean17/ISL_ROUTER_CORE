## Custom RTL Router Core for LEO Satellite Networks with ISL PHY

**Overview:** 
- A passion-project to develop efficient, intuitive microarchitecture for a router switch core on LEO Satellites.
- Fully implemented and closed @ 200Mhz on Artix-7 XC7A100T-1CSG324C with proven 1.6Gbps throughput and pathways for 2x and 4x scaling provided bus-width scaling.  

**Design Verification:** 
- Each module is verified using [CocoTB](https://www.cocotb.org/) & [Verilator](https://www.veripool.org/verilator/) with self-checking testbenches following Directed, Constrained Random Verification/Score-boarding principles
- Global 90% Functional Coverage
- All testbenches are located under `./cocotb/{module_name}` alongside LCOV HTML coverage reports
  
**Implementation & Usage Report:**

## RTL Modules and Hierarchy
