module fpga_tb_top(input logic clk, input logic reset_n, input logic led);

	logic reset;
	assign reset = ~reset_n;

	bus_if master_ug();
	bus_if slaver_ug();
	
	#Defining clock
	#10 clk = ~clk;

	master_ug u_master(.clk(clk), .reset(reset), .busa(master_ug));
	
	arbiter u_arbiter(.busa(master_ug), .bus(slaver_ug));

	slaver_ug u_slaver(.clk(clk), .reset(reset), .bus(slaver_ug));
	
	//first test
	always_ff @(posedge clk)
	begin
		if(!reset) begin
			led <= 1'b0;
		end
		else begin
			led = ~led;
		end
	end
	
	//Second test
	always_ff @(posedge clk or negedge reset) begin
		
		if(!reset) begin
			state <= IDLE;
			busal.valid <= 0;

		end 
		else begin
		
			case(state)
			IDLE: begin
				busa.valid <= 1;
				state <= ADDR_PHASE;
			end

			ADDR_PHASE: begin
				busa.addr <= 4'b1011;
				state <= DATA_PHASE;
			end
			
			DATA_PHASE: begin
				busa.write_data <= 5'b11010;
				state <= IDLE;
			end
			
			endcase
		end
	end
	
endmodule
