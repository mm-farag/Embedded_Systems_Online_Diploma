/*
 * unit2_Lesson6_Slide33_Bit_Fields.c
 *
 *  Created on: Feb 1, 2021
 *      Author: Muhammad Mustafa
 */



/**/



#include<stdio.h>
struct register_Name_Type
{
	unsigned char delta_Cts:1;
	unsigned char delta_Dsr:1;
	unsigned char tr_Edge:1;
	unsigned char delta_Rec:1;
	unsigned char cts:1;
	unsigned char dsr:1;
	unsigned char ring:1;
	unsigned char rec_Line:1;
}register_Name;

/*
 * unsigned char
 * :1 dont forget that
 *
 */


void main()
{

	unsigned char x = 0b00101010;


	register_Name.delta_Cts=   (x&1<<0)>>0;
	register_Name.delta_Dsr=   (x&1<<1)>>1;
	register_Name.tr_Edge=     (x&1<<2)>>2;
	register_Name.delta_Rec =  (x&1<<3)>>3;
	register_Name.cts =        (x&1<<4)>>4;
	register_Name.dsr =        (x&1<<5)>>5;
	register_Name.ring =       (x&1<<6)>>6;
	register_Name.rec_Line =   (x&1<<7)>>7;

	printf("0b%u", register_Name.rec_Line);
	printf("%u", register_Name.ring);
	printf("%u", register_Name.dsr);
	printf("%u", register_Name.cts);
	printf("%u", register_Name.delta_Rec);
	printf("%u", register_Name.tr_Edge);
	printf("%u", register_Name.delta_Dsr);
	printf("%u", register_Name.delta_Cts);
}


