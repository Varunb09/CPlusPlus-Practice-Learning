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
	IOPIN0 = c<<15;
	IOCLR0 = RS;				//RS = 0
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(1000);
	IOCLR0 = EN;
}
void data(char c)
{
	IOPIN0=c<<15;
	IOSET0 = RS;		//RS = 1
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(500);
	IOCLR0 = EN;
}

void data1(char c[])
{
	int i = 0; 
	for(i = 0;c[i]!='\0';i++)
	{
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
 	 
	 command(0x38);
	 command(0x0e);
	 command(0x01);
	 command(0x80);
}

