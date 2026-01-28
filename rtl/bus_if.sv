interface bus_if;
	
	//Declaration
	logic [15:0] addr;
	logic [31:0] write_data;
	logic [31:0] read_data;
	
	logic read;
	logic write;

	logic valid;
	logic ready;

	//The data direction
	modport master (output valid,output read,output  write, output addr, output write_data, input ready, input read_data);

	modport slave (input  valid, input  read, input  write, input  addr, input  write_data,output ready,output read_data);

	/*
	//To create stimulus to testbench encapsulation
	task automatic master_read(input logic [15:0] addr_in, output logic [31:0] data_out);
		
		@(posedge clk);
		addr = addr_in;
		valid = 1'b1;
		read = 1'b1;
		write = 1'b0;

		wait(ready);
		
		data_out = read_data;
		valid = 1'b0;	
		read = 1'b0;

		$display("The master read: addr = %h data = %h", addr_in, data_out);

	endtask
*/

endinterface
