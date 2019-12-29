#ifndef _LCD1602_H_
#ifndef _LCD1602_H_

#define  DB  P0

sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;

int read_busy()
{
	bit sign=0;
	RS = 0;
	RW = 1;
	E = 1;
	sign = DB&0x80;
	E = 0;
	return sign;
}

void write_dat(unsigned char dat)
{
	while(read_busy());
	RS = 1;
	RW = 0;
	DB = dat;
	E = 1;
	E = 0;
}

void write_cmd(unsigned char cmd)
{
	while(read_busy());
	RS = 0;
	RW = 0;
	DB = cmd;
	E = 1;
	E = 0;
}

void set_cursor(unsigned char x,unsigned char y)
{
	unsigned char addr;
	if(y==0)
	{
		addr = 0x00 + x;
	}
	else
	{
		addr = 0x40 + x;
	}
	write_cmd(addr | 0x80);
}

void write_str(unsigned char x,unsigned char y,unsigned char *str)
{
	set_cursor(x,y);
	while(*str!='\0')
	{
		write_dat(*str++);
	}
}

//void write_num(unsigned char x,unsigned char y,unsigned int num) 
//{
//	unsigned char i,k,j;
//	unsigned char str0[]={'0','1','2','3','4','5','6','7','8','9'};
//	for(i=0;k!=0;i++)
//	{
//		j=num%10;
//		k=num/10;
//	}
//	j=k=0;
//	for(j=0;j<i;j++)
//	{
//		set_cursor(x+i-j,y);
//		k=num%10;
//		write_dat(str0[k]);
//		num=num/10;
//	}
//}

void lcd_init()
{
	write_cmd(0x38);
	write_cmd(0x0c);
	write_cmd(0x06);
	write_cmd(0x01);
}

void menu_1()
{
	write_cmd(0x01);
	write_str(0,0," Yanfa TEST>>A");
	write_str(0,1,"Temperature>>B");
}

void menu_2()
{
	write_cmd(0x01);
	write_str(0,0," First>>C");
	write_str(0,1,"Second>>D"); 
}

void menu_3()
{
	write_cmd(0x01);
	write_str(0,0,"Tem");
	write_str(7,0,"Year:");
	write_str(0,1,"Month:");
	write_str(9,1,"Date:");
	write_str(3,0,"25.1");
	write_str(12,0,"2019");
	write_str(6,1,"12");
	write_str(14,1,"27");
}
#endif