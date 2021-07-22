/*
 ============================================================================
 Name        : difference_Between_Variable_and_Pointer.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{	long long int rand_address = 0x00000000FFFFAAAA; //8bytes 16 hexadecimal digits
	char *P_addr = 0x00000000FFFFAAAA; // howa keda shayef n da int 3ady gowa poiter elly mafrod yshil address! bs still hyshta8al mn 8ir moshkela

	printf("rand_address = %lld \n", rand_address);
	printf("rand_address = %llx \n", rand_address);

	return EXIT_SUCCESS;
}
