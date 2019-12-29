#ifndef  _UART_H_
#define  _UART_H_
unsigned char str2[100]={0};
unsigned char str = 0xff;
unsigned char index=0;

void delay_ms(int n)	 
{
	int i,j;
	for(j=n;j>0;j--)
		for(i=112;i>0;i--);
}

void uart_init(unsigned int baud)
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 256-(11059200/12/32)/baud;
	TL1 = TH1;
	TR1 = 1;
	EA = 1;
	ES = 1;
}

void uart_rupt()  interrupt 4
{
	while(RI)
	{
		str = 0xff;
		P1 = 0xff;
		RI=0;
		str2[index]=SBUF;
		index++;
		delay_ms(1);
	}
}

void reset()
{
	int i;
	index=0;
	for(i=0;i<100;i++)
	{
		str2[i]=0;
	}
}
	
void uarttoled()
{
	int j;
	unsigned char led[]={0XFE,0XFD,0XFB,0XF7,0XEF,0XDF,0XBF,0X7F};
	if(str2[0]=='K' && str2[1]=='X')
	{
		for(j=2;str2[j]!=0;j++)
		{
			if(str2[j]<='8' && str2[j]>='0')
			{
				P1&=led[str2[j]-'1'];
				str&=led[str2[j]-'1'];
			}
		}
	}
}

void led_flash()
{
	P1=str;
	delay_ms(100);
	P1=0xff;
	delay_ms(100);
}
/*******************************************
          题目1
*********************************************/
unsigned char str1[]={'K','X',' ','n','b'};

void return_nb()
{
	unsigned char i,k;
	if(str2[0]=='K' && str2[1]=='X')
	{
		for(i=2;i<100;i++)
		{
			if (str2[i]!=0)
			{
				break;
			}
			if(str2[i]==0 && i!=99)
			{
				continue;
			}
			for(k=0;k<5;k++)
			{
				SBUF=str1[k];
				while(!TI);
				TI=0;
			}
		}
	}
}
/*******************************************
					题目二
*******************************************/
void return_content()
{
	int j=0,i=0;
	for(j=99;j>1;j--)
	{
		if(str2[j]==0)
		{
			continue;
		}
		for(i=2;i<=j;i++)
		{
			SBUF=str2[i];
			while(!TI);
			TI=0;
		}
		break;
	}
}
/******************************************
					题目三
********************************************/
#endif