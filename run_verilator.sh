#!/bin/bash

set -e   # Stop anything if error

TOP=tb_top
BUILD_DIR=build

echo "===================================="
echo " Building SystemVerilog with Verilator"
echo "===================================="

# Clean the build
rm -rf ${BUILD_DIR}
mkdir -p ${BUILD_DIR}

# Verilator generating the file
verilator \
  --cc \
  --exe \
  --build \
  --trace \
  -Wall \
  --assert \
  --x-assign unique \
  --x-initial unique \
  --top-module ${TOP} \
  -Irtl \
  -Irtl/interface \
  -Irtl/pkg \
  rtl/pkg/axi_pkg.sv \
  rtl/interface/bus_if.sv \
  rtl/master_reg.sv \
  rtl/slave_reg.sv \
  rtl/arbiter.sv \
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


#Tip: The -I expects a direectory, not a file
# rtl/**/*.sv \	-> 	#searching in subdirectories inside rtl repository
