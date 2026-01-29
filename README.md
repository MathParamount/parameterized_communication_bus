# Overview

the initial project roadmap is:

bus_if -> arbiter -> bus_controller -> slave_reg


The initial project interface needs 11 input and 8 output:

the structure of final project was:

common_pkg -> master_reg -> bus_if -> arbiter -> slave_reg

-------------------------

Inicialmente acabei fazendo 11 entradas e 8 saídas, mas preferi simplificar o mais possível para facilitar a criação da fsm e o debug depois. O objetivo não é criar o mais legitimo possível, mas algo mais simples para aprendizagem.

Na parte do master_reg eu inicialmente pensei em criar uma lógica com always_ff em que é sensível ao clk do master para inserir os dados internamente recebidos do barramento e verificar a esbilização dos sinais de ready e valid.
Contudo, eu percebi que o projeto ficaria mais confuso e tem furos na lógica do código.
Portanto, eu decidi fazer uma fsm com enum de todos os estados possíveis e master_reg decidir a lógica baseado no estado.
A estrtura de estados do master foi: no caso do IDLE foi a criação de dados zero das variáveis do master e verificação do sinal prontidão do servo para trocar de estado. O caminho dos estados foi pensado para seguir: IDLE -> ADDR_PHASE -> DATA_PHASE. 
No estado de endereço ele verifica se é leitura ou escrita. Se for leitura(read) ele envia ao barramento o sinal de leitura do endereço. Se for escrita(write) ele envia sinal de escrita de dado ao barramento com a inserção de dado ao endereço.

-------------------------

No arbiter: eu inicialmente pensei em fazer um multiplexador na saída do master para o um decodificador que mandava para o endereço específico do slaver e seguiria a mesma lógica do datapath do slaver para o master. Contudo, eu acabei percebendo que como o projeto só tem 1 master e 1 slave não há necessidade de uma lógica aprofundada nas conexões do barramento central. Afinal, o master manda em todo o sistema. Então, bastou eu fazer a interconexão dos sinais e codificar os endereços.

-------------------------
Tentativa de compilação que não deu certo:

 iverilog -g2012 -o sim.out \ rtl/bus_inf.sv \ rtl/master_reg.sv \ rtl/arbiter.sv \ rtl/slave_reg.sv \ tb/tb_top.sv
 
