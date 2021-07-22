/*
 ============================================================================
 Name        : unit2_Lesson5_Change_good_To_Food.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void function_Change_Ascii(char string[])
{
	string[0]--;
}

int main(void)
{
	char array[10] = "good";
	function_Change_Ascii(array);
	printf("%s\n", array);

	return EXIT_SUCCESS;
}
