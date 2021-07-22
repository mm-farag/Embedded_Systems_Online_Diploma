/*
 ============================================================================
 Name        : memory_Dumping.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>




struct SDataSet
{
	unsigned char data1;
	unsigned int data2;
	unsigned char data3;
	unsigned short data4;
};

struct SDataSet data1;

void func_Memory_Dumping(char* pDump, int size)
{
	int i;
	for(i=0; i<size; i++, pDump++) // best case if u will use pDump many times
	{
//		printf("address:%p		%x		%d\n", pDump, (unsigned char)*pDump++, (unsigned char)*pDump++); // casting to see the data in the form of the unsigned char
		printf("address: %p			value in hex(unsigned char): %x\n", pDump, (unsigned char)*pDump); // casting to see the data in the form of the unsigned char
	}

}


int main(void)
{
	float test = 1;

	void* voidPointer_p;
	//<>* <>
	struct SDataSet*	P_struct = &data1; // pointer to structure




	data1.data1 = 0xFA;
	data1.data2 = 0xFFAA0041;
	data1.data3 = 0x11;
	data1.data4 = 0x0808;

//	printf("%d\n", sizeof(data1));

	func_Memory_Dumping((char*)&data1, sizeof(data1));
	printf("+++++++++++++++++++++++++\n");



	P_struct->data1 = 0xFB;

	func_Memory_Dumping(&data1, sizeof(data1));

	printf("-----------------------------------");
	printf("\n%x     %x", data1.data1, P_struct->data1);
	printf("-----------------------------------\n");
	voidPointer_p = &test;
//	*(int*)voidPointer_p = 5;
	*(float*)voidPointer_p = 3;
	printf("test is: %d\n", (int)test);


	return EXIT_SUCCESS;
}
