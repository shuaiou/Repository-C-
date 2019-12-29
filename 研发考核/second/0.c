#include "reg52.h"

unsigned char KEY_SIGNAL();
void delay_ms(unsigned int n)	;

void main()
{
	unsigned char i;
	while(1)
	{
		for(i = 0;i < 8;i++)
		{
			P1 =(0xfe << i);
			delay_ms(50);
			while(1==KEY_SIGNAL());
		}
		for(i = 0;i < 8;i++)
		{
			P1 =(0x7f >> i);
			delay_ms(50);
			while(1==KEY_SIGNAL());
		}
	}
}
/******************************
					P3^2°´¼ü
******************************/

unsigned char KEY_SIGNAL()
{
	static unsigned char flag=0;
	while(!(P3&0x04))
	{
		delay_ms(10);
		while(!(P3&0x04))
		{
			while(!(P3&0x04));
			flag=!flag;
			return flag;
		}
	}
	return flag;
}
/*************************
         ÑÓÊ±
**************************/
void delay_ms(unsigned int n)	 
{
	int i,j;
	for(j=n;j>0;j--)
		for(i=112;i>0;i--);
}
