/*
 ============================================================================
 Name        : string_Scanning.c
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
    char name[50];
   // scanf("%s", name); // space problem
    gets(name);
    printf("%s", name);
	return EXIT_SUCCESS;
}
