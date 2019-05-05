#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

// This project is just an example on how to use printf and scanf

int main()
{
	// declare variables
	int num;
	char ltr;	
	// user inputs number
	printf("Hello my name is Cameron \n");
	printf("HURRY!! ENTER A NUMBER!!\n\n");
	scanf(" %d", &num);
	// user inputs letter
	printf("...only stupid people pick %d >.>\n\n", num);
	printf("lets try something else.\nEnter a letter this time.\n\n");
	scanf(" %c", &ltr);
	// end program
	printf("WOW, %c?\nyour hopeless.\n", ltr);
	printf("Goodbye\n\n");
	return 0;
}