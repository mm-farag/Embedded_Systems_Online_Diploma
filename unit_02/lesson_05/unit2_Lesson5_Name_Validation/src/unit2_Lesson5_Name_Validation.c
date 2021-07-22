/*
 ============================================================================
 Name        : unit2_Lesson5_Name_Validation.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum NUM_validate_Type
{
	found,
	not_Found
};


enum NUM_validate_Type function_Name_Validation(char data_Base[][20], char user_To_Validate[])
{
	int i;
//	enum NUM_Validate_Type Validate;
//	for(i=0; i<sizeof(data_Base) / sizeof(data_Base[0]); i++)
	for(i=0; i<5; i++)
	{
		if(strcasecmp(data_Base[i], user_To_Validate) == 0)
		{
			return found;
		}
		else
			return not_Found;
	}
}


int main(void)
{
	char names[5][20]={"Mohamed", "Ahmed", "magdy", "Linda", "Yassine"};
//	int i;
	char user[20];
//	enum NUM_Validate_Type validate;
	printf("Please, enter your name\n");
	fflush(stdin); fflush(stdout);
	scanf("%s", user);
	if(function_Name_Validation(names, user) == found)
	{
		printf("Your name is found, enta mennena\n");
	}
	else
		printf("Enta msh mennena\n");

	printf("Finished..\n ");
	return EXIT_SUCCESS;
}
