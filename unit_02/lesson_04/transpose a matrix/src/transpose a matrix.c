/*
 ============================================================================
 Name        : transpose.c
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

	int array [4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	int i,j;
	int container;
	for(i = 0; i< sizeof(array)/ sizeof(array[0]); i++)
        {
            for(j = 0; j < sizeof(array[0]) / sizeof(int); j++)
            {
                printf("%d\t", array[i][j]);
            }
            printf("\n");
        }
        printf("============================\n");

        for(i = 0; i< sizeof(array)/ sizeof(array[0]); i++)
        {
            for(j = i; j < sizeof(array[0]) / sizeof(int); j++)
            {
                container = array[i][j];
                array[i][j] = array[j][i];
                array[j][i] = container;
            }
        }


        for(i = 0; i< sizeof(array)/ sizeof(array[0]); i++)
        {
            for(j = 0; j < sizeof(array[0]) / sizeof(int); j++)
            {
                printf("%d\t", array[i][j]);
            }
            printf("\n");
        }

	return EXIT_SUCCESS;
}
