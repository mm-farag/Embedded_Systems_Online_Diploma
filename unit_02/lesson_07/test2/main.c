/*
 * main.c
 *
 *  Created on: Feb 19, 2021
 *      Author: Muhammad Mustafa
 */

#include<stdio.h>
#include<stdlib.h>


#define myPrint(x, ...)      x##_VA_ARGS__;


#define Dprintf(...) printf(#__VA_ARGS__)

void main(void)
{

	Dprintf("DEC(7) = %d\n", DEC(7) );
	Dprintf();

}


