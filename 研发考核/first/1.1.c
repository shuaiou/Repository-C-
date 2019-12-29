#include "reg52.h"

void delay_s();
void timer_init();
void timer_go();
void timer_stop();

unsigned int count=0;

void main()
{
	int i;
	timer_init();
	while(1)
	{
		for(i=0;i<8;i++)
		{
			P1=0xfe<<i;
			delay_s();
		}
		for(i=0;i<8;i++)
		{
			P1=0x7f>>i;
			delay_s();
		}
	}
	
}
void delay_s()
{
	timer_go();
	while(count<200);
	count=0;
	timer_stop();
}

void timer_init()
{
	TMOD=0X01;
	TH0=(65535-(4608*200))/256;
	TL0=(65535-(4608*200))%256;
	EA =1;
	ET0=1;
}

void timer_go()
{
	TR0=1;
}

void timer_stop()
{
	TR0=0;
}

void timer0_rupt()   interrupt 1
{
	TH0=(65535-(4608*200))/256;
	TL0=(65535-(4608*200))%256;
	count++;
}

