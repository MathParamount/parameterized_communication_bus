`include "bus_if.sv"

timeunit 100ns;
timeprecision 100ns;

typedef enum logic []


module master_reg
(
	input logic clk, bus_if busa 
);

	begin
		always_ff @(posedge master_clk) begin
			
			//data input write
			busa.write_data <= busa.read_data;
			busa.write_addr <= busa.read_addr
			
			busa.write_addr_valid <= 1;
			busa.write_addr <= 1;

			//stability
			if(busa.write_addr_ready && busa.write_ready)
			{
				busa.write_addr_valid <= 0; busa.write_addr <= 0;
			}
			
			//read
			if(busa.read_addr_valid && !busa.read_addr_ready)
			{
			}

	end

endmodule
