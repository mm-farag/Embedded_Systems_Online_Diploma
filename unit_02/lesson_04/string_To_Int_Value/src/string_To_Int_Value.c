/*
 ============================================================================
 Name        : string_To_Int_Value.c
 Author      : Mohamed Mustafa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int FUNC_Asci_To_Int(char text_Number[]);
int main(void)
{
     char string_Number[50];
     int x;
     fflush(stdin); fflush(stdout);
     scanf("%s", string_Number);
     x = FUNC_Asci_To_Int(string_Number);
     printf("the deduced int is: %d\n", x);
     return EXIT_SUCCESS;
}


int FUNC_Asci_To_Int(char text_Number[])
{
    int i = 0;
    int sum = 0;
    int digit;
    while(text_Number[i] != '\0'
          &&
          (text_Number[i] >= 48 && text_Number[i] <= 57))
    {
        digit= text_Number[i]-'0';
        sum = (sum*10) + digit;

        i++;
    }
    return sum;
}
