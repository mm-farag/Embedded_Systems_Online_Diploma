/*
 ============================================================================
 Name        : unit2_Lesson5_Extern_Must_Be_Defined_One_Time.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


extern int yyy = 50;  //extern can only initialized globally.
int main(void)
{
//	extern int yyy = 50 //error
	printf("%d", yyy);
	return EXIT_SUCCESS;
}

int yyy;


