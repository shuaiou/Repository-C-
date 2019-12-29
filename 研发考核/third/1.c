#include "reg52.h"
#include "UART.h"

void main()
{
	uart_init(9600);
	while(1)
	{
		while(str2[0]!='K' || str2[1]!='X')led_flash();
		uarttoled();
		return_nb();
		return_content();
		reset();
	}
}