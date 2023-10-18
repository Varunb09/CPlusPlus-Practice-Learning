#include<lpc214x.h>
#include<math.h>
int main()
{
	int i = 0;
	float temp = 0;
	int ang = 0;

	while(1)
	{
		for(ang = 0;ang <= 360;ang += 5)		 
		{
			temp = sin(ang*(3.14 / 180));		  //convert degree to radian
			i = (5 + (5*temp)) * 102.3;			  //increasing level by 5 and 
			DACR = (i);
		}
	}
}