#include<lpc214x.h>
#include "keypad link lcd.h"
#define ROW (1<<17|1<<18|1<<19|1<<20)
#define COL (1<<21|1<<22|1<<23|1<<24)

long rowdefine(void);
int main()
{
	long z = 0,y = 0;
	lcd();
	data("TESTING BOARD :)");
	delay(5000);
	label1:while(1)
	{
		IODIR1 = ROW;					  
		//initialize row with zero
		IOCLR1 = ROW;	
		command(0x01);
		z = (IOPIN1 & COL);		   //Z=0x1e00000   cheaking whether any switch is pressed or not
		if(z != 0x1e00000)
		{
			if(z == 0x1c00000)				//gives col 1
			{
				y = rowdefine();			//finding row adress and printing
				goto label;
				
			}
			if(z == 0x1a00000)				//gives col 2
			{
				y = rowdefine();
				goto label;
				
			}
			if(z == 0x1600000)				// gives col 3
			{
				y = rowdefine();
				goto label;
				
			}	
			if(z == 0x0e00000)				//gives col 4
			{
				y = rowdefine();
				goto label;
			}
		}
	}
		label:while(1)
		{
		//cheaking pheripheral
		if(z == 0x1c00000 && y == 0x1c0000)
		{
		//led glow
			IODIR1 = 0xff<<17;
			IOSET1 = 0xff<<17;
			delay(5000);
			IOCLR1 = 0xff<<17;
			data("led success");
			goto label1;
		}
		if(z == 0x1c00000 && y == 0x1a0000)
		{
		//buzzer prog
			IOSET0 = 1<<25;
			delay(5000);
			IOCLR0 = 1<<25;
			data("buzzer success");
			goto label1;
		}
		if(z == 0x1c00000 && y == 0x160000)
		{
			//program using timer 1
			T1TCR = 1<<0;
			T1MR0 = 1000000;
			T1PR = 14;
			T1MCR = 0x3<<0;
			while(!(T1IR & 1<<0));
			command(0x80);
			command(0x0c);
			data("timer 1 OK...");
			T1IR = 1<<0;
			goto label1;
		}
		if(z == 0x1c00000 && y == 0x0e0000)
		{
			//program using timer 0
			T0TCR = 1<<0;
			T0MR0 = 1000000;
			T0PR = 14;
			T0MCR = 0x3<<0;
			while(!(T0IR & 1<<0));
			command(0x80);
			command(0x0c);
			data("timer 0 OK...");
			T0IR = 1<<0;
			goto label1;
		}
		if(z == 0x1a00000 && y == 0x1c0000)
		{
		//rtc
			CCR = 1<<0|1<<4;			 //enable rtc and source selectrtc
			CIIR = 1<<1;			   //increment counter at every minute for incrementing every second use 1<<0	
			while(!(ILR & 1<<0));			   //cheak flag for interrupt location register
			command(0x80);
			command(0x0c);
			data("RTC OK...");
			ILR = 1<<0;
			goto label1;		
		}
		if(z == 0x0e00000 && y == 0x0e0000)
		{	//watch dog timer
			WDMOD = 1<<0|1<<1;
			WDTC = 0xffffffff;
			WDFEED=0xAA;
			WDFEED = 0x55;
			while(1)
			{	if(!(WDTC = 0))
				{
				command(0x80);
				command(0x0c);
				data("reset successfully");
				break;
				}
			}
			goto label1;
		}
		}	
}

long rowdefine()
{
	int y =0;
		IODIR1 = COL;
		IOCLR1 = COL;			//initializing collumm as zero
		y = (IOPIN1 & ROW);		   //y=0x1e0000	 check wheather row is pressed or not
			if(y != 0x1e0000)
			{
				if(y == 0x1c0000)		  //gives row 1
				{
					return y;	
				}
				if(y == 0x1a0000)		   //gives row 2
				{
					return y;
				}
				if(y == 0x160000)		   //gives row 3
				{
					return y;
				}
				if(y == 0x0e0000)			//gives row 4
				{
					return y;
				}
			}
			return 0;
}
