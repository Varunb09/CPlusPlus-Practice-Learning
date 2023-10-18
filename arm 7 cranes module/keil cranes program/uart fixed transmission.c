#include<lpc214x.h>
#include"lcd link.h"
int main()
{	
	int a[10],i;
	char b[] = {"varun"};
	lcd();
	U0LCR = 1<<0|1<<1|1<<7;
	U0DLL = 97;
	U0LCR = 1<<0|1<<1|0<<7;
	PINSEL0 = 0<<3|1<<2|0<<1|1<<0;
	while(1)
	{	
			for(i = 0;i<=5;i++)
			{
				while(!(U0LSR & 1<<0));
				a[i] = U0RBR;
				if(a[i] != b[i])
				break;
				else
				{
					command(0x01);
					data1("matched");
				}
			}
			command(0x80);
			data1("not matched");
			delay(1000);
			command(0x01);
			//while(!(U0LSR & 1<<5));
			//U0THR = a[i];
	}
}