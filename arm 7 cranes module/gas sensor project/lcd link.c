#include<lpc214x.h>
#define EN 1<<10
#define RS 1<<13
#define RW 1<<12

void delay(int c)
{
	int i,j;
	for(i=0;i<c;i++)
	for(j=0;j<1000;j++);
}

void command(int c)
{
	
	//send command
	IOPIN0 = c<<15;
	IOCLR0 = RS;				//RS = 0
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(10);
	IOCLR0 = EN;
	delay(10);
}
void data(char c )
{
	IOPIN0=c<<15;
	IOSET0 = RS;		//RS = 1
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(10);
	IOCLR0 = EN;
	delay(10);
}

void data1(char c[] )
{
	//send data
	int i = 0; 
	for(i = 0;c[i]!='\0';i++)
	{
//	IOPIN0 = c[i]<<15;
	IOPIN0=c[i]<<15;
	IOSET0 = RS;		//RS = 1
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(500);
	IOCLR0 = EN;
	}
}

void lcd()
{
 	 IODIR0 |= (0xff<<15|EN|RW|RS);
	 command(0x38);
	 command(0x0e);
	 command(0x01);
	 command(0x80);
}
void lcd_string(char *str)
{
	while(*str)
	{
		data(*str++);
	}
	delay(100);
}

void display(int c)
{
	if(c)
	{
		display(c/10);
		data((c%10)+0x30); 
	}	
}



