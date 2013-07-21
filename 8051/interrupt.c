#include "common.h"
#include "interrupt.h"

void	interrupt_switch(unsigned char interrupt_num, unsigned char value)
{
/*
	系统中断开关
参数：
	interrupt_num:中断编号
		0～4分别代表边沿型外部中断0、定时器0、外部中断1、定时器1、串口；
		5代表中断总开关；
		6、7分别代表电平型外部中断0、电平型外部中断1；
	value:
		对中断总开关而言，0代表关闭、1代表启用；
		对特定中断而言，0代表关闭、1代表普通中断、2代表优先中断；

*/
	switch(interrupt_num){
		case	0://边沿型外部中断0
			EX0=value;		PX0=value>>1;		IT0=1;
			break;
		case	1://定时器0中断
			ET0=value;		ET0=value>>1;
			break;
		case	2://触发型外部中断1
			EX1=value;		PX1=value>>1;		IT1=1;
			break;
		case	3://定时器1中断
			ET1=value;		ET1=value>>1;
			break;
		case	4://串口中断
			ES=value;		ES=value>>1;
			break;
		case	6://电平型外部中断0
			EX0=value;		PX0=value>>1;		IT0=0;
			break;
		case	7://电平型外部中断1
			EX1=value;		PX1=value>>1;		IT1=0;
			break;
		default://中断总开关
			EA=value;
			break;
	}
}

