/*
 ============================================================================
 Name        : test.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum ENUM_validation
{
	found, not_Found
};

enum ENUM_validation function_Name_Validation(char name[][20], int name_Size, char user[])
{
	int i;
	printf("searching..\n");
	for(i=0; i<name_Size; i++)
	{

		if(!strcasecmp(name[i], user))
		{
			return found;
		}
	}
	return not_Found;
}


int main(void)
{
	int flag = 0;
	char user[20] = {0};
	char name[][20] = {"Yassine", "Ahmed", "Linda"};
	while(1)
	{
		if(flag == 0)
		{
			printf("Please enter your name to check\n");
			flag = 1;
		}
		else
		{
			printf("enter another name: \n");
		}

		fflush(stdin); fflush(stdout);
		gets(user);

		if(function_Name_Validation(name, 3, user) == found)
			printf("%s is found\n", user);
		else
			printf("Sorry\n");
	}


	return EXIT_SUCCESS;
}
