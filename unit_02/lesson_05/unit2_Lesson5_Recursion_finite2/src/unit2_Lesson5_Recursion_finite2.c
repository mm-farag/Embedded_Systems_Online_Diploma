/*
 ============================================================================
 Name        : unit2_Lesson5_Recursion_finite2.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void function_Print_Hello(int x)
{
	if(x>0)
	{
		printf("Hello %d\n", x);
		function_Print_Hello(--x);
	}


}

int main(void)
{
	function_Print_Hello(10);


	return EXIT_SUCCESS;
}
