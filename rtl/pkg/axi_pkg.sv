package axi_pkg;

typedef enum [1:0] {
	ST_IDLE,
	ST_ADDR_PHASE,
	ST_DATA_PHASE
} state_t;

endpackage
