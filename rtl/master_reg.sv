`ifndef MASTER_REG_SV
`define MASTER_REG_SV

module master_reg(
    input logic clk, 
    input logic reset,
    bus_if.master busa
);
    
    //states
    localparam [1:0] ST_IDLE = 2'b00;
    localparam [1:0] ST_ADDR_PHASE = 2'b01;
    localparam [1:0] ST_DATA_PHASE = 2'b10;
    
    reg [1:0] state;
    reg [1:0] next_state;
    
    //inner registers
    logic write_r, valid_r, read_r;
    logic [15:0] addr_r;
    logic [31:0] write_data_r;
    
    //sequential logic
    always_ff @(posedge clk or negedge reset) begin
        if (!reset) begin
            state <= ST_IDLE;
        end
        else begin
            state <= next_state;
        end
    end
    
    //combinational logic
    always_comb begin
        // Default values
        next_state = state;
        valid_r = 0;
        read_r = 0;
        write_r = 0;
        addr_r = '0;
        write_data_r = '0;
        
        case (state)
            ST_IDLE: begin
                addr_r = 16'h0010;
                write_data_r = 32'hDEADBEEF;
                write_r = 1'b1;
                valid_r = 1'b1;
                
                if (busa.ready) begin
                    next_state = ST_ADDR_PHASE;
                end
            end
            
            ST_ADDR_PHASE: begin
                valid_r = 1'b1;
                
                if (busa.ready) begin
                    next_state = ST_DATA_PHASE;
                end
            end
            
            ST_DATA_PHASE: begin
                valid_r = 1'b1;
                
                if (busa.ready) begin
                    next_state = ST_IDLE;
                end
            end
            
            default: begin
                next_state = ST_IDLE;
            end
        endcase
    end
    
    //connecting with interface
    assign busa.valid      = valid_r;
    assign busa.read       = read_r;
    assign busa.write      = write_r;
    assign busa.addr       = addr_r;
    assign busa.write_data = write_data_r;
    
endmodule

`endif
