#include<lpc214x.h>
#include "lcd link.h"

#define MOTOR_1 (1<<20)
#define MOTOR_2 (1<<17)
#define MOTOR_3 (1<<18)
#define MOTOR_4 (1<<19)
int main()
{
	//PINSEL1 |= (0<<8|0<<9|0<<3|0<<2|0<<5|0<<4|0<<7|0<<6);
	lcd();
	IODIR1 |= (1<<20|1<<17|1<<18|1<<19);
	while(1)
	{	
		 //MOTOR CLOCKWISE ROTATION
		/*IOSET1 = MOTOR_2;
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
		delay(100);  */
		
		//MOTOR ANTICLOCKWISE ROTATION		
		IOSET1 = MOTOR_4;
		delay(100);
		IOCLR1 = MOTOR_4;
		delay(100);

		IOSET1 = MOTOR_1;
		delay(100);
		IOCLR1 = MOTOR_1;
		delay(100);

		IOSET1 = MOTOR_3;
		delay(100);
		IOCLR1 = MOTOR_3;
		delay(100);

		IOSET1 = MOTOR_2;
		delay(100);
		IOCLR1 = MOTOR_2;
		delay(100);  


	}
}





































