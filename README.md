# Overview

This project implements a parameterized communication bus inspired by a simplified CAN bus architecture, based on the AXI-Lite interface protocol. Designed for real-world industrial applications, this SystemVerilog implementation provides a lightweight, efficient communication solution for control registers and simple peripherals.
AXI-Lite, a subset of the AMBA AXI4 protocol from AMD, is optimized for single-transaction-per-address communication, typically supporting 32 or 64-bit data widths. Our implementation simplifies the protocol further by using fixed 32-bit data bus widths and single-beat bursts, reducing complexity while maintaining compatibility with AXI-Lite standards.

<p align="center">
  <img src="https://github.com/user-attachments/assets/8a2b5a8c-d1e8-4023-93d2-33127b605381" alt="AXI Lite diagram" width="50%">  <br><em>AXI-Lite schema</em>
</p>

The system employs a master-slave architecture with handshake mechanisms for flow control, ensuring reliable data transfer between components while accommodating varying processing speeds.

# Architecture

The architecture is divided into three main components:

- Master interface

* States: IDLE, ADDRESS PHASE, DATA PHASE (encoded with 2 bits);

* Functionality: Initializes data, writes addresses and data for testing, and uses ready signals to transition between states;

* Operation: The master initiates transactions and manages the communication flow;
    
- Bus interface

* Components:

1. bus_if: Handles data direction and signal routing.

2. arbiter: Interconnects signals between buses with simple logic for dual-bus transmission.

* Functionality: Manages data transmission and signal interconnection between master and slav;

- Slave Interface

* States: Three-state FSM (same encoding as master);

* Functionality: Responds to valid signals to transition between states, with sequential logic handling read data and combinational logic managing state transitions;

* Operation: Receives data from master and sends ready signals to acknowledge receipt;

## Finite state machine(FSM)

Both master and slave interfaces utilize identical state encoding in separate FSMs, synchronized to ensure proper communication. The FSM approach ensures predictable behavior and reliable handshake mechanisms.

<p align="center">
  <img height="958" src="https://github.com/user-attachments/assets/d70b991e-36a6-4dda-8b19-e62aea8894b4" alt="FSM_behavior" width="1774">  <br><em>Finite State Machine</em>
</p>


# Simulation and test

## Testbench 

1. Design Under Test (DUT): Instantiates all interfaces for simulation.

2. Initialization: Handles clock and reset signals with proper parameter module usage.

3. Challenge Resolution: Initial clock/reset declaration issues were resolved through proper parameterization.

## Sim_main

* Tool: Verilator compilation with C++ simulation.

* Features:

1. Uses verilated_vcd_c header for waveform tracing.
2. Implements clock deactivation/reactivation cycles with reset application.
3. Analyzes 100 time samples for comprehensive testing.
4. Generates waveform files compatible with GTKWave.

# Test

* Initial Issue: Array read_data in master and slave models was initialized to zero and not properly called;

* Solution: Set read high during master address phase for testing;

* Verification: Successful data activation with synchronized master/slave states;

* Observation: State repetition occurs every 5 clock edges with synchronized ready_r and ready signals due to arbiter interconnection;


# Compilation prerequisites

<p align="center">
  <img height="595" src="https://github.com/user-attachments/assets/1910a182-26b7-4957-8f7f-303b3d15d7f0" alt="compilation" width="1725">  <br><em>Successful Compilation </em>
</p>

## Ubuntu/Debian

```
sudo apt update && sudo apt upgrade -y

sudo apt install iverilog -y

sudo apt install gtkwave -y

sudo apt install verilator git help2man perl python3 make g++ -y

sudo apt install libfl2 libfl-dev zlibc zlib1g zlib1g-dev -y


autoconf
```

Once the installation is complete, we will have successfully installed Icarus Verilog in our Ubuntu machine.

```
cd <project_directory>

chmod +x run_verilator.sh

./run_verilator.sh
```

