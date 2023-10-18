//Lcd interfacing

#include<lpc214x.h>

#define EN 1<<10
#define RS 1<<13
#define RW 1<<12
#define LCD_DATA  0X0F

void command( int c );
void data( char c );
void delay( int c );

void lcd()
{
	//char *string1 = "varun nisha"; 
	//char *string2 = "radhika";
	IODIR0 = ( (LCD_DATA  << 15) | EN | RW | RS );
	command( 0x28 );
	command( 0x0E );
	command( 0x01 );
	//command( 0x80 );
	command( 0x0F );
	command( 0x1C );
	/*while(*string1)
	{
		data(*string1);
		string1++;
	//	command( 0x14 );  
	} */
}

void command( int c )
{
	char cmd;
	cmd = (c & 0xf0 ) >> 4;
	IOPIN0 = cmd << 15;
	IOCLR0 = RS;
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(1000);
	IOCLR0 = EN;

	cmd = (c & 0x0F );

	IOPIN0 = cmd << 15;
	IOCLR0 = RS;
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(1000);
	IOCLR0 = EN;
}

void data( char c )
{
	char cmd;
	cmd = (c & 0xf0) >> 4;

	IOPIN0 = cmd << 15;
	IOSET0 = RS;
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(1000);
	IOCLR0 = EN;

	cmd = (c & 0x0f);

	IOPIN0 = cmd << 15;
	IOSET0 = RS;
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(1000);
	IOCLR0 = EN;
}

void delay( int c )
{
	int i , j;
	for( i = 0; i < c; i++)
	for(j = 0; j < 1000; j++);
}
