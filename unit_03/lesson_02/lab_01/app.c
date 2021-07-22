#include "uart.h"

unsigned char string_Buffer[100] = "learn-in-depth: Faragelloooooooooo";
const unsigned char  string_Buffer_02[100];
unsigned const int x = 5;

void main(void)
{
	int const y = 7;
	UART_Send_String(string_Buffer);
}
