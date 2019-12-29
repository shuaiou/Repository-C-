#include "reg52.h"

void timer1_init();
void timer0_init();
void delay_ms(int n);
void Pwm_Duty(unsigned char j);
void indextoled();

unsigned char count=0,index=0,i;
code unsigned char led[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
code unsigned char duty_circle[]={2,5,15,30,60,100,145,165};
	
void main()
{
	timer0_init();
	timer1_init();
	while(1)
	{
		indextoled();
	}
}

void timer0_init()
{
	TMOD |= 0x01;
	TH0 = (65535-(11059200/12)*(1/921600))/256;
	TL0 = (65535-(11059200/12)*(1/921600))%256;
	TR0 = 1;
	EA = 1;
	ET0 = 1;
}

void timer0_rupt()   interrupt 1
{
	TH0 = (65535-(11059200/12)*(1/921600))/256;
	TL0 = (65535-(11059200/12)*(1/921600))%256;
	for(i = 0;i < index;i++)
	{
		Pwm_Duty(i);
	}
	count++;
}

void timer1_init()
{
	TMOD |= 0x10;
	TH1 = 0x00;
	TL1 = 0x00;
	TR1 = 1;
	ET1 = 1;
}

void timer1_rupt()   interrupt 3
{
	TH1 = 0x00;
	TL1 = 0x00;
}

void Pwm_Duty(unsigned char j)
{
	if(count < duty_circle[j])
	{
		P1 = led[j];
	}
	else if(count <165)
	{
		P1 = 0xff;
	}
	else
	{
		count = 0;
	}
}

void delay_ms(int n)	 
{
	int k,j;
	for(j=n;j>0;j--)
		for(k=112;k>0;k--);
}

void indextoled()
{
	index++;
	delay_ms(1);
	if(index==8)
	{
		index=0;
	}
}