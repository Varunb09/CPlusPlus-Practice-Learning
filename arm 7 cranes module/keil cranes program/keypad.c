#include<lpc214x.h>
#include "keypad link lcd.h"
#define ROW (1<<17|1<<18|1<<19|1<<20)
#define COL (1<<21|1<<22|1<<23|1<<24)

void rowdefine(void);
int main()
{
	int Z = 0;
	lcd();

	while(1)
	{
		IODIR1 = ROW;					  
		//initialize row with zero
		IOCLR1 = ROW;	
		command(0x01);
		Z = (IOPIN1 & COL);		   //Z=0x1e00000   cheaking whether any switch is pressed or not
		if(Z != 0x1e00000)
		{
			if(Z == 0x1c00000)				//gives col 1
			{
				
				command(0x80);
				data("col_1");
				rowdefine();			//finding row adress and printing
				break;
				
			}
			if(Z == 0x1a00000)				//gives col 2
			{
				
				command(0x80);
				data("col_2");
				rowdefine();
				break;
				
			}
			if(Z == 0x1600000)				// gives col 3
			{
				
				command(0x80);
				data("col_3");
				rowdefine();
				break;
				
			}	
			if(Z == 0x0e00000)				//gives col 4
			{
				
				command(0x80);
				data("col_4");
				rowdefine();
				break;
			}
		}
	}	
}

void rowdefine()
{
	int y =0;
		IODIR1 = COL;
		IOCLR1 = COL;			//initializing collumm as zero
		y = (IOPIN1 & ROW);		   //y=0x1e0000	 check wheather row is pressed or not
			if(y != 0x1e0000)
			{
				if(y == 0x1c0000)		  //gives row 1
				{
					command(0xc0);
					data("row_1 pressed :)");
				}
				if(y == 0x1a0000)		   //gives row 2
				{
					command(0xc0);
					data("row_2 pressed :)");
				}
				if(y == 0x160000)		   //gives row 3
				{
					command(0xc0);
					data("row_3 pressed :)");
				}
				if(y == 0x0e0000)			//gives row 4
				{
					command(0xc0);
					data("row_4 pressed :)");
				}
			}
}
	