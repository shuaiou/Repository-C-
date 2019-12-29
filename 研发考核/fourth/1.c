#include "reg52.h"
void timer0_init();
void delay_ms(unsigned int ms);          //·â×°PWMºôÎüµÆ

unsigned int duty_circle_0=0;

void main()
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
	TH0 = (65535-(11059200/12)*10/1000000)/256;       //10us
	TL0 = (65535-(11059200/12)*10/1000000)%256;
	TR0 = 1;
	EA = 1;
	ET0 = 1;
}

void timer0_rupt()     interrupt 1
{
	static unsigned int count=0;
	TH0 = (65535-(11059200/12)*10/1000000)/256;
	TL0 = (65535-(11059200/12)*10/1000000)%256;
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