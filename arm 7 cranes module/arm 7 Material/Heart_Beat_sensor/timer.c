
#include<string.h>
#include"prototypes.h"

int second = 0;
extern long int heart_beat;

void timer_init(void)
{
	VICVectAddr2 = (long)timer_isr;
	VICVectCntl2 = (1 << 5) | 4;
	VICIntSelect &= ~(1 << 4);
	T0IR = 0X01;
	VICVectAddr = 0;
	VICIntEnable |= (1 << 4);
//	T0PR = 0;
	T0PC = 0;
//	T0MR0 = 1000000;
	T0MR0 = 15000000;
//	T0PR = 224;
	T0PR = 14;
	T0MCR = 0X3;
	T0TCR = 0X01;
}
	  
void timer_isr(void)__irq
{
		second++; // 
//	CONVERT_ADC(heart_beat); // displaying value of heart beat in lcd
 	T0IR = 0X01;
 	VICVectAddr = 0;
}
