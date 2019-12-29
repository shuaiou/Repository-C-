#include "reg52.h"
#include "LCD1602.h"

unsigned char judge,flag;
unsigned int count=0;

void uart_init(unsigned int baud);
void jusgement();
void delay_s();
void timer_init();
void timer_go();
void timer_stop();
void first();
void second();

void main()
{	
	lcd_init();
	uart_init(9600);
	menu_1();
	while(1)
	{
		jusgement();
	}
}

void delay_ms(int n)	 
{
	int i,j;
	for(j=n;j>0;j--)
		for(i=112;i>0;i--);
}

void uart_init(unsigned int baud)
{
	SCON = 0x50;
	TMOD |= 0x20;
	TH1 = 256-(11059200/12/32)/baud;
	TL1 = TH1;
	TR1 = 1;
	EA = 1;
	ES = 1;
	PS = 1;
}

void uart_rupt()  interrupt 4
{
	while(RI==1)
	{
		RI=0;
		judge=SBUF;
		delay_ms(1);
	}
	second();
}

void jusgement()
{
	if((flag==1 || flag==2 || flag==3) && judge=='R')
	{
		menu_1();
		flag=0;
	}
	else if(flag==0 && judge=='A')
	{
		menu_2();
		flag=1;
	}
	else if((flag==0 && judge=='B') || (flag==3 && judge=='R'))
	{
		menu_3();
		flag=1;
	}
	else if(flag==1 && judge=='C')
	{
		first();flag=2;
	}
	else if(flag==1 && judge=='D')
	{
		flag=3;
	}
	else
	{
		;
	}
}

/*            FIRST               */
void first()
{
	int i;
	timer_init();
	while(judge != 'R')
	{
		for(i=0;i<8;i++)
		{
			P1=0xfe<<i;
			if(judge == 'R')break;
			delay_s();
		}
		for(i=0;i<8;i++)
		{
			P1=0x7f>>i;
			if(judge == 'R')break;
			delay_s();
		}
	}
	P1=0XFF;
	timer_stop();
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
	TMOD |= 0X01;
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
/*             SECOND                   */

void second()
{
	if(judge=='1' && flag==3)
	{
		P2&=0XDF;
	}
	if(judge=='0' && flag==3)
	{
		P2|=0X20;
	}	
}