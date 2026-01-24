timeunit 100ns;
timeprecision 100ns;

interface bus_if #(DATA_WIDTH = 32, ADDR_WIDTH = 16);
	
	//Declaration
	logic clk, reset;

	wire [ADDR_WIDTH-1:0] addr;
	wire [DATA_WIDTH-1:0] write_data;
	wire [DATA_WIDTH-1:0] read_data;
	
	logic read,write;

	logic valid,ready;
	//The data direction

	modport master_reg (input read, read_data, output addr, write_data, write, valid, ready);

	modport slave_reg (input addr,write_data,write,valid,ready, output read,read_data);


	//To create stimulus to testbench encapsulation
	task master_write(input logic [ADDR_WIDTH-1:0] addr, input logic [DATA_WIDTH-1:0] data);

		@(posedge clk);
		valid <= 1;
		read <= 0;
		write <= 1;
		
		this.addr <= addr;
	
		write_data <= data;
		
		wait(ready);
		valid <= 0;
	
	endtask

	task master_read(input logic [ADDR_WIDTH-1:0] addr);
		
		@(posedge clk);
		valid <= 1;
		read <= 1;
		write <= 0;

		this.addr <= addr;
		wait(ready);

		$display("The data is: %h", read_data);
		valid <= 0;

	endtask
	
endinterface : bus_if
