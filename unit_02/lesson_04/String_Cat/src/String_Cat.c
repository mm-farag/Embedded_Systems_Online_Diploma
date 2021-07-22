/*
 ============================================================================
 Name        : String_Cat.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void function_String_Cat(char dist[], char source[]);

int main(void)
{
    char source[50] = "Mousa";
    char distination[50] ="Linda";
    char space[] = " ";
    /*strcat(distination, " ");
    strcat(distination, source);*/
    function_String_Cat(distination, space);
    function_String_Cat(distination, source);


    printf("%s", distination);
	return EXIT_SUCCESS;
}


void function_String_Cat(char dist[], char source[])
{
    int i = 0;
    int j = 0;
    while(dist[i] != '\0')
    {
        i++;
        //dist++;
    }


    while(source[j] != '\0')
    {

        dist[i] = source[j];
        i++;
        j++;
    }
    source[j] = '\0';
}
