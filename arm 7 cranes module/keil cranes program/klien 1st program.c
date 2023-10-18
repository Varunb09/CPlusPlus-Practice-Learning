#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
int main()
{	 
	IODIR1 = 0x3f<<17;					  //IODIR1 say direction to port 1
	/*IODIR1 |= 1<<17;					  //IODIR0 say direction to port 0
	IODIR1 |= 1<<18;
	IODIR1 |= 1<<19;*/	 
	while(1)
	{	
		IOSET1 = 0x3f<<17;       //hexa value selects the bit to set and 0 define location start shifting from...
		/*IOSET1 = 1<<17;		   //method to set individual  bit 
		IOSET1 = 1<<18;
		IOSET1 = 1<<19;*/
		delay(1000);
		IOCLR1 = 0x3f<<17;			//hexa value selects the bit to clear and 0 define location start shifting from...
		/*IOCLR1 = 1<<17;			//method to clear individual  bit
		IOCLR1 = 1<<18;
		IOCLR1 = 1<<19;*/
		delay(1000);
	}	
}
