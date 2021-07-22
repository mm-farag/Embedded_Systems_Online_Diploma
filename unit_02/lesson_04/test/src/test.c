/*
 ============================================================================
 Name        : test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "function_1.h"


void print(int counter)
{
	printf("%d\n", counter);
	if(--counter > 0)
		print(counter);
}



int main(void)
{
	print(3);

	return EXIT_SUCCESS;
}
