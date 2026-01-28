module tb_top(input logic clk, input logic reset);
    //declare interfaces
    bus_if bus_master();
    bus_if bus_slave();
    
    //instantiate DUT
    master_reg u_master(
        .clk(clk),
        .reset(reset),
        .busa(bus_master)
    );
   
	 arbiter u_arbiter(
	 	.m(bus_master),
		.s(bus_slave)
	 );

    slave_reg u_slave(
        .clk(clk),
        .reset(reset),
        .busc(bus_slave)
    );

    
endmodule
