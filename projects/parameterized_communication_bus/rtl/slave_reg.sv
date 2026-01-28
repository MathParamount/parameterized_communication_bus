`ifndef SLAVE_REG_SV
`define SLAVE_REG_SV

module slave_reg(
    input logic clk,
    input logic reset, 
    bus_if.slave busc
);
    
    localparam [1:0] ST_IDLE = 2'b00;
    localparam [1:0] ST_ADDR_PHASE = 2'b01;
    localparam [1:0] ST_DATA_PHASE = 2'b10;
    
    reg [1:0] state;
    reg [1:0] next_state;
    
    //inner registers
    logic ready_r, ready_next;
    logic [31:0] read_data_r, read_data_next;
	  
    assign busc.ready     = ready_r;
    assign busc.read_data = read_data_r;

    //sequential logic
    always_ff @(posedge clk or negedge reset) begin
        if (!reset) begin
            state <= ST_IDLE;
            ready_r <= 1'b0;
            read_data_r <= 32'b0;
        end
        else begin
            state <= next_state;
            ready_r <= ready_next;
            read_data_r <= read_data_next;
    	  end
	 end
    
    //combinational logic
    always_comb begin
        // Default values
        next_state = state;
        ready_next = 1'b0;
        read_data_next = read_data_r;
        
        case (state)
            ST_IDLE: begin
                if (busc.valid) begin
                    next_state = ST_ADDR_PHASE;
                end
            end
            
            ST_ADDR_PHASE: begin
                ready_next = 1'b1;
                
                if (busc.read) begin
                	read_data_next = 32'hCAFEBABE;  	
             	end
             	else begin
             	 	read_data_next = read_data_r;
             	end
             	
             	next_state = ST_DATA_PHASE;
            end
            
            ST_DATA_PHASE: begin
            	ready_next = 1'b0;
                next_state = ST_IDLE;
            end
            
            default: begin
                next_state = ST_IDLE;
            end
        endcase
    end
    
endmodule

`endif
