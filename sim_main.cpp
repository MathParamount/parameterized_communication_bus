#include "Vtb_top.h"
#include "verilated.h"
#include <iostream>

#include "verilated_vcd_c.h"		//tracing to generate wave_form

int main(int argc, char **argv) {
   Verilated::commandArgs(argc, argv);
    
	Verilated::traceEverOn(true);

   Vtb_top *top = new Vtb_top;

	VerilatedVcdC* tfp = new VerilatedVcdC;	//wave_form pointer
	top->trace(tfp,99);
	tfp->open("wave.vcd");		//file name
    
   std::cout << "Starting simulation..." << std::endl;
    
	top->clk = 0;
	top->reset = 0;
	top->eval();

    // applying reset for some cycles
    for (int i = 0; i < 5; i++) {
        top->clk = !top->clk;
		  top->eval();
    }
    
    top->reset = 1;

	 for(int time = 0; time < 1000; time++)
	 {
		 top ->clk = !top->clk;
		 top->eval();
		 
		 tfp->dump(time*10);

		 if(time %100 == 0)
		 {
			std::cout << "time step: " << time << std::endl;
		 }
    }
	
	 tfp->close();
	 delete tfp;

    delete top;
    std::cout << "Simulation finished!" << std::endl;
    return 0;
}
