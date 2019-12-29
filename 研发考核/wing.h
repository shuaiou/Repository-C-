/*****************************************************

LED显示函数（呼吸灯，流水灯，跑马灯）

*****************************************************/
/*
#include "reg52.h"
void timer0_init();
void delay_ms(unsigned int ms);          //封装PWM呼吸灯

unsigned int duty_circle_0=0;

void PWM_LED()
{
	timer0_init();
	while(1)
	{
		duty_circle_0+=2;
		if(duty_circle_0==100)
		{
			duty_circle_0=0;
		}
		delay_ms(1);
	}
}

void timer0_init()
{
	TMOD |= 0x01;
	TH0 = 0XFF;
	TL0 = 0Xf7;
	TR0 = 1;
	EA = 1;
	ET0 = 1;
}

void timer0_rupt()     interrupt 1
{
	static unsigned int count=0;
	TH0 = 0XFF;
	TL0 = 0Xf7;
	if(count < duty_circle_0)
	{
		P1=0X00;
	}
	else if(count <100)
	{
		P1=0XFF;
	}
	else
	{
		count=0;
	}
	count++;
}

void delay_ms(unsigned int ms)
{
	unsigned int i;
	unsigned int j;
	for (i=0;i<ms;i++)
	{
		for(j=0;j<200;j++);
		for(j=0;j<102;j++);
	}	
}
*/
void WATER_LED(unsigned char time1)
{
	unsigned char i;
	P1=0XFE;
	for(i = 0;i < 8;i++)
	{
		P1 <<= 1;
		delay_ms(time1);
	}
	P1=0X7F;
	for(i = 0;i < 8;i++)
	{
		P1 >>=1;
		delay_ms(time1);
	}
}

void HORSE_LED(unsigned char time2)
{
	unsigned char i;
	for(i = 0;i < 7;i++)
	{
		P1 = ~(0X01<<1);
		delay_ms(time2);
	}
	for(i = 0;i < 7;i++)
	{
		P1 = ~(0X80>>1);
		delay_ms(time2);
	}
}

/*****************************************************

数码管显示函数

*****************************************************/
void show_tube(unsigned char lefttoright)
{
	switch(lefttoright)
	{
		case 0:P2&=0XFE;P2|=0x20;P2|=0X40;P2|=0X80;break;
		case 1:P2|=0X01;P2&=0XFD;P2|=0X40;P2|=0X80;break;
		case 2:P2|=0X01;P2|=0X20;P2&=0XFB;P2|=0X80;break;
		case 3:P2|=0X01;P2|=0X20;P2|=0X40;P2&=0XF7;break;
	}
}

void show_n(unsigned char n)
{
	const char t[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10,0x08,0x03,0x36,0x21,0x06,0x0e};	
	P0=t[n];
	delay_ms(5);    ////////////////////////
	P0=0XFF;
}

void show_num(unsigned int num)
{
	unsigned char n;
	unsigned char i;
	for(i = 0;i < 4;i++)
	{
		n = num%10;
		num = num/10;
		show_tube(3-i);
		show_n(n);
	}
}
/****************************************************

按键扫描

****************************************************/

unsigned char KEY_4()
{
	while(~P3 & 0X04)
	{
		delay_ms(10);
		while(~P3 & 0X04)
		{
			while(~P3 & 0X04);
			return 1;
		}
		while(~P3 & 0X08)
		{
			while(~P3 & 0X08);
			return 2;
		}
		while(~P3 & 0X10)
		{
			while(~P3 & 0X10);
			return 3;
		}
		while(~P3 & 0X20)
		{
			while(~P3 & 0X20);
			return 4;
		}
	}
}

unsigned char KEY_8()         ////   define KEY=????  
{
	KEY=0x00;
	if(KEY!=0x00)
	{
		delay_ms(10);
		if(KEY!=0x00)
		{
			switch (KEY)
			{
				case 0x80:return 8 ;
				case 0x40:return 7 ;
				case 0x20:return 6 ;
				case 0x10:return 5 ;
				case 0x08:return 4 ;
				case 0x04:return 3 ;
				case 0x02:return 2 ;
				case 0x00:return 1 ;
				default:return 0;
			}
		}
	}
	KEY=0xff;
}

unsigned char KEY_16()
{
  unsigned char s=0;
	P1=0xf0;
	while(P1!=0xf0)
	{
		delay_ms(10);
		if(P1!=0xf0)
		{
			P1=0xf0;
			switch(P1)
			{
				case 0x70:s=12;break;
				case 0xb0:s=8;break;
				case 0xd0:s=4;break;
				case 0xe0:s=0;break;
			}
			P1=0x0f;
			switch(P1)
			{
				case 0x07:s=s+1;break;
				case 0x0b:s=s+2;break;
				case 0x0d:s=s+3;break;
				case 0x0e:s=s+4;break;
			}
			while(P1!=0x0f);
			return s;
		}
	}
	return 0;
}


/****************************************************

定时器中断函数（定时器中断）

*****************************************************/

void timer0_init()
{
	TMOD |= 0x01;
	TH0 = 0XFF;
	TL0 = 0XA4;
	TR0 = 1;
//	EA = 1;             选择定时器中断
//	ET0 = 1;
}

void timer1_init()
{
	TMOD |= 0x10;
	TH1 = 0XFF;
	TL1 = 0XA3;
	TR1 = 1;
//	EA = 1;             选择定时器中断
//	ET1 = 1;
}

void timer0_rupt()     interrupt 1
{
	TH0 = 0XFF;
	TL0 = 0XA3;
}

void timer1_rupt()      interrupt 3
{
	TH0 = 0XFF;
	TL0 = 0XA3;
}

/****************************************************

串口中断函数

*****************************************************/
void uart_init(unsigned int baud)
{
	SCON = 0X50;
	TMOD |= 0X20;
	TH1 = 256-(11059200/12/32)/baud;
	TL1 = TH1;
	TR1 = 1;
//	EA = 1;        选择串口中断
//	ES = 1;
}

void uart_rupt()   interrupt 4
{
	if(!RI)
	{
		RI = 0;
		SBUF = SBUF;
	}
	if(!TI)
	{
		TI = 0;
	}
}

/*****************************************************

延时函数

******************************************************/

/*void delay_ms(unsigned int ms)
{
	unsigned int i;
	unsigned int j;
	for (i=0;i<ms;i++)
	{
		for(j=0;j<200;j++);
		for(j=0;j<102;j++);
	}	
}

void delay_us10(unsigned int us)
{
	us=us*2;          //实际偏小，大概9微妙左右
	while(us--);
}*/
void delay_ms(int n)	 
{
	int i,j;
	for(j=n;j>0;j--)
		for(i=112;i>0;i--);
}

void delay_us10(int t)
{
	int i;
	for(i=0;i<=t;i++);
}