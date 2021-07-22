/*
 ============================================================================
 Name        : unit2_Lesson5_Scope_Testing;.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 100;


	{
		int a = 200;
		printf("%d\n", a);

	}
	return EXIT_SUCCESS;
}
