#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i=0;i<c;i++)
	for(j=0;j<1000;j++);
}
int main()
{
	while(1)
	{
		DACR = 1023;	//for generating square wave
		delay(1000);
		DACR = 0;
		delay(1000);
	}
}