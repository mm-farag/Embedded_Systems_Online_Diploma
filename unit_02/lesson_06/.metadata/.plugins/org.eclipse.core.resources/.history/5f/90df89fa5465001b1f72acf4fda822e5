/*
 * unit2_Lesson3_Slide16_Employee_Bubble_Sort_Nested_Structure_Using_Function.c
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
	struct SDate m_Birth_Date;
	struct SDate m_Graduation_Date;

}emp[EMPLOYEE_NUMBER];



struct SDate read_Date(char date_Name[])
{
	struct SDate date;
	printf("read_Date function - Enter employee %s (day/month/year): ", date_Name);
	fflush(stdin); fflush(stdout);
	scanf("%u%u%u", &date.day, &date.month, &date.year );
	return date;
}


void read_Employee(void)
{
	int i = 0;
	char y;
	char employee_First_Name[50];
	char employee_Second_Name[50];
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

		//			printf("Enter employee Date: (dd-mm-year): ");
		//			fflush(stdin); fflush(stdout);
		//			scanf("%u%u%u", &emp[i].date.day, &emp[i].date.month, &emp[i].date.year);

		emp[i].m_Birth_Date = read_Date("Birth Date");
		emp[i].m_Graduation_Date = read_Date("Graduation Date");

		///

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

}


void sort_Employees(void)
{
	int i, j;
	struct SEmployee temp_Emp;
	for(j = 0; j < EMPLOYEE_NUMBER - 1; j++) //bubble sorting
		for(i = 0; i < EMPLOYEE_NUMBER - 1; i++)
		{
			if(
					(emp[i].m_Birth_Date.year < emp[i+1].m_Birth_Date.year)
					||
					(emp[i].m_Birth_Date.year == emp[i+1].m_Birth_Date.year && emp[i].m_Birth_Date.month < emp[i+1].m_Birth_Date.month)
					||
					(emp[i].m_Birth_Date.year == emp[i+1].m_Birth_Date.year && emp[i].m_Birth_Date.month == emp[i+1].m_Birth_Date.month && emp[i].m_Birth_Date.day < emp[i+1].m_Birth_Date.day))
			{
				temp_Emp = emp[i];
				emp[i] = emp[i+1];
				emp[i+1] = temp_Emp;
			}

		}

}


void print_Employees(void)
{
	int i;
	printf("%s%50s%50s", "Emplyee name", "Employee Birthday", "Employee Salary\n");
	for(i=0; i<EMPLOYEE_NUMBER; i++)
	{

		printf("%-45s%-2u/%-2u/%-45u%u\n", emp[i].name, emp[i].m_Birth_Date.day, emp[i].m_Birth_Date.month,emp[i].m_Birth_Date.year, emp[i].salary);

	}

}



void main(void) //main function
{
	read_Employee();
	sort_Employees();
	print_Employees();
}

