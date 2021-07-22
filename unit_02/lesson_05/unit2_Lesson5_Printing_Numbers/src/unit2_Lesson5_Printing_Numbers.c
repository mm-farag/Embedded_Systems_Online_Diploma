/*
 ============================================================================
 Name        : unit2_Lesson5_Printing_Numbers.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void function_printing_Numbers(void)
{
	int i, j;
	for(i = 0; i<10; i++)
	{
		for(j=i; j<10; j++)
		{
			printf("%d  ", j);
		}
		printf("\n");

	}

}



int main(void)
{
	function_printing_Numbers();
	return EXIT_SUCCESS;
}
