/*
 ============================================================================
 Name        : unit2_Lesson5_Recursion_Infinite.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void function_Print_Hello(void)
{
	static unsigned long int counter;
	printf("Hello\n");
	printf("%ld\n", counter++);
	function_Print_Hello();
}

int main(void)
{
	function_Print_Hello();
	return EXIT_SUCCESS;
}
