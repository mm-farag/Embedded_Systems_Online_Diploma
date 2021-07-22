/*
 ============================================================================
 Name        : printing.c
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
    char AOString[][20]= {"Ahmed Ali", "Mahmoud Samy", "Linda Mousa", "Mohamed Mustafa", "Nader Zohdi"};
    char i;
    for(i=0; i<sizeof(AOString) / sizeof(AOString[0]); i++)
    {
        printf("%s\n", AOString[i]);
    }
	return EXIT_SUCCESS;
}
