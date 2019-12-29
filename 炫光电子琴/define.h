#include "reg52.h"

#define uint unsigned int
#define uchr unsigned char
#define KEY P1
#define RGB_LIGHT P3

//uchr music[10][5]={{0x85,0xc4},{0xf3,0xc4},{0xd5,0xd5,0xee},{0x71,0xc4},{0x4b,0xc4},{0xf3,0xc4},{0x91,0xee}};
//uchr RGB[10]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//uint count=0;
//uint key_storige;

sbit TUBE1 = P2^0;
sbit TUBE2 = P2^1;
sbit TUBE3 = P2^2;
sbit TUBE4 = P2^3;
sbit RED = P2^4;
sbit GREEN = P2^6;
sbit BLUE = P2^7;
sbit BEEP = P3^7;

void timer0_init();
//void timer1_init();
void keyscan_8();
int keytonumber();
void numbertomusic();
void numbertoRGB();
void RGBtoLIGHT();
void timer0_initerrupt();
//void timer1_initerrupt();
void delay_ms(uint ms);
void tube_choice(uchr lefttoright);
void show_note();
void show_DO();
void delay_w(uint i);
void stop_sound();
void begin_sound();
