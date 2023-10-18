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
void digit0(int x)
{
		IOCLR0 = 1<<7;
		S0SPDR = (1 << 8) | (x << 0);
		delay(1000);
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}
void digit1(int x)
{
		IOCLR0 = 1<<7;
		S0SPDR = 1<<9| x << 0;			   //1<<3 is used for switching on the decimel point of digit1
		delay(1000);
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}
void digit2(int x)
{
		IOCLR0 = 1<<7;
		S0SPDR = 1<<9|1<<8|x<<0;
		delay(1000);
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}
void digit3(int x)
{
		IOCLR0 = 1<<7;
		S0SPDR = 1<<10|x<<0;
		delay(1000);
		while(!(S0SPSR & 1<<7));
		IOSET0 = 1<<7;
}

void segment()
{
	
	PINSEL0 |= (0 << 13 | 1 << 12 | 0 << 11 | 1 << 10 | 0 << 9 | 1 << 8);
	//IODIR0 = 1<<7;
	S0SPCR = 1 << 2 | 1 << 5;
	S0SPCCR = 8;


	shutdown_to_normal();
   	decode_mode();
	scan_limit();
	maximum_intensity();
	
	//digit0();
	//digit1();
	//digit2();
	//digit3();
}