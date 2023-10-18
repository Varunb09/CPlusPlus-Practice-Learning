#include<lpc214x.h>
#include<string.h>
#include"lcd link.h"

char b1[] = "00003B50B2D9";
char b2[] = "0000449F3FE4";
char b3[] = "00003BC2C831";
int item1 = 200,item2 = 250,item3 = 300;
volatile int total = 0;
char a[13];

int billing(void)
{
	int i = 0;
	memset(a,0,13);
	lcd();
	U1LCR = 1<<0|1<<1|1<<7;
	U1DLL = 97;
	U1LCR = 1<<0|1<<1|0<<7;
	PINSEL0 = 0<<17|1<<16|0<<19|1<<18;	
	while(i<=11)
	{
		while(!(U1LSR & 1<<0));		//data reciever register
		a[i] = U1RBR;
		i++;
	}
	lcd_string(a);
	if(strncmp(a,b1,12) == 0)
	{
		total = item1;	
	}
	else if(strncmp(a,b2,12) == 0)
	{
		total = item2;
	}
	else if(strncmp(a,b3,12) == 0)
	{
		total = item3;
	}
	else 
		return 0;
	//z =total;
	//total = 0;
	return(total);
}

int delete(void)
{
	int i = 0;
	memset(a,0,13);
	lcd();
	U1LCR = 1<<0|1<<1|1<<7;
	U1DLL = 97;
	U1LCR = 1<<0|1<<1|0<<7;
	PINSEL0 = 0<<17|1<<16|0<<19|1<<18;
	while(i<=11)
	{
		while(!(U1LSR & 1<<0));		//data reciever register
		a[i] = U1RBR;
		i++;
	}
	lcd_string(a);
	if(strncmp(a,b1,12) == 0)
	{
		total = item1;	
	}
	else if(strncmp(a,b2,12) == 0)
	{
		total = item2;
	}
	else if(strncmp(a,b3,12) == 0)
	{
		total = item3;
	}
	else
		return 0;
	//z =total;
	//total = 0;
	return(total);	
}

