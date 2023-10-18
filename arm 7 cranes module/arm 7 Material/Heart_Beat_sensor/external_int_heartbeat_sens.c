//	#include<LPC214X.H>
	#include"prototypes.h"
 		int heart_beat = 0;

		void ext_int2(void)__irq
		{
			EXTINT = 0X04;	
		  	heart_beat++	;	 // count the number of heart beat
		  	VICVectAddr = 0;
		}
	
	  	void external_interrupt_init(void)
		{
			PINSEL0 = (((PINSEL0 & ~(0X3 << 14)) | (3 << 14)));// selecting EINT2 for P0.7
			VICVectAddr3 = (long)ext_int2;
			VICVectCntl3 = (1 << 5) | 16;
			EXTPOLAR = 0x04;
			EXTMODE = 0X04;
			VICIntSelect = (0 << 16);
			VICIntEnable = (1 << 16);
		}

		  
	
	
	
	
