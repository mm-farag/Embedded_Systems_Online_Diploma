/*
 ============================================================================
 Name        : unit2_Lesson4_Arrays_Storing_And_Printing_10_Students_Degrees_Loops.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned char i = 0;
	float students[10];

	for( i = 0; i < sizeof(students)/sizeof(float); i++ )
	{
		fflush(stdin); fflush(stdout); scanf("%f", &students[i]);
		//		printf("%d\n", i);
	}

	printf("=================\n");

	for( i = 0; i <sizeof(students)/sizeof(float); i++ )
	{
		printf("%f\n", students[i]);
	}

	return EXIT_SUCCESS;
}
