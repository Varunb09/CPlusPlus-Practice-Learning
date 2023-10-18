#include<lpc214x.h>
#include "lcd link.h"

int main()
{
	int str1[] = {"$GPGGA,135934.000,2431.0513,N,07345.0718,E,1,6,1.53,595.5,M,-52.2,M,,*78"},a[100],b[100];
	int c,i,count = 0,k;
	lcd();
	U1LCR = 1<<0|1<<1|1<<7;
	U1DLL = 97;
	U1LCR = 1<<0|1<<1|0<<7;
	PINSEL0 = 0<<17|1<<16|0<<19|1<<18;
	while(1)
	{
		while(!(U1LSR & 1<<0));		//data reciever register
		for(i = 0;i<40;i++ )
		{
			a[i] = U1RBR;
			if(a[i] == '$'||a[i] == 'G'||a[i] == 'P'||a[i] == 'G'||a[i] == 'G'||a[i] == 'A')
			{
				count++;
			}
			else
			{
				count = 0;
				delay(1000);
				break;
			}
			if(count == 6 || a[i] == 18)
			{
			   	for(k =0;j<=20;k++)
					{
						b[k]=a[i];
					}
			}
		
		}
		
	}
	
}