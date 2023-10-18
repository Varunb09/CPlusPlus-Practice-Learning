//#include<LPC21XX.h>
#include"prototypes.h"

	void lcd_init()
	{
		IODIR1 |= (RS | EN);	 //Register select | Enable 
		IODIR0 |= (0xF << 12);	 //	pin  12 13 14 15 data pins port 0
		lcd_cmd(0x02);	//power on reset
		lcd_cmd(0X28);	 //4 bit mode
		lcd_cmd(0X06);  // increment the curser
		lcd_cmd(0X0E);	 //display on,curser blink
		lcd_cmd(0X01);	//clears the display
		lcd_cmd(0X80);	  //1st line
	}


	void lcd_cmd(unsigned char command)
	{
		unsigned int com;		   //32 BIT
		
		IOCLR1 |= (RS | EN); //clearing Rs = 0 and En = 0
		com = (command & 0xf0);		   //8 bit	
		com = com << 8;				   // shifting from 4 5 6 7 to 12 13 14 15 place(shifting by 8)
		
		IOSET0 |= com;	
		IOCLR0 |= ~com;				   //copy command to port pin
       
	   	IOCLR1 |= (RS | EN);
		IOSET1 |= EN;		  // en=1
		delay(40);
		IOCLR1 |= EN;		  //en = 0
					   
		com = (command & 0x0f);
		com = com << 12;			 //shifting from 0 1 2 3 to  12 13 14 15 place(shifting by 12)
	
		IOSET0 |= com;
		IOCLR0 |= ~com;
    
		IOCLR1 |= (RS | EN);
		IOSET1 |= EN;
		delay(40);
		IOCLR1 |= EN;
	}
	                                           
	void lcd_data(unsigned char data1)
	{
		unsigned int dat;
		
		IOCLR1 |= (RS | EN);		 //clearing rs = 0 and en = 0
		dat = (data1 & 0xf0);
		dat = dat << 8;
	
		IOCLR0 |= (0xF << 12);
		IOSET0 |= dat;
		IOCLR0 |= ~dat;				  //copy data to port pin
		delay(40);
		IOCLR1 |= (RS | EN);
		IOSET1 |= (RS | EN);	   //rs=1 and en=1
		delay(50);

		IOCLR1 |= EN;		  //en = 0

	
		IOCLR1 |= (RS | EN);		  //clear rs =0 and en =0
		dat = (data1 & 0x0f);
		dat = dat << 12;
	
		IOCLR0 |=(0xF << 12);
		IOSET0 |= dat;
		IOCLR0 |= ~dat;
		
		delay(40);
		IOCLR1 |= (RS | EN);
		IOSET1 |= (RS | EN);
		delay(50);
		IOCLR1 |= EN;
	}


	void delay(unsigned int it)
	{
		unsigned int i,j;
		for(i = 0; i < it; i++)
		for(j = 0; j < 5000; j++);
	}

	void Clr_Lcd()
	{
		lcd_cmd(0x01);
		lcd_cmd(0x80);
	}

void lcdstring(unsigned char *p)
{

	while(*p)
	{
		lcd_data(*p);
		p++;
	}
	delay(60);
}


void display(long int n)
		{
				if(n)
					{
						display(n/10);
						lcd_data((n%10) + 0x30);
					}
		}
	 
