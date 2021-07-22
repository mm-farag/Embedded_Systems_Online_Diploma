/*
 ============================================================================
 Name        : unit2_Lesson5_Extern_With_Global.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void function_print_Variable(void);

extern int x_X;


int main(void)
{

	printf("main file x_X = %d\n", x_X);
	function_print_Variable();
	x_X = 33;
	printf("main file x_X = %d\n", x_X);
	function_print_Variable();



	return EXIT_SUCCESS;
}
