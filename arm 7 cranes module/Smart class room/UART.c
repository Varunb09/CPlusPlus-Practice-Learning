#include<lpc214x.h>
#include"lcd link.h"
int main()
{	
	int a;
	lcd();
	U0LCR = 1<<0|1<<1|1<<7;
	U0DLL = 97;
	U0LCR = 1<<0|1<<1|0<<7;
	PINSEL0 = 0<<3|1<<2|0<<1|1<<0;
	while(1)
	{
		while(!(U0LSR & 1<<5));	   //data transmitter register
		U0THR = a;
		while(!(U0LSR & 1<<0));		//data reciever register
		a = U0RBR;	
		if(a != 8)				 
		data(a);
		else 
		command(0x01);

	}
}

