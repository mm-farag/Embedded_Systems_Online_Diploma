/*
 ============================================================================
 Name        : ggggggggggggggggg.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */





#include <stdio.h>
#include <stdlib.h>
int x = 0;
#define UART0DR *(volatile unsigned int*)(unsigned int*)&x
int main(void)
{
	printf("x = %d\n", x);
	x = 1;
	printf("UARTDR = %d\n", UART0DR);
	UART0DR = 2;
	printf("UARTDR = %d\n", UART0DR);

	return EXIT_SUCCESS;
}
