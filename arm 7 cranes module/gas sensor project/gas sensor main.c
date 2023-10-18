#include<lpc214x.h>
#include"lcd link.h"
//#include<gsm.h>
#define MOTOR_1 (1<<20)
#define MOTOR_2 (1<<17)
#define MOTOR_3 (1<<18)
#define MOTOR_4 (1<<19)

int main()
{
	unsigned int done = 1;					   
	int result = 0,i;
	char a[] = "gas leakage";
	PINSEL1 |= (0<<25 | 1<<24) ;
	IODIR1 |= (1<<20|1<<17|1<<18|1<<19);
	lcd();
	U0LCR = 1<<0|1<<1|1<<7;
	U0DLL = 97;
	U0LCR = 1<<0|1<<1|0<<7;
	PINSEL0 = 0<<3|1<<2|0<<1|1<<0;
	while(1)
	{
		AD0CR = (1 << 1| 3 << 8| 1 << 16 | 1 << 21);
		while(!(AD0DR1 & (done << 31)));
		result = ((AD0DR1 >> 6) & 0x3ff);
		command(0x80);
		command(0x01);
		lcd_string("GAS SENSOR:");
		display(result);
		delay(300);
		command(0x01);
		if(result >= 900)
		{
			lcd_string("GAS DETECTED");
			for(i =0; a[i] != '\0';i++)
			{
				while(!(U0LSR & 1<<5));	   //data transmitter register
				U0THR = a[i];
				//while(!(U0LSR & 1<<0));		//data reciever register
				//a[i] = U0RBR;
			}
			//while(!(U0LSR & 1<<0));		//data reciever register
			//a = U0RBR;
			
			while(i != 10)
			{
				//MOTOR CLOCKWISE ROTATION
				IOSET1 = MOTOR_2;
				delay(100);
				IOCLR1 = MOTOR_2;
				delay(100);
			
				IOSET1 = MOTOR_3;
				delay(100);
				IOCLR1 = MOTOR_3;
				delay(100);
			
				IOSET1 = MOTOR_1;
				delay(100);
				IOCLR1 = MOTOR_1;
				delay(100);
			
				IOSET1 = MOTOR_4;
				delay(100);
				IOCLR1 = MOTOR_4;
				delay(100);

				i++;
			}
		}
		else
		{
			lcd_string("GAS DOES NOT DETECTED");
			delay(1000);
			command(0x01);
		}

	}
}

