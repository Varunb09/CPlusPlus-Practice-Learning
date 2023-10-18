			
//	#include<lpc214x.h>
			
#include"prototypes.h"

extern int second;
extern int heart_beat;

int main()
{
	lcd_init(); // initialisation of lcd
	external_interrupt_init(); // for initialising the external interrupt
	timer_init();// initialising timer 
	lcdstring("HeartBeat Sensor");
	lcd_cmd(0x01);
	while(1)
	{
	
		if(second >= 1)
		{
		//	display(heart_beat); // displaying value of heart beat in lcd
			//cmd(0x01);
			CONVERT_ADC(heart_beat*4);
			heart_beat = 0;
			second = 0;
			delay(100);
			lcd_cmd(0x01);
		}
		
	}	 
}

