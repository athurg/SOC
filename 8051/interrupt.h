#ifndef INTERRUPT_H
#define INTERRUPT_H

/*
	中断号定义

	中断寄存器地址 = (中断号 * 8) + 3
*/
#define IE0_VECTOR	0	 // 0x03 外部中断0
#define TF0_VECTOR	1	 // 0x0b 定时器0
#define IE1_VECTOR	2	 // 0x13 外部中断1
#define TF1_VECTOR	3	 // 0x1b 定时器1
#define SI0_VECTOR	4	 // 0x23 串口 0
#define INIT_SWITCH	5	 // 0x23 串口 0
#define IE0_trig_VECTOR	0	 // 边沿型外部中断0
#define IE1_trig_VECTOR	2	 // 电平型外部中断0
#define IE0_volt_VECTOR	6	 // 边沿型外部中断1
#define IE1_volt_VECTOR	7	 // 电平型外部中断1

//中断有效值定义
#define	INIT_DISABLE	0	//禁用中断
#define	INIT_ENABLE	1	//普通优先级中断
#define	INIT_HIGHT	3	//高优先级中断

/*	函数声明	*/
void	interrupt_switch(unsigned char interrupt_num, unsigned char value);

#endif
