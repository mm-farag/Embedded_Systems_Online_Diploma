/*
 ============================================================================
 Name        : unit2_Lesson7_Function_Factory_Macros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define FUNC(FUNCTION_NAME, SCALE) int func_#FUNCTION_NAME(int number){return number * SCALE}

FUNC(Double, 2)
FUNC(Quadruple, 4)



int main(void)
{
	printf("the double of the 2 is: \n", func_Double(2));
	printf("the quadruple of the 2 is: \n", func_Quadruple(2));
	return EXIT_SUCCESS;
}
