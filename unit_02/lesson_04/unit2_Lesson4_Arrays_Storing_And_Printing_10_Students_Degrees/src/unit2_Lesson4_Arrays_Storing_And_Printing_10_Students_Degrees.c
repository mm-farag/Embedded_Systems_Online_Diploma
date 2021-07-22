/*
 ============================================================================
 Name        : unit2_Lesson4_Arrays_Storing_And_Printing_10_Students_Degrees.c
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
	float student[10];
	fflush(stdin); fflush(stdout); scanf("%f", &student[0]);
	fflush(stdin); fflush(stdout); scanf("%f", &student[1]);
	fflush(stdin); fflush(stdout); scanf("%f", &student[2]);
	fflush(stdin); fflush(stdout); scanf("%f", &student[3]);
	fflush(stdin); fflush(stdout); scanf("%f", &student[4]);
	fflush(stdin); fflush(stdout); scanf("%f", &student[5]);
	fflush(stdin); fflush(stdout); scanf("%f", &student[6]);
	fflush(stdin); fflush(stdout); scanf("%f", &student[7]);
	fflush(stdin); fflush(stdout); scanf("%f", &student[8]);
	fflush(stdin); fflush(stdout); scanf("%f", &student[9]);

	printf("%f\n", student[0]);
	printf("%f\n", student[1]);
	printf("%f\n", student[2]);
	printf("%f\n", student[3]);
	printf("%f\n", student[4]);
	printf("%f\n", student[5]);
	printf("%f\n", student[6]);
	printf("%f\n", student[7]);
	printf("%f\n", student[8]);
	printf("%f\n", student[9]);







	return EXIT_SUCCESS;
}
