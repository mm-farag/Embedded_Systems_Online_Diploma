/*
 * unit2_Lesson3_Slide22_Complex_Number.c
 *
 *  Created on: Feb 1, 2021
 *      Author: Muhammad Mustafa
 */



#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


struct SComplex
{
	double m_Real_Part;
	double m_Imaginary_Part;
};



struct SComplex read_Imaginary_Number(char complex_Name[]);
struct SComplex add_Complex(struct SComplex a, struct SComplex b);
void print_Complex(char struct_Name[], struct SComplex temp);




void main()
{
	struct SComplex x, y, z;
	x = read_Imaginary_Number("x");
	y = read_Imaginary_Number("y");
	z = add_Complex(x, y);
	print_Complex("x", x);
	print_Complex("y", y);
	print_Complex("z", z);

}


struct SComplex read_Imaginary_Number(char complex_Name[])
{
	struct SComplex temp_Imaginary;
	printf("Enter \"%s\" imaginary number ex(3 , 3.6)\n", complex_Name);
	fflush(stdin); fflush(stdout);
	scanf("%lf %lf", &temp_Imaginary.m_Real_Part, &temp_Imaginary.m_Imaginary_Part);
	return temp_Imaginary;

}

struct SComplex add_Complex(struct SComplex a, struct SComplex b)
{
	struct SComplex temp;
	temp.m_Real_Part = a.m_Real_Part + b.m_Real_Part;
	temp.m_Imaginary_Part = a.m_Imaginary_Part + b.m_Imaginary_Part;
	return temp;
}

void print_Complex(char struct_Name[], struct SComplex temp)
{

	printf("complex %s : real = %lf, imaginary = %lf\n", struct_Name, temp.m_Real_Part, temp.m_Imaginary_Part);
}
