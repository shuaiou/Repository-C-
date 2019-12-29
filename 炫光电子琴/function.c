#include "define.h"

//#define uint unsigned int
//#define uchr unsigned char
//#define KEY P3
//#define RGB_LIGHT P1
//#define delaytomunsic_h (65535-53535)/12/256;  //待修改
//#define delaytomunsic_l (65535-53535)/12%256;

uchr code music[10][5]={{0x85,0xc4},{0xf3,0xc4},{0xd5,0xd5,0xee},{0x71,0xc4},{0x4b,0xc4},{0xf3,0xc4},{0x91,0xee}};         ///改
//uchr code RGB[10]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf};
uchr code RGB[10]={0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uchr code note[]={0xfc8f,0xfcef,0xfd45,0xfd6c,0xfdb4,0xfdf4,0xfe2e};
uint count=0;
uint key_storige=0;
uint keys_storige=0;
uint tube_storige=0;

void keyscan_8()
{
	P1=0x00;
	if(KEY!=0x00)
	{
		delay_ms(10);
		if(KEY!=0x00)
		{
			key_storige=keytonumber();							
			tube_storige=key_storige;
			keys_storige=key_storige;
		}
	}
	P1=0xff;
}


int keytonumber()
{
	switch (KEY)
	{
		case 0x80:return 7 ;
		case 0x40:return 6 ;
		case 0x20:return 5 ;
		case 0x10:return 4 ;
		case 0x08:return 3 ;
		case 0x04:return 2 ;
		case 0x02:return 1 ;
		case 0x00:return 0 ;
		default:return keys_storige;
//		case 0xfe:return 0 ;          无用按键
	}
	return 0;
}


void numbertomusic()
{
	switch (key_storige)
	{
		case 0:stop_sound();break;
		case 1:begin_sound();delay_ms(40);break;            //待添加延时时间
		case 2:begin_sound();delay_ms(40);break;
		case 3:begin_sound();delay_ms(40);break;
		case 4:begin_sound();delay_ms(40);break;
		case 5:begin_sound();delay_ms(40);break;
		case 6:begin_sound();delay_ms(40);break;
		case 7:begin_sound();delay_ms(40);break;
	}
}

void stop_sound()
{
	BEEP=1;
	TR0=0;
	EA=0;
	ET0=0;
}

void begin_sound()
{
	TR0=1;
	EA=1;
	ET0=1;
}

void numbertoRGB()
{
	switch (key_storige)
	{
		case 0:;break;
		case 1:RED=1;GREEN=0;BLUE=0;break;
		case 2:RED=0;GREEN=1;BLUE=0;break;
		case 3:RED=0;GREEN=0;BLUE=1;break;
		case 4:RED=1;GREEN=1;BLUE=0;break;
		case 5:RED=0;GREEN=1;BLUE=1;break;
		case 6:RED=1;GREEN=0;BLUE=1;break;
		case 7:RED=1;GREEN=1;BLUE=1;break;
//		case 0xfe:return 0 ;          无用按键
	}
}

void RGBtoLIGHT()
{
	switch(key_storige)
	{
		case 0:;break;
		case 1:RGB_LIGHT=RGB[0];key_storige=0;break;
		case 2:RGB_LIGHT=RGB[1];key_storige=0;break;
		case 3:RGB_LIGHT=RGB[2];key_storige=0;break;
		case 4:RGB_LIGHT=RGB[3];key_storige=0;break;
		case 5:RGB_LIGHT=RGB[4];key_storige=0;break;
		case 6:RGB_LIGHT=RGB[5];key_storige=0;break;
		case 7:RGB_LIGHT=RGB[6];key_storige=0;break;
	}
}


void timer0_init()           //调频
{
	TMOD = 0x01;
  TH0 = (0xffff-note[key_storige])/256;
	TL0 = (0xffff-note[key_storige])%256;
	TR0 = 1;
	EA = 1;
	ET0=1;
}
//void timer1_init()       //按键 
//{
//	TMOD = 0x10;
//  TH0 = 0x88;     
//	TL0 = 0x99;
//	TR0 = 1;
//	EA = 1;
//	ET0=1;
//}

void timer0_interrupt()   interrupt 1 
{
	if(key_storige!=0)
	{
		TR0=0;
		TH0 = (0xffff-note[key_storige])/256;
		TL0 = (0xffff-note[key_storige])%256;
		BEEP=!BEEP;
		TR0=1;
	}
}


void delay_ms(uint ms)
{
	uint i;
	uint j;
	for (i=0;i<ms;i++)
	{
		for(j=0;j<200;j++);
		for(j=0;j<102;j++);
	}
}

void delay_w(uint i)
{
	while(i--);
}


void tube_choice(uchr lefttoright)
{
	switch(lefttoright)
	{
		case 0:TUBE1=0;TUBE2=1;TUBE3=1;TUBE4=1;break;
		case 1:TUBE1=1;TUBE2=0;TUBE3=1;TUBE4=1;break;
		case 2:TUBE1=1;TUBE2=1;TUBE3=0;TUBE4=1;break;
		case 3:TUBE1=1;TUBE2=1;TUBE3=1;TUBE4=0;break;
	}
}

void show_note()
{
	switch(tube_storige)
	{
		case 0:break;
		case 1:tube_choice(0);P0=music[0][0];tube_choice(1);P0=P0=music[0][1];
		case 2:tube_choice(0);P0=music[1][0];tube_choice(1);P0=P0=music[1][1];
		case 3:tube_choice(0);P0=music[2][0];tube_choice(1);P0=P0=music[2][1];tube_choice(2);P0=P0=music[2][2];
		case 4:tube_choice(0);P0=music[3][0];tube_choice(1);P0=P0=music[3][1];
		case 5:tube_choice(0);P0=music[4][0];tube_choice(1);P0=P0=music[4][1];
		case 6:tube_choice(0);P0=music[5][0];tube_choice(1);P0=P0=music[5][1];
		case 7:tube_choice(0);P0=music[6][0];tube_choice(1);P0=P0=music[6][1];
 //	case 0xfe:return 0 ;             无用按键
	}
}
	