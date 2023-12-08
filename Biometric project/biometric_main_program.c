#include<lpc214x.h>		
#include"lcd link.h" 


void tx0(int c)		 //uart transmitter
{
		while(!(U0LSR & (1 << 5)));
		U0THR = c;
}

char rx0()		 //uart transmitter
{
		while(!(U0LSR & (1 << 5)));
		return U0RBR;
}

void uart_init()
{
	PINSEL0 = 1<<0|1<<2;
	U0LCR = 0X80;
	U0DLL = 97;
	U0LCR = 0X03;
}

void delay_ms(unsigned int ms)
{
	T0TCR = 0x02;
	T0TCR = 0x01;
	while((T0TC<ms));
	T0TCR = 0x00;
}
void timer_init()
{
	// T0TCR = 1<<0;
	 T0PR = 14999;
	 T0TCR = 1<<1;
}
int main()
{

	int i;
	unsigned char ch=1,k=1;
	lcd();
	timer_init();
	uart_init();
	
	while(1)
	{
	tx0(0xef);		//header	 
	tx0(0x01);
						
	tx0(0xff);			 // module address 
	tx0(0xff);
	tx0(0xff);
	tx0(0xff);

	tx0(0x01);		//packaage identifiers

	tx0(0x00);	   // package length
	tx0(0x03);

	tx0(0x01);		 //instruction caode

	tx0(0x00); 		//check sum
	tx0(0x05);

	for(i = 0;i<10;i++)
	{
		k = rx0();
		if(i == 9)
		{
			ch = k;
			k = rx0();
			k = rx0();
			if(ch == 0x00)
			{
					k = 1;
					tx0(0xef);
					tx0(0x01);

					tx0(0xff);
					tx0(0xff);
					tx0(0xff);
					tx0(0xff);

					tx0(0x01);

					tx0(0x00);
					tx0(0x04);

					tx0(0x02);

					tx0(0x01);

					tx0(0x00);
					tx0(0x08);
					i = 0;
					for(i =0 ; i<10; i++)
					{
						k = rx0();
						if(i ==9)
						{
							ch = k;
							k = rx0();
							k = rx0();
							if(ch == 0x00)
							{
								lcd_string("Take off your fingure");
								command(0x01);
								lcd_string("Take off your fingure");
								command(0xc0);
								delay_ms(2000);
							//	delay(2000);								
							}
						}
					}
			}
		}
	}
	}
}

