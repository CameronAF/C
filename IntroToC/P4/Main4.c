#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

// This project will demonstrate the use of for loops, while loops, and do while loops
// User will input a number and 3 different text will be printed that many times

int main ()
{
	// declare variables
	int num;
	int i;
	// user inputs a number
	printf("Enter a number from 1 to 50\n");
	scanf(" %d", &num);
	// For loop
	for(i=0; i<num; i++)
	{
		printf("Programming is fun\n");
	}
	// While loop
	i=0;
	while(i<num)
	{
		printf("sports are fun\n");
		i++;
	}
	// Do While loop
	i=0;
	do{
		printf("FAU is awesome\n");
		i++;
	}while(i<num);
	return 0;
}