	#include<lpc214x.h>
	#include<string.h>
	#include"GSM.h"	  
	#include"lcd.h"
	
	int main()
	{
		IODIR0 = LED_ALL;
		lcd_init();
		display_string("ACCIDENT OCCURED:");
		GSM_UART1_init();
		gsm_send_msg("ACCIDENT OCCURED");
		while(1);
	}		
