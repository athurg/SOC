module main(
	input	CLOCK, RESET,
	output	[7:0] P3I,
	output	[7:0] P0O
);
	wire mcu_clock;
	
	pll sys_pll(CLOCK, mcu_clock);
	
	mcu mcu8051(
		.CLOCK(mcu_clock),
		.RESET(RESET),
		.P0I({8{1'b1}}),	.P1I({8{1'b1}}),	.P2I({8{1'b1}}),	.P3I({8{1'b1}}),
		.P0O(P0O),.P3O(P3I)
	);
endmodule
