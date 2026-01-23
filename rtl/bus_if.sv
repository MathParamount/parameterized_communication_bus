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

endinterface : bus_if
