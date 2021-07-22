/*
 ============================================================================
 Name        : unit2_Lesson5_Factorial.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int function_Factorial(int number)
{
	int i = 0;
	int result  = 1;

	if(number)
	{for(i=0; i<number; i++)
	{
		result*= i+1;
	}
	}
	else
	{
		return 1;
	}

	return result;
}


int main(void)
{
	int i;
	for(i = 0; i<=5; i++)
	{
		printf("factorial of %d = %d\n", i, function_Factorial(i));
	}
	return EXIT_SUCCESS;
}
