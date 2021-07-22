/*
 ============================================================================
 Name        : how.c
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
	int degree [4][6] = {
						{36, 28, 76, 47, 82, 33},
						{75, 49, 38, 98, 59, 83},
						{82, 65, 10, 21, 86, 22},
						{25, 63, 65, 76, 37, 21}};
	int x = 9;
	int y;

	int i, j, counter;

	for(counter = 0, i = 0, j = 0; counter < 24; counter++)
	{

		printf("%d \t", degree[i][j]);
		j++;
		if( j % 6 == 0 )
		{

		printf("\n");
			i+1;
		}
	}

	printf("i=%d , j=%d, counter=%d\n======================\n", i, j, counter);

	//assign x value to the item {2, 3}

	degree[2][3] = x;
	y = degree[2][3];

	for(counter = 0, i = 0, j = 0; counter < 24; counter++)
	{

		printf("%d \t", degree[i][j]);
		j++;
		if( j % 6 == 0 )
		{

		printf("\n");
			i+1;
		}
	}
	printf("==========================\n");

	//scan item {1,4} from user


	scanf("%d", &degree[1][4]);

	printf("===========================\n");

	for(i = 0; i< sizeof(degree) / sizeof(degree[0]); i++)
	{
	    for(j = 0; j <sizeof(degree[0])/sizeof(int); j++)
        {
            printf("%d \t", degree[i][j]);
        }
        printf("\n");
	}
	printf("============================\n");

	//print item {1, 4}
	printf("item {1, 4} is: %d\n", degree[1][4]);


	printf("size of degree = %d\nsize of degree[0] = %d\n", sizeof(degree), sizeof(degree[0]));

	return EXIT_SUCCESS;
}
