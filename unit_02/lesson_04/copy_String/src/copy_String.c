/*
 ============================================================================
 Name        : copy_String.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define pointer 2
#define array 1
#define z array

function_String_Copy(char source[], char distination[]);

int main(void)
{
    char distination[50];
    char source[100] = "Linda Mousa Saleh";
    function_String_Copy(distination, source);
    printf("%s\n", distination);

	return EXIT_SUCCESS;
}



function_String_Copy(char distination[], char source[])
{
    #if z == array
    printf("array mode is enabled\n");

    int i = 0;
    for(;source[i] != '\0'; i++)
    {
        distination[i] = source[i];
    }
    distination[i] = '\0';

    #elif z == pointer
    printf("pointer mode is enabled\n");

    int i;
    for( i = 0; *source != '\0'; source++, distination++)
    {
        *distination = *source;

    }
    *source = '\0';
    #endif // z

}
