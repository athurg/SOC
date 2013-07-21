/*
	8051MCU模块
说明：
	输入时钟不小于36MHz；
	ROM的hex编程文件相对于本目录的路径为：../debug/soc.hex；
	MT、NO、POE[0]、POE[2]、POE[3]、POE[4]分别绑定到21、22、25、26、24、28口以解锁；

待完成：
	完成双向口设置；
	测试串口、中断；
*/
module mcu(
	input	CLOCK, RESET,
	input	[7:0] P0I, P1I, P2I, P3I,
	output	[7:0] P0O, P1O, P2O, P3O
);
	wire	[7:0] RAM_ADDR, RAM_DB_IN, RAM_DB_OUT;
	wire	RAM_WEN;
	wire	[15:0] ROM_ADDR;
	wire	[7:0] ROM_DB;

	CPU8051V1	core(
		.RESET(RESET),.X1(CLOCK), .X2(CLOCK),
		.NEA(1'b1), .NESFR(1'b1), .ALEI(1'b1), .PSEI(1'b1),
		.P0I(P0I), .P1I(P1I), .P2I(P2I), .P3I(P3I),
		.P0O(P0O), .P1O(P1O), .P2O(P2O), .P3O(P3O),
		.RAMdaO(RAM_DB_OUT), .RAMadr(RAM_ADDR), .RAMdaI(RAM_DB_IN), .FWE(RAM_WEN),
		.ROMdaO(ROM_DB), .ROMadr(ROM_ADDR)
	);

	/* 256字节的RAM */
	ram8051	ram(
		.inclock(CLOCK),
		.wren(~RAM_WEN),
		.address(RAM_ADDR),
		.data(RAM_DB_IN),
		.q(RAM_DB_OUT)
	);

	/* 8K字节的RAM */
	rom8051	rom(
		.inclock(CLOCK),
		.address(ROM_ADDR[12:0]),
		.q(ROM_DB)
	);
endmodule
