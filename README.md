# Overview

This project search to use parameterized communication bus like a personal can bus homemade based in a mini AXI-Lite interface. The reason of this work is a real implementation in SystemVerilog that can be used in an industry.
Firstly, the AXI-Lite is a light bus protocol originated from AMD ideal to a communication with control registers and simple peripheral. Originally It was think to support 32 or 64 bits. It do only one transaction by address. 
Usually, this kind of project is made with the masters, interface and slavers. The master is responsible to send valid signal to slaver, and interface implement the Bursts protocol that is biddable to tranfer one specific data and address to other slaver. The slaver is responsible to send ready signal to master telling that can receive a data from master. Moreover, the handshake mechanism that works to control the flow of data, throtlling the speed if needed. It is used a lot because we need to implement a method to check if the valid and ready is high to send and receive a specific data obeying the clock behaviour.
Endly, how I used AXI-Lite and it's a subset of AXI4 protocol. It reduced the complexity with all bursts composed by 1 beat and data accesses use the full data bus width of 32 bits.

# Architecture

The architecture is divided amoung master interface, bus interface and slave interface.

'/home/gabriel-cruz/Área de trabalho/project_photos/AXI_LIte.jpeg' 

The master interface was tought to be made with 3 states dubbed: IDLE, DATA PHASE and ADDRESS PHASE. These states was codified with 2 bits. The IDLE state initialize the data and write down a specific address and data to be test and ready signal define if it'll going to another phase.
The bus inteface is responsible send the data and interconnect the signals. This part of the project was divided between bus_if and arbiter to make the specific functionalities. Being the bus_if responsible for data direction and the arbiter file biddable to interconnect the signals with a simple logic to transmit both two bus.

'/home/gabriel-cruz/Área de trabalho/project_photos/arbiter.png' 

The slaver interface was tought to be made with 3 states too, whereas the slaver use valid signal to change to another states. Moreover, the read signal is codified and used in sequential and combinational logic, being that the sequential logic handle the read data and combinational logic handle with states.

## Finite state machine(FSM)

The project was tought to be work with FSMs in which every states are encoded with specific address. The master and slaver FSM has equal encoding. It works because they are running in different files and works together with the same state to send and receive informations. 

'/home/gabriel-cruz/Área de trabalho/project_photos/FSM_behavior.png'

## Testbench 

The testbench was tought to be initialize the signals and data, which we instantiate the interfaces and follow the Design Under Test(DUT) for be a target to simulate in sim_main file.
Initially the testbench has a lot of problem with clk and reset declaration, but I learned that the those data need to be use in parameter module.

## Sim_main

This file was needed due to the verilator compilation and code simulations. It file used tracing,thus we ringed on of the verilated_vcd_c header. Initially was desactivated the clock and reactivated the reset applying this mechanism for some cycles. Nonetheless, we analyzed the dump file for about 100 samples of times.Hence these simulations was responsible to generates the waves in GTKWave.

# Test

Was made a lot of system test with GTKWave and we saw that initially the array read_ata in master and slaver model was set to zero and it didn't call in the project, thus we changed the files to set the read to high in master addr phase to be tested and we saw that the data was sucessful activated and master and slaver was has been in same state and be activated together. It is due to the arbiter code which only inteconeect two interfaces with simple assignments.

# Compilation

'/home/gabriel-cruz/Área de trabalho/project_photos/compilation.png'

For be compiled and run in your desktop you need to install certains packages and update their system.
In Ubuntu version:

```
sudo apt update; sudo apt upgrade;
sudo apt install iverilog;
```

Once the installation is complete, we will have successfully installed Icarus Verilog on our Ubuntu machine.
After that you need to install GTKWave using ``` sudo apt-get install gtkwave```.

We need to install verilator and packages:

```
sudo apt-get install verilator;
sudo apt-get install git help2man perl python3 make
sudo apt-get install g++  # Alternatively, clang
sudo apt-get install libgz  # Non-Ubuntu (ignore if gives error)
sudo apt-get install libfl2  # Ubuntu only (ignore if gives error)
sudo apt-get install libfl-dev  # Ubuntu only (ignore if gives error)
sudo apt-get install zlibc zlib1g zlib1g-dev  # Ubuntu only (ignore if gives error)
```