<p align="center">
  <img height="2470" src="https://github.com/user-attachments/assets/b178a8ea-d472-4926-b9b4-9fcb2c9f6bda" alt="compilation_path" width="3791">  <br><em>Compilation path</em>
</p>


## Output

* Waveform file (wave.vcd) in project root directory;

* Build directory with compiled artifacts;

* Automatic cleanup of previous builds via garbage collection in script;
    
# Observations

1. Master bus requires two rising edges of the ready signal for read activation.
2. Active write operations display both address and transmitted data.
3. No address or data displayed when both write and read are low.
4. Address remains constant throughout the transaction cycle.

<p align="center">
  <img height="545" src="https://github.com/user-attachments/assets/88110932-c2ff-4e02-a539-97dbab677a15" alt="bus_master_behavior" width="1914"> <br><em>Master bus behaviour</em>
</p>


<p align="center">
  <img height="522" src="https://github.com/user-attachments/assets/5ff89ba2-12f4-4a69-bc1b-93a3a7280ec0" alt="slave_and_bus" width="1911"> <br><em>Slaver bus behaviour</em>
</p>

<p align="center">
  <img height="545" src="https://github.com/user-attachments/assets/847d9bc6-499a-4ac0-b7b0-d1b520daaf50" alt="master_slave_behavior" width="1914">  <br><em>The bus behaviour</em>
</p>

## Limitations

* Designed for single master and slave configuration;
* No support for multiple masters or slaves;
* No sophisticated logic for dividing ready and valid signals between address and data phases;
* Package-based state encoding not implemented due to compilation constraints;

## Future enhancements

* Physical FPGA implementation with dedicated testbench;
* Support for multiple masters and slaves;
* Enhanced state management through proper package implementation;
* Improved arbitration logic for complex scenarios;


# Initial errors and corrections

1. Memory Access in Arbiter: Incorrectly placed slave memory assignment within arbiter module. Solution: Removed memory access from arbiter.

2. FSM Packaging: Should have placed FSM in a separate package for better code organization. Solution: Used include statements instead (due to Icarus Verilog limitations with SystemVerilog packages).

3. Interface Instantiation: Wrong interface instantiation in arbiter (bus_if inter(clk);). Solution: Corrected to bus_if inter();.

4. Signal Naming: Used non-existent signals (serv_*) in arbiter interconnections. Solution: Corrected to proper signal names.

5. Testbench Structure: Missing interface instantiations in testbench module. Solution: Added proper interface instantiation.

6. Arbiter Implementation: Unnecessary bus instantiation in arbiter. Solution: Simplified arbiter structure.

7. Task Usage: Incorrect task implementation for slave response. Solution: Removed unnecessary tasks, focused on master_read functionality.

8. Interface Declaration: Improper modport specification in arbiter arguments. Solution: Corrected to explicit interface declarations.

9. Compilation Issues: Icarus Verilog limitations with SystemVerilog packages. Solution: Used include statements instead of packages.

# Conclusion

This project successfully implements a parameterized AXI-Lite communication bus in SystemVerilog, demonstrating practical knowledge of hardware description languages, simulation tools, and verification methodologies. Despite initial challenges with toolchain compatibility and architectural decisions, the final implementation provides a functional, testable system that serves as a foundation for more complex communication architectures.
The development process significantly enhanced skills in SystemVerilog programming, bash scripting, and C++ integration for hardware simulation. Extensive testing and iterative refinement ensured a robust final product suitable for educational and prototyping purposes.

# Reference

https://www.researchgate.net/figure/AXI-lite-interface-hardware-behaviour_fig4_311865597

Made by RAYPCB in medium: https://medium.com/@raypcb/interfacing-with-axi-peripherals-in-rtl-a-comprehensive-guide-3c2284de4d15

Made by Dillon Huff in youtube: https://www.youtube.com/watch?v=1zw1HBsjDH8

Made by Stephen St. Michael: https://www.allaboutcircuits.com/technical-articles/what-are-axi-interconnects-tutorial-master-slave-digital-logic/

Made by AMD: https://docs.amd.com/v/u/en-US/pg161-axi-master-lite
