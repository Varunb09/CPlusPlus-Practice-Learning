// main project program
//link gsm for alcohol and accident.c,lcd command display.c,gps reciever.c
#include<lpc214x.h>
#include"lcd link.h"
#include"gsm.h"
#include"gps reciever.h"

int flag =0;
extern char lat[13], lon[13], time[10];		   //lattitude and longitude externed from gps receiver file


void viberation_isr(void)__irq			  //viberation sensor isr
{
	IOSET0 = 1<<25;						 
	delay(1000);
	IOCLR0 = 1<<25;
	lcd_string("done");
	flag=1;								   // enabling flag 
	EXTINT = 1<<3;
	VICVectAddr = 0;
	
}

int main()
{
	//all initialization
	unsigned int done = 1;					   
	int result = 0;
	IODIR0 = 1<<25;
	GPS_UART0_init();
	GSM_UART1_init();
	lcd();
	PINSEL1 |= 0<<25|1<<24|1<<29|0<<28;			//p0.28 used adc0.1
	AD0CR = (1 << 1| 3 << 8| 1 << 16 | 0<<17 |1 << 21);
	VICIntEnable = 1 << 17;	 
	VICIntSelect = 0 << 17;		 
	VICVectAddr0 = (long)(viberation_isr);	   
	VICVectCntl0 = 1<<5|17;
	EXTMODE = 1 << 3;
	EXTPOLAR = 0 << 3;
	while(1)
	{
	
	
		//alcohol reading
		command(0x80);
		lcd_string("Alcohol val:");
		while(!(AD0DR1 & (done << 31)));
		result = ((AD0DR1 >> 6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
		command(0xc0);
		display(result);
		delay(1000);
		command(0x01);

		//viberation sensor reading		
	
		if(flag == 1)	// cheaking flag for interrupt occured
		{
			command(0x01);
			lcd_string("ACCIDENT OCCURED:");
			read_gps();		  //read_ gps latitude and longitude
			gsm_send_msg("ACCIDENT OCCURED",lat,lon);	 //transmit data of lat and long. to gsm mobile number
			delay(1000);
			flag =0;	   //diable flag
		}

	}	
}
