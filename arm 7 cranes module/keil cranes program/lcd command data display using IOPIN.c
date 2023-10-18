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
	delay(1000);
	IOCLR0 = EN;
}
void data(char c[])
{
	//send data
	int i;
	for(i=0;c[i]!='\0';i++)
	{
	IOPIN0 = c[i]<<15;
	IOSET0 = RS;		//RS = 1
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(1000);
	IOCLR0 = EN;
	 }
}

int main()
{
 	 IODIR0 = (0xff<<15|EN|RW|RS);
	 command(0x38);
	 command(0x0c);
	 command(0x01);
	 command(0x80);
	 data("VARUN BHATNAGAR");
	 /*data('A');
	 data('R');
	 data('U');
	 data('N');*/
	 
	 command(0xc0);
	 data("NISHA RAI :)");
	 /*data('I');
	 data('S');
	 data('H');
	 data('A');	 */ 
}
