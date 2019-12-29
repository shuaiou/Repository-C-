#include "reg52.h"

void UART_INIT(unsigned int baud);

void main()
{
	UART_INIT(9600);
	while(1);
}

void UART_INIT(unsigned int baud)
{
	SCON=0x50;
	TMOD=0x20;
	TH1=256-(11059200/12/32)/baud;
	TL1=TH1;
	TR1=1;
	EA=1;
	ES=1;
}

void uart_rupt()  interrupt 4
{
	if(RI)
	{
		RI=0;
		if(1==SBUF)
		{
			P2&=0xdf;
		}
		else if(0==SBUF)
		{
			P2|=0x20;
		}
		else;
	}
}