	#include<lpc214x.h>	
	#include<string.h> 	
	#include"GSM.h"
	#include"lcd link.h" 
	#include"gps reciever.h"
	
	char *AT = "AT\r\n"	;
	char *AT_CMGF = "AT+CMGF=1\r\n";
	char *AT_CMGS="AT+CMGS=\"+919783905067\"\r\n";
	char *OK = "OK";
	char temp[15];
	
	void GSM_UART1_init(void)				//uart initialization
	{
		PINSEL0 = (PINSEL0 & ~(0XF << 16)) |UART1_GSM_ALL;	// FOR UART0 AND UART1
		U1LCR = 0X80;
		U1DLL = 97;
		U1LCR = 0X03;
	}
	void GPS_UART0_init(void)
	{
		PINSEL0 = (PINSEL0 & ~(0XF << 0)) |UART0_GSM_ALL;	// FOR UART0 AND UART1
		U0LCR = 0X80;
		U0DLL = 97;
		U0LCR = 0X03;
	}
			
/*------------------------------------------------------------------------------------------------
FUNCTION NAME : SENDING MESSAGE THROUGH GSM --> UART1
-------------------------------------------------------------------------------------------------*/

	void string_uart_trns_gsm(char *str)		 //uart transmitter
	{
		while(*str)
		{
			while(!(U1LSR & (1 << 5)));
			U1THR = *str;
			str++;
		}
	}
//	void string_uart0_trns_gsm(char *str)
//	{
//		while(*str)
//		{
//			while(!(U0LSR & (1 << 5)));
//			U0THR = *str;
//			str++;
//		}
//	}
	void put_char_gsm(char c)	//put charater to gsm
	{
		while(!(U1LSR & (1 << 5)));
		U1THR = c;
	}

	char uart_recv_gsm(void)		  //uart reciever
	{
		while(!(U1LSR & (1 << 0)));		
		return(U1RBR);
	}
	char uart0_recv_gps(void)
	{
		while(!(U0LSR & (1 << 0)));		
		return(U0RBR);
	} 


	void gsm_response(char ca,int no)		//gsm terminal responce monitor
	{
		char c;	
		int i = 0; 
		do
		{
			i = 0;
			c=uart_recv_gsm();
			temp[i] = c;
		}while((c != ca));
		
		do
		{	
			i++;
			c=uart_recv_gsm();
			temp[i] = c;
		}while(i != no);

	
	}


void gsm_send_msg(char *str1,char *str2,char *str3)		 //send msg commands to gsm
		{	
		

			do
			{
				delay(5000);
				string_uart_trns_gsm(AT);
				gsm_response('O',1);
				temp[2] = '\0';
			
			}while(strcmp(temp,OK) != 0);
				
			delay(5000);
			string_uart_trns_gsm(AT_CMGF);	   //transmit initialization command to gsm
			delay(6000);
			string_uart_trns_gsm(AT_CMGS);
		   	delay(5000);
		   	string_uart_trns_gsm(str1);
			put_char_gsm(0x0a);			   //wait for another message
			delay(3000);
			string_uart_trns_gsm(str2);
			put_char_gsm(0x0a);				  //put character(str) to gsm message
			delay(3000);
			string_uart_trns_gsm(str3);
			put_char_gsm(0x1a);			  //terminate msg transmittion
		  	delay(3000);

		}
		
