`include "bus_if.sv"

timeunit 100ns;
timeprecision 100ns;

module master_reg
(
   input logic clk, bus_inf.slave_reg busc, bus_if.master_reg busa
);

   logic [32:0] mem [15:0];
   
   always_ff @(posedge clk or negedge reset)
   begin
   	if(!reset)  begin
   	busc.mem[addr] <= 0;
   	read_data <= 0;
   	end
   	
   	else if(busa.valid && busa.ready)
   	begin
   		if(busa.write)
   			busc.mem[addr] <= write_data;
   	
   		else if(busa.read)
   			read_data <= busc.mem[addr];
   	end
    end

endmodule
