/*
 ============================================================================
 Name        : unit2_Lesson6_Slide83_Arithmatic_Using_Union.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

enum NUMOption_Type
{
	int_Option,
	float_Option,
	Double_Option
};

union UNUValues_Type
{
	int int_Value;
	float float_Value;
	double double_Value;

};



union UNUValues_Type add_Function(union UNUValues_Type a, union UNUValues_Type b, enum NUMOption_Type option )
{
	union UNUValues_Type r;
	switch(option)
	{
	case int_Option:
		r.int_Value = a.int_Value  + b.int_Value;
		break;

	case float_Option:
		r.float_Value = a.float_Value + b.float_Value;
		break;
	case Double_Option:
		r.double_Value = a.double_Value + b.double_Value;
		break;
	}
	return r;
}


int main(void)
{
	union UNUValues_Type v1, v2, v3;
	enum NUMOption_Type;
	printf("the sizeof union is: %d\n", sizeof(union UNUValues_Type));


	v1.int_Value = 5;
	v2.int_Value = 6;
	v3 = add_Function(v1, v2, int_Option);
	printf("int: %d + %d = %d\n", v1.int_Value, v2.int_Value, v3.int_Value);

	v1.float_Value = 5.5;
	v2.float_Value = 6.5;
	v3 = add_Function(v1, v2, float_Option);
	printf("float: %f + %f = %f\n", v1.float_Value, v2.float_Value, v3.float_Value);

	v1.double_Value = 5.5;
	v2.double_Value = 6.5;
	v3 = add_Function(v1, v2, Double_Option);
	printf("double: %lf + %lf = %lf\n", v1.double_Value, v2.double_Value, v3.double_Value);


	return EXIT_SUCCESS;
}