2 tentativa de Compilação que não deu certo:
 iverilog -g2012 \
  -I rtl \
  rtl/*.sv \
  tb/tb_top.sv \
  -o sim.out

vvp sim.out

3 tentativa de compilação que não deu certo:
iverilog -g2012 -I rtl \
  rtl/bus_if.sv \
  rtl/master_reg.sv \
  rtl/arbiter.sv \
  rtl/slave_reg.sv \
  tb/tb_top.sv \
  -o sim.out

4 tentativas de compilação que não deu certo:
iverilog -g2012 \
  rtl/common_pkg.sv \
  rtl/bus_if.sv \
  rtl/master_reg.sv \
  rtl/slave_reg.sv \
  rtl/arbiter.sv \
  tb/tb_top.sv \
  -s tb_top \
  -o sim.out

vvp sim.out

5 tentativa de compilação que não deu certo:
chmod +x run.sh
./run.sh

6 tentativa de compilação:
cat > run_verilator.sh << 'EOF'
#!/bin/bash
BUILD_DIR="/tmp/verilator_build_$$"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"
cp -rL "/home/gabriel-cruz/Área de trabalho/projetos/parameterized_communication_bus/rtl" .
cp -rL "/home/gabriel-cruz/Área de trabalho/projetos/parameterized_communication_bus/tb" .
cp "/home/gabriel-cruz/Área de trabalho/projetos/parameterized_communication_bus/sim_main.cpp" .
verilator -Wall --cc --build rtl/*.sv tb/*.sv --top-module tb_top --exe sim_main.cpp
./obj_dir/Vtb_top
EOF

chmod +x run_verilator.sh

depois: ./run_verilator.sh

7 tentativa:

# Execute este comando direto no terminal:
cd /tmp && \
mkdir -p test_v && cd test_v && \
cp -rL "/home/gabriel-cruz/Área de trabalho/projetos/parameterized_communication_bus/rtl" . && \
cp -rL "/home/gabriel-cruz/Área de trabalho/projetos/parameterized_communication_bus/tb" . && \
cat > sim_main.cpp << 'EOF'
#include "Vtb_top.h"
#include "verilated.h"
int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vtb_top *top = new Vtb_top;
    for (int i = 0; i < 10000; i++) top->eval();
    delete top;
    return 0;
}
EOF
verilator -Wall --cc --build rtl/*.sv tb/*.sv --top-module tb_top --exe sim_main.cpp && \
echo "Compilation successful!" && \
./obj_dir/Vtb_top

8 tentativa:

./run_verilator.sh

------------------------

Nas compilações que eu fiz do projeto identifiquei os seguintes erros inicialmente cometidos , mas resolvidos:
1) eu tinha colocado a atribuição da memória e acesso da memória do slave dentro do arbiter o que não pode acontecer e é errado. Também tinha codificação de endereço sem sentido para acesso ao slave_reg. Assim, removi as inserções e acesso da memória no arbiter. 
2) Eu deveria ter colocado a FSM dentro de um package, pois o package serve para compartilhar (typedef), enumerações, tarefas e funções entre múltiplos módulos ou arquivos de verificação. Afinal, o package evita conflitos de nomes no escopo global e melhora manutenção do projeto. Assim, eu todo arquivo que usa o state_t eu devo chamar no topo importar o nome do pacote.
3) Também eu tive que criar um arquivo separado para colocar o package. Afinal, aprendi que o package não pode estar misturado com o módulo.
4) No arbiter eu tinha instanciado a interface de forma errada como: bus_if inter(clk);
O correto é bus_if inter();
5)Nas interconexões do arbiter eu tinha usado o serv_valid, serv_read, serv_write, serv_addr. O que não faz sentido e é errado.
6)No testbench eu não instanciei as interfaces dentro do módulo do testbench. Esse instanciamento é a criação de interfaces com os nomes dados dentro do testbench.
7) Eu coloquei inicialmente interconnect no testbench. O que não precisou.
8) Eu tinha instanciado o barramento no arbiter. O que não precisou.
9) Eu tinha colocado uma task para o slave, mas isso estar errado, pois o slave só responde a sinal e não chama task. Também apaguei a task da master_write e coloquei apenas o master_read.
10) Possíveis erros no arbiter foi que é melhor declaração explícita, pois em interface as declarações são diferente de sinais regulares, assim, bus_if.master m1 no argumento do módulo é um erro no arbiter devendo especificar o modport dentro do módulo, como bus_if.master m1_if();
11) Eu tive que alterar o arquivo com a FSM para usar include invés de package, pois o Icarus tem limitação com o systemverilog packages.
12) I created a bash file to faciliate the compilation in the root project. The reason is that the path has space and it gives a lot of errors.

---------------------------------

Aprendi técnicas de debug de código em systemverilog:
1) Verifique o arquivo de package em barramento e depois coloque echo $? para ver se retorna 0 que indica que os dois arquivos estão certos.
iverilog -g2012 \
  rtl/common_pkg.sv \
  rtl/bus_if.sv \
  -o sim.out

echo $?  # Verifique se retorna 0 (sucesso)

2) Adicione um módulo por vez para ver se é um arquivo ou outro:
iverilog -g2012 \
  rtl/common_pkg.sv \
  rtl/bus_if.sv \
  rtl/master_reg.sv \
  -o sim.out

--------------------------------------
Observações:
Este projeto foi implementado usando systemverilog, em que o objetivo foi implementar um projeto útil com as habilidades aprendidas no curso da Cadence sobre systemverilog. 
Foi pensado em uma comunicação simples em que há somente 1 master e 1 slave, assim, reduzindo lógica complexa de redirecionamento de dados no barramento.
Este projeto foi simulado no GTKWave gerado pelas formas de ondas do arquivo em C++ na raiz do projeto chamado sim_main em que ele faz todo o teste do sistema ligando e desativando o reset, clock, contando tempo e gerando as ondas.
Há limitação do sistema, porque não foi pensando em um sistema com mais slavers nem múltiplos masters mandando sinais e dados para os slavers. Embora haja uma codificação dos estados do sistema não há uma lógica na divisão do ready e valid para o endereço e dado do master e slaver. Além disso, não foi possível criar um arquivo com os estados em forma de package em arquivo diferente, pois houve erros na compilação do arquivo tipo .sh.
Outrossim, foi pensado em simular o sistema em um FPGA físico, mas é necessário criar outro testbench exclusivo para rodar o programa no FPGA.

O arquivo em bash para execusão do projeto precisa dos seguintes comandos para funcionar:

chmod +x run_verilator.sh
Logo em seguida deve ser feito:
./run_verilator.sh

Assim vai ser compilado e gerado o arquivo de forma de onda na pasta root do projeto, chamado: wave.vcd.

# Architecture

# Observations

# Conclusion
