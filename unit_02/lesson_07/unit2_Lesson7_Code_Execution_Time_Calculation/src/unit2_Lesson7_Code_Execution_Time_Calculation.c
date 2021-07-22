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
#include <time.h>

int main(void)
{
	int i;
	clock_t time_Start;
	clock_t time_End;
	clock_t time_Difference = 0;
//	printf("time dif = %ld\n", time_Difference);

	time_Start = clock();
	for(i=0; i<4000000; i++)
	{
		printf("Hello %d\n", i);
	}


	time_End = clock();
	time_Difference = (long)time_End - time_Start;
	printf("final time difference = %ld\n", time_Difference);
	printf("final time difference in sec  = %lf\n", (double)time_Difference/CLOCKS_PER_SEC);

	return EXIT_SUCCESS;
}
