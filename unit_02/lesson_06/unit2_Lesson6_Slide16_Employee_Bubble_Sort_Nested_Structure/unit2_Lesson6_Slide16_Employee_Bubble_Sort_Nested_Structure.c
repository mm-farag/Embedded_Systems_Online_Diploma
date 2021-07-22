/*
 * unit2_Lesson6_Slide16_Employee_Bubble_Sort_Nested_Structure.c
 *
 *  Created on: Feb 1, 2021
 *      Author: Muhammad Mustafa
 */



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>



#define EMPLOYEE_NUMBER 5 // Ascending


struct SDate
{
	unsigned int day;
	unsigned int month;
	unsigned int year;

};


struct SEmployee
{
	char name[100];
	unsigned int salary;
	struct SDate date;

}emp[EMPLOYEE_NUMBER];



void main(void) //main function
{

	int i = 0, j = 0;
	char y;
	char employee_First_Name[50];
	char employee_Second_Name[50];

	struct SEmployee temp_Emp;


	do
	{
		if(i == EMPLOYEE_NUMBER) break;

		fflush(stdin); fflush(stdout);
		printf("Enter Employee first name: ");
		fflush(stdin); fflush(stdout);
		scanf("%s", employee_First_Name);


		printf("Enter Employee second name: ");
		fflush(stdin); fflush(stdout);
		scanf("%s", employee_Second_Name);


		strcpy(emp[i].name, employee_First_Name);
		strcat(emp[i].name, " ");
		strcat(emp[i].name, employee_Second_Name);

		printf("Enter employee Date: (dd-mm-year): ");
		fflush(stdin); fflush(stdout);
		scanf("%u%u%u", &emp[i].date.day, &emp[i].date.month, &emp[i].date.year);

		printf("Enter employee salary: ");
		fflush(stdin); fflush(stdout);
		scanf("%u", &emp[i].salary);


		fflush(stdin); fflush(stdout);

		printf("Enter y to enter a new employee data\n");
		fflush(stdin); fflush(stdout);
		y = getchar();
		//		printf("%c\n", y);
		//		printf("Press y\n");
		i++;
	}while(y =='y');


	for(j = 0; j < EMPLOYEE_NUMBER - 1; j++) //bubble sorting
		for(i = 0; i < EMPLOYEE_NUMBER - 1; i++)
		{
			if(
					(emp[i].date.year < emp[i+1].date.year)
					||
					(emp[i].date.year == emp[i+1].date.year && emp[i].date.month < emp[i+1].date.month)
					||
					(emp[i].date.year == emp[i+1].date.year && emp[i].date.month == emp[i+1].date.month && emp[i].date.day < emp[i+1].date.day))
			{
				temp_Emp = emp[i];
				emp[i] = emp[i+1];
				emp[i+1] = temp_Emp;
			}

		}



	printf("%s%50s%50s", "Emplyee name", "Employee Birthday", "Employee Salary\n");
	for(i=0; i<EMPLOYEE_NUMBER; i++)
	{

		printf("%-45s%-2u/%-2u/%-45u%u\n", emp[i].name, emp[i].date.day, emp[i].date.month,emp[i].date.year, emp[i].salary);

	}
}
