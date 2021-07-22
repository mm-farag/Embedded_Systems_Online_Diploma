/*
 ============================================================================
 Name        : polynimial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;


int main(void) {

	float x[] = {5 , 16, 22, 3.5, 15, 3, 10};
	float y;
	uint8_t i;
	for( i = 0; i < sizeof(x)/sizeof(float); i++)
	{
		y =  5 * x[i] * x[i] + 3 * x[i] + 5;
		printf("x(%f) = %f \n", x[i], y);

	}



	return EXIT_SUCCESS;
}
