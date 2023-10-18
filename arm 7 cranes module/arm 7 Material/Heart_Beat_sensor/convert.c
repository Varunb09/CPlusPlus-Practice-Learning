
#include "prototypes.h"


void CONVERT_ADC(int d)
{

  unsigned char dig1,dig2,dig3;
  int temp;
    
   temp=d;
   temp=temp/10;
   dig1=d%10;
   dig2=temp%10;
   dig3=temp/10;
 
   dig3 = dig3 | 0X30;

   dig2 = dig2 | 0X30;
  
   dig1 = dig1 | 0X30;
   
   lcd_data(dig3);
   lcd_data(dig2);
   lcd_data(dig1);
   delay(30);

     
  //s =((dig3*100)+(dig2*10)+dig1);
 
}
