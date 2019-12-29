#include "define.h"


void main()
{
	timer0_init();
	timer1_init();
	while(1)
	{
		numbertomusic();
		numbertoRGB();
		RGBtoLIGHT();
  	show_note();
	}
}