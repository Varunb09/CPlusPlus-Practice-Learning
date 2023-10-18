
#include<lpc214x.h>
#include"prototype.h"

unsigned char gps_data[] = "$GPGGA", lat[13], lon[13], time[10];



int main()
{
   	uart_init();
	lcd_int();

	lcdstring("GPS TEST CODE");
	lcd_cmd(0x01);
	while(1)
	{
		lcd_cmd(0x01);
		read_gps();
		delay(100);
	}
}

void read_gps()
{
	unsigned char i ,j ,k ,rec;
	first:
	for(i=0;(uart_recv() == gps_data[i]) && i<6 ;i++);	// getting lat,long,time values from gps
		
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
		 		rec = uart_recv();
		 		time[i]=rec;
		 	}
			else if(i>10&&i<=22) 
			{
				rec = uart_recv();
				lat[j]=rec;
				j++;
			} 
			else if(i>22)
			{
				rec = uart_recv();
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
	lcdstring("Lattitude:");
	lcd_cmd(0xC0);
	lcdstring(lat);
	delay(100);
	lcd_cmd(0x01);
	lcdstring("Longitude:");
	lcd_cmd(0xC0);
	lcdstring(lon);
} 