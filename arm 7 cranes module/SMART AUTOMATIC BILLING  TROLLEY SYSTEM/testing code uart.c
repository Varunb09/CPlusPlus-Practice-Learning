#include<lpc214x.h>
#include<string.h>
#include"lcd link.h"

char b1[] = "00003B50B2D9";
char b2[] = "0000449F3FE4";
char b3[] = "00003BC2C831";
int item1 = 200,item2 = 250,item3 = 300,c,flag = 0;
static int total;
char a[12];

int billing(void)
{
	int i=0;	
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
	//lcd_string(a);
	if(strncmp(a,b1,12) == 0)
	{
		total += item1;	
	}
	if(strncmp(a,b2,12) == 0)
	{
		total += item2;
	}
	if(strncmp(a,b3,12) == 0)
	{
		total += item3;
	}
	return(total);
}

void eint3_isr_delete(void)__irq
{
	int i=0;
	while(i<=11)
	{
		while(!(U1LSR & 1<<0));		//data reciever register
		a[i] = U1RBR;
		i++;
	}
	//lcd_string(a);
	if(strncmp(a,b1,12) == 0)
	{
		total -= item1;	
	}
	if(strncmp(a,b2,12) == 0)
	{
		total -= item2;
	}
	if(strncmp(a,b3,12) == 0)
	{
		total -= item3;
	}
	command(0x80);
	//c = billing();
	display(total);
	flag = 1;
	VICVectAddr = 0;
	EXTINT = 1<<3;
	//return(total);	
}
int main()
{
	lcd();
	U1LCR = 1<<0|1<<1|1<<7;
	U1DLL = 97;
	U1LCR = 1<<0|1<<1|0<<7;
	PINSEL0 = 0<<17|1<<16|0<<19|1<<18;

	VICIntEnable = 1<<17;		 // enabling eint3 interupt
	VICIntSelect = 0<<17;		 // selecting as IRQ interupts 	and 1 for FIQ interupts
	VICVectAddr0 = (long)(eint3_isr_delete);	  //giving address of sub routine to vector address registor 
	VICVectCntl0 = 1<<5|17;				  //'o' for selecting slot 0 of 20 vector regitor and 1 is slot enabling bit at 5th bit of registor and 17 give id of the address 
	EXTMODE = 1<<3;					  //edge triggering
	EXTPOLAR = 0<<3;
	while(1)
	{
		if(flag == 0)
		{
			command(0x80);
			c = billing();
			display(c);	
		}
		else
		{
			flag = 0;	
		}
	}	
}