to be able to create a configuration script: ```autoconf        # Create ./configure script```.

Endly, to compile and run the code in their desktop you'll need to gives permission to execution via terminal, but you need to go to root file of the project and write down:

```
chmod +x run_verilator.sh;
./run_verilator.sh
```
Hence it will generates a wave file in the root directory of the project and the build directory.
The build directory is used by run_verilator file. This bash file use the testbench file and files build. We implemented a garbage collector to remove the buildd every time that new compilation is running reducing the probability of errors.
This file was reponsible too to execute the build directory running the simulation and the program as at all.

'/home/gabriel-cruz/Área de trabalho/project_photos/compilation_path.png' 

# Observations

Há limitação do sistema, porque não foi pensando em um sistema com mais slavers nem múltiplos masters mandando sinais e dados para os slavers. Embora haja uma codificação dos estados do sistema não há uma lógica na divisão do ready e valid para o endereço e dado do master e slaver. Além disso, não foi possível criar um arquivo com os estados em forma de package em arquivo diferente, pois houve erros na compilação do arquivo tipo .sh.
Outrossim, foi pensado em simular o sistema em um FPGA físico, mas é necessário criar outro testbench exclusivo para rodar o programa no FPGA.


## Initial errors

1. eu tinha colocado a atribuição da memória e acesso da memória do slave dentro do arbiter o que não pode acontecer e é errado. Também tinha codificação de endereço sem sentido para acesso ao slave_reg. Assim, removi as inserções e acesso da memória no arbiter.
2. Eu deveria ter colocado a FSM dentro de um package, pois o package serve para compartilhar (typedef), enumerações, tarefas e funções entre múltiplos módulos ou arquivos de verificação. Afinal, o package evita conflitos de nomes no escopo global e melhora manutenção do projeto. Assim, eu todo arquivo que usa o state_t eu devo chamar no topo importar o nome do pacote.
3. Também eu tive que criar um arquivo separado para colocar o package. Afinal, aprendi que o package não pode estar misturado com o módulo.
4. No arbiter eu tinha instanciado a interface de forma errada como: bus_if inter(clk);
O correto é bus_if inter();
5. Nas interconexões do arbiter eu tinha usado o serv_valid, serv_read, serv_write, serv_addr. O que não faz sentido e é errado.
6. No testbench eu não instanciei as interfaces dentro do módulo do testbench. Esse instanciamento é a criação de interfaces com os nomes dados dentro do testbench.
7. Eu coloquei inicialmente interconnect no testbench. O que não precisou.
8. Eu tinha instanciado o barramento no arbiter. O que não precisou.
9. Eu tinha colocado uma task para o slave, mas isso estar errado, pois o slave só responde a sinal e não chama task. Também apaguei a task da master_write e coloquei apenas o master_read.
10. Possíveis erros no arbiter foi que é melhor declaração explícita, pois em interface as declarações são diferente de sinais regulares, assim, bus_if.master m1 no argumento do módulo é um erro no arbiter devendo especificar o modport dentro do módulo, como bus_if.master m1_if();
11. Eu tive que alterar o arquivo com a FSM para usar include invés de package, pois o Icarus tem limitação com o systemverilog packages.

# Conclusion

This project was sucessful made which was learned about the systemverilog, bash and compilation file to systemverilog in C++. This project was so hard, which was needed a lot of research and failed tentatives, but it was a worth learn that 
ramped up my programming skills. Moreover, we tested a lot of times and recompiled it.

# Reference

https://www.researchgate.net/figure/AXI-lite-interface-hardware-behaviour_fig4_311865597

Made by RAYPCB in medium: https://medium.com/@raypcb/interfacing-with-axi-peripherals-in-rtl-a-comprehensive-guide-3c2284de4d15

Made by Dillon Huff in youtube: https://www.youtube.com/watch?v=1zw1HBsjDH8

Made by Stephen St. Michael: https://www.allaboutcircuits.com/technical-articles/what-are-axi-interconnects-tutorial-master-slave-digital-logic/

Made by AMD: https://docs.amd.com/v/u/en-US/pg161-axi-master-lite
