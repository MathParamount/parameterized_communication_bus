module assumption_(input logic clk, input logic reset,bus_if.master busa, bus_if.slave busc);

//master

a_as_m: assume property(@(posedge clk)
	$rose(busa.valid) |-> $changed(busa.addr)
);

//assume that write_data and write change simultaneously
b_as_m: assume property(@(posedge clk)
	$changed(busa.write_data) |-> $changed(busa.write)
);

//assume that signals change in positive edge of the clock
c_as_m: assume property(@(posedge clk)
	$changed(busa.valid) || $changed(busa.write) || $changed(busa.addr) || $changed(busa.write_data) |-> $rose(clk)
);

//avoid random reset and clk interactions
d_as_m: assume property(@(posedge clk)
	$changed(reset) |-> $rose(clk)
);

//slaver

a_as_s: assume property(@(posedge clk)
	$changed(busc.addr) |-> $rose(busc.ready)
);

//assume that signals change in positive edge of the clock
b_as_s: assume property(@(posedge clk)
	$changed(busa.ready) || $changed(busa.read_data) |-> $rose(clk)
);


endmodule
