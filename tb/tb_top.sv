module tb_top;

	logic clk, reset;

	//clock
	always #5 clk = -clk;

	//interface
	bus_if bus(.*);

	// DUTs
	master_reg mast_test
	(
		.clk(clk), .reset(reset), .bus(bus.master_reg)
	);

	interconnect interc_test
	(
		.bus_m (bus.interconnect_m),
		.bus_s (bus.interconnect_s)
	);

	slave_reg slave_test
	(
		.clk(clk), .reset(reset), .bus(bus.slave)
	);

	//reset + stimulus
	initial begin
		clk = 0;
		reset = 0;
		repeat (5) @(posedge clk);
		reset = 1;

		//write
		bus.master_write(8'h04, 32'hDEADBEEF);

		//read
		bus.master_read(8'h04);

		$finish;
	end

endmodule
