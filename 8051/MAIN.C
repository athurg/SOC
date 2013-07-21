#include "common.h"
#include "interrupt.h"

uchar counter=0;
void main()
{
	interrupt_switch(IE0_volt_VECTOR,INIT_ENABLE);
	interrupt_switch(INIT_SWITCH,INIT_ENABLE);
	while(1){
		P1=counter;
	}
}

void INIT0_ISR(void) __interrupt IE0_VECTOR
{
    //外部中断0中断处理程序
	counter++;
}

