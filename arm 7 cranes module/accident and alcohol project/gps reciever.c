#include<lpc214x.h>
#include "lcd link.h"
#include"gsm.h"
void read_gps(void);

unsigned char gps_data[] = "$GPGGA"; 
 char lat[13], lon[13], time[10];



//void gps_reciever()
//{
//   	GPS_UART0_init();
//	lcd();
//	command(0x01);
//	lcd_string("GPS TEST CODE");
//	command(0x01);
//		command(0x01);
//		read_gps();
//		delay(100);
//}

void read_gps(void)
{
	unsigned char i ,j ,k ,rec;
	first:
	for(i=0;(uart0_recv_gps() == gps_data[i]) && i<6 ;i++);	// getting lat,long,time values from gps
		
	if(i<6)
	{
		goto first;
	}
	else
	{
		i=0;j=0;k=0;
		while(i<=34)
		{
			if(i<=10)
			{
		 		rec = uart0_recv_gps();
		 		time[i]=rec;
		 	}
			else if(i>10&&i<=22) 
			{
				rec = uart0_recv_gps();
				lat[j]=rec;
				j++;
			} 
			else if(i>22)
			{
				rec = uart0_recv_gps();
				lon[k] = rec;
				k++;
			}
				i++;
		}	 
		i=0;
	}
		
	//time[i]='\0';				
  	lat[j] ='\0';
	lon[k] ='\0';
	lcd_string("Lattitude:");
	command(0xC0);
	lcd_string(lat);
	delay(100);
	command(0x01);
	lcd_string("Longitude:");
	command(0xC0);
	lcd_string(lon);
} 

