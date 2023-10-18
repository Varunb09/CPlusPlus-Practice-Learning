#include<lpc214x.h>

void shutdown_to_normal()
{
		IOCLR0 = 1<<7;
		S0SPDR = 0x0c01;
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}
void decode_mode()
{
		IOCLR0 = 1<<7;
		S0SPDR = 0x090f;
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}
void scan_limit()
{
		IOCLR0 = 1<<7;
		S0SPDR = 0x0b03;
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}
void maximum_intensity()
{
		IOCLR0 = 1<<7;
		S0SPDR = 0x0a0f;
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}
void digit0()
{
		IOCLR0 = 1<<7;
		S0SPDR = 0x0101;
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}
void digit1()
{
		IOCLR0 = 1<<7;
		S0SPDR = 0x0209;
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}
void digit2()
{
		IOCLR0 = 1<<7;
		S0SPDR = 0x0309;
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}
void digit3()
{
		IOCLR0 = 1<<7;
		S0SPDR = 0x0405;
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}


int main()
{
	PINSEL0 = 0<<13|1<<12|0<<11|1<<10|0<<9|1<<8;
	IODIR0 = 1<<7;
	S0SPCR = 1<<2|1<<5;
	S0SPCCR = 8;


	shutdown_to_normal();
   	decode_mode();
	scan_limit();
	maximum_intensity();
	digit0();
	digit1();
	digit2();
	digit3();
}
