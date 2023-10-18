	#include<lpc214x.h>							 			
/************* LCD Pins *******************/
	#define RS (1 << 24) 
	#define EN (1 << 25)
//	#define data_pins (0xf << 12)

/************* LCD Function *************/

	void lcd_init(void);
	void lcd_cmd(unsigned char );
	void lcd_data(unsigned char );
	void delay(unsigned int );
	void Clr_Lcd(void);
	void lcdstring(unsigned char *);

	void display(long int );

/************* ******************/

//	#define LED (1 << 7)
/*************Timer *****************/			

	void timer_init(void);
	void timer_isr(void)__irq;
//	#define TRIGGER (1 << 4)
//	#define ECHO (1 << 5)
//	#define LED (1 << 7)

/***************************************/
  	void external_interrupt_init(void);
  	void ext_int2(void)__irq;

	void timer_init(void);
	void timer_isr(void)__irq;

	void CONVERT_ADC(int );
