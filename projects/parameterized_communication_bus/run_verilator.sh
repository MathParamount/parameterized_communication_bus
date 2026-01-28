#!/bin/bash

set -e   # Para o script se algo der erro

TOP=tb_top
BUILD_DIR=build

echo "===================================="
echo " Building SystemVerilog with Verilator"
echo "===================================="

# Limpa build anterior
rm -rf ${BUILD_DIR}
mkdir -p ${BUILD_DIR}

# Etapa 1: Verilator gera C++
verilator \
  --cc \
  --exe \
  --build \
  --trace \
  -Wall \
  --top-module ${TOP} \
  -Irtl \
  rtl/*.sv \
  tb/tb_top.sv \
  sim_main.cpp \
  -o sim_${TOP} \
  --Mdir ${BUILD_DIR}

echo "===================================="
echo " Running simulation"
echo "===================================="

# Executa o binário gerado
./${BUILD_DIR}/sim_${TOP}

echo "===================================="
echo " Simulation finished successfully"
echo "===================================="

