/*
 ============================================================================
 Name        : unit2_Lesson5_Storage_Class_Register_With_Local.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


//register int x; //error as register variable is restored inside the GP Registers into processor
int main(void)
{
	register int x = 0;
	int i;
	for(i=0; i<10; i++)
	{
		x = x + i;
		printf("%d\n", x);
	}
	return EXIT_SUCCESS;
}
