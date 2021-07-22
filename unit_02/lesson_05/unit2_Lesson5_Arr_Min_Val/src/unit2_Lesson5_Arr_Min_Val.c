/*
 ============================================================================
 Name        : unit2_Lesson5_Arr_Min_Val.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int funcion_Min_Arr_Val(int x[], int size)
{
	int i = 0;
	int min = x[0];
	for(i=1; i<size; i++)
	{
		if(x[i] < min )
			min = x[i];
	}
	return min;
}

int main(void)
{
	int arr1[] = {10 , 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int arr2[] = {11, 12,13, 14, 15, 16, 17, 18, 19, 10};

	printf("the min of arr1 is: %d\n",funcion_Min_Arr_Val(arr1, 10) );
	printf("the min of arr2 is: %d\n",funcion_Min_Arr_Val(arr2, 10) );
	return EXIT_SUCCESS;
}
