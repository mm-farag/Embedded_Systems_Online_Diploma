/*
 ============================================================================
 Name        : unit2_Lesson5_Static_Var_With_Func.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void function_Print_Xy(void)
{
	static int x = 1;
	int y = 1;
	printf("x = %d, y = %d\n", x++, y++);

}




int main(void)
{
	int i = 0;
	for(; i<10; i++)
	{
		function_Print_Xy();
	}

	return EXIT_SUCCESS;
}
