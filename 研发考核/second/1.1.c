#include "reg52.h"

#define KEY P0

unsigned char KEY_16();
void delay_ms(unsigned int n)	;

unsigned char flag=1;

void main()
{
	unsigned char i;
	while(1)
	{
		for(i = 0;i < 8;i++)
		{
			P1 =(0xfe << i);
			delay_ms(50);
			while((i+1)==KEY_16() || flag==0)
			{;}
		}
		for(i = 0;i < 8;i++)
		{
			P1 =(0x7f >> i);
			delay_ms(10);
		}
	}
}

unsigned char KEY_16()
{
  static unsigned char s=0;
	KEY=0xf0;
	while(KEY!=0xf0)
	{
		delay_ms(10);
		if(KEY!=0xf0)
		{
			KEY=0xf0;
			switch (KEY)
			{
				case 0x70:s=12;break;
				case 0xb0:s=8;break;
				case 0xd0:s=4;break;
				case 0xe0:s=0;break;
			}
			KEY=0x0f;
			delay_ms(5);
			KEY=0x0f;
			switch(KEY)
			{
				case 0x07:s=s+1;break;
				case 0x0b:s=s+2;break;
				case 0x0d:s=s+3;break;
				case 0x0e:s=s+4;break;
			}
			while(KEY!=0x0f);
			if(s==16)flag=!flag;
			return s;
		}
	}
	return s;
}

void delay_ms(unsigned int n)	 
{
	int i,j;
	for(j=n;j>0;j--)
		for(i=112;i>0;i--);
}
