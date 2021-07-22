/*
 * unit2_Lesson6_Slide3_c_Example_Without_Structure.c
 *
 *  Created on: Jan 28, 2021
 *      Author: Muhammad Mustafa
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define EMPLOYEE_NUMBER 1


#define FLUSH() do{\
		+		fflush(stdin);\
		fflush(stdout);\
}while(0);


void main()
{
	char first_Name[50], second_Name[50];
	char names[EMPLOYEE_NUMBER][100];
	unsigned char count = 0, i = 0, j = 0;
	unsigned int birth_Date_Day[EMPLOYEE_NUMBER] = {0};
	unsigned int birth_Date_Month[EMPLOYEE_NUMBER] = {0};
	unsigned int birth_Date_Year[EMPLOYEE_NUMBER] = {0};
	int salary[EMPLOYEE_NUMBER];


	char temp_Name[100];
	unsigned int temp_Birth_Date_Day;
	unsigned int temp_Birth_Date_Month;
	unsigned int temp_Birth_Date_Year;

	int temp_Salary;

	do
	{

		if(count == EMPLOYEE_NUMBER)
		{
			fflush(stdin); fflush(stdout);
			printf("================================================\nYOU EXEEDED THE LIMITATIONS OF EMPLOYEES\n================================================\n");
			break;
		}
		printf("Enter employee first name: ");
		fflush(stdin); fflush(stdout);
		scanf("%s", first_Name);

		printf("Enter employee second name: ");
		fflush(stdin); fflush(stdout);
		scanf("%s", second_Name);
		strcpy(names[count], first_Name);
		strcat(names[count], " ");
		strcat(names[count], second_Name);

		printf("Enter employee birthdate (day/month/year) example: \"23/3/1997\": ");
		fflush(stdin); fflush(stdout);
		scanf("%u\%u\%u", &birth_Date_Day[count], &birth_Date_Month[count], &birth_Date_Year[count]);
		printf("Enter employee salary: ");
		fflush(stdin); fflush(stdout);
		scanf("%d", &salary[count]);
		count++;
		fflush(stdin); fflush(stdout);
		//		FLUSH;
		printf("Press 'y' if you want to add more: ");
		fflush(stdin); fflush(stdout);
	}while(getchar() == 'y');
	//	/*bubble sorting*/


	for(j = 0; j < EMPLOYEE_NUMBER -1; j++)
	{
		for(i = 0; i < EMPLOYEE_NUMBER -1; i++)
		{
			if(
					(birth_Date_Year[i+1] < birth_Date_Year[i])
					||
					(birth_Date_Year[i+1] == birth_Date_Year[i] && birth_Date_Month[i+1] < birth_Date_Month[i])
					||
					(birth_Date_Year[i+1] == birth_Date_Year[i] && birth_Date_Month[i+1] == birth_Date_Month[i] && birth_Date_Day[i+1] < birth_Date_Day[i]))
			{
				temp_Birth_Date_Day = birth_Date_Day[i];
				birth_Date_Day[i] = birth_Date_Day[i+1];
				birth_Date_Day[i+1] = temp_Birth_Date_Day;


				temp_Birth_Date_Month = birth_Date_Month[i];
				birth_Date_Month[i] = birth_Date_Month[i+1];
				birth_Date_Month[i+1] = temp_Birth_Date_Month;


				temp_Birth_Date_Year = birth_Date_Year[i];
				birth_Date_Year[i] = birth_Date_Year[i+1];
				birth_Date_Year[i+1] = temp_Birth_Date_Year;

				temp_Salary = salary[i];
				salary[i] = salary[i+1];
				salary[i+1] = temp_Salary;

				strcpy(temp_Name, names[i]);
				strcpy(names[i], names[i+1]);
				strcpy(names[i+1], temp_Name);



			}
		}
	}

	printf("%s%50s%50s\n", "name", "Birthday", "Salary");
	for(i=0; i<EMPLOYEE_NUMBER; i++)
	{

		printf("%-45s%-2u/%-2u/%-45u%d\n", names[i], birth_Date_Day[i], birth_Date_Month[i], birth_Date_Year[i], salary[i]);

	}

}
