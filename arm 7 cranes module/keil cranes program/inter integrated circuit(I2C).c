#include<lpc214x.h>
#include"lcd link.h"

void display(long c)
{
	if(c)
	{
		display(c/10);
		data((c%10)+0x30); 
	}	
}
int main()
  {
  	lcd();
  	PINSEL0=1<<4|1<<6;
	I2C0CONSET=1<<6;   //ENABLE I2C
	I2C0SCLL=75;
	I2C0SCLH=75;

 //

	I2C0CONCLR=1<<3;
	I2C0CONSET=1<<5;
	while(!(I2C0CONSET & 1<<3));
	//display(I2C0STAT);
	I2C0CONCLR=1<<3;
	I2C0CONCLR=1<<5;

	I2C0DAT=0XA0;
	while(!(I2C0CONSET & 1<<3));
	//display(I2C0STAT);
	I2C0CONCLR=1<<3;

	I2C0DAT=0X00;
	while(!(I2C0CONSET & 1<<3));

	//display(I2C0STAT);
	I2C0CONCLR=1<<3;

	I2C0DAT=0X01;
	while(!(I2C0CONSET & 1<<3));
	//display(I2C0STAT);
	I2C0CONCLR=1<<3;

	I2C0DAT='A';
    while(!(I2C0CONSET & 1<<3));
	//display(I2C0STAT);
	I2C0CONCLR=1<<3;
	 
	I2C0CONSET=1<<4;
	 command(0x80);

  /////////////////////////////////////////////////////////////
	 I2C0CONCLR=1<<3;
	I2C0CONSET=1<<5;
	while(!(I2C0CONSET & 1<<3));
	//display(I2C0STAT);
	I2C0CONCLR=1<<3;
	I2C0CONCLR=1<<5;

	I2C0DAT=0XA0;
	while(!(I2C0CONSET & 1<<3));
	//display(I2C0STAT);
	I2C0CONCLR=1<<3;

	I2C0DAT=0X00;
	while(!(I2C0CONSET & 1<<3));
	//display(I2C0STAT);
	I2C0CONCLR=1<<3;

	I2C0DAT=0X01;
	while(!(I2C0CONSET & 1<<3));
	//display(I2C0STAT);
	I2C0CONCLR=1<<3;

	I2C0CONSET=1<<4;
	 command(0x80);
 ///////////////////////////////////////////////////////////////////

 	
	I2C0CONCLR=1<<3;
	I2C0CONSET=1<<5;
	while(!(I2C0CONSET & 1<<3));
	command(0xc0);
	//display(I2C0STAT);
	I2C0CONCLR=1<<3;
	I2C0CONCLR=1<<5;
	
	 	I2C0CONSET=1<<2;
		//delay(4000);

	I2C0DAT=0XA1;
	while(!(I2C0CONSET & 1<<3));
	//display(I2C0STAT);
	I2C0CONCLR=1<<3;



	data(I2C0DAT);
    while(!(I2C0CONSET & 1<<3));
	//display(I2C0STAT);
	I2C0CONCLR=1<<3|1<<2;

	I2C0CONSET=1<<4;
	 command(0x80);
	
  ///////////////////////////////////////


}
