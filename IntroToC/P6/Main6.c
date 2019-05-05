#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Write a small program that fills an array of doubles with user input, prints the doubles on the screen in a column,
//Adds up all the doubles in the array and prints the sum onto the screen.
//- Declare an array of doubles of size 20.
//- Ask the user how many doubles to enter <= 20.
//- Use a loop to read the doubles into the array from the user.
//- Use a loop to print the array onto the screen in a column.
//- Use a loop to add up all the items in the array and store the sum
//- print the sum onto the screen

#define SIZE 20

// user enters numbers to fill an array
void DoubleArr(double arr[], int num);

// Array getts printed to user
void PrintArr(double arr[], int num);

// Numbers in array are summed and printed to the user
void AddArr(double arr[], int num);

int main()
{
	// declare variables
	double arr[SIZE];
	int num;
	// user defines array length
	printf("How many numbers are you adding togeather?\n");
	printf("(Maximum numbers you can enter is 20)\n");
	scanf(" %d", &num);
	// user enters numbers to fill an array
	DoubleArr(arr, num);
	// Array getts printed to user
	PrintArr(arr, num);
	// Numbers in array are summed and printed to the user
	AddArr(arr, num);
	return;
}

void DoubleArr(double arr[], int num)
{
	int i;
	for(i=0; i<num; i++)
	{
		printf("Enter number %d out %d\n", i+1, num);
		scanf(" %lf", &arr[i]);
	}
	return;
}

void PrintArr(double arr[], int num)
{
	int i;
	for(i=0; i<num; i++)
	{
		printf(" %f\n", arr[i]);
	}
	return;
}

void AddArr(double arr[], int num)
{
	int i;
	double sum=0;
	for(i=0; i<num; i++)
	{
		sum=sum+arr[i];
	}
	printf("sum it %f\n", sum);
	return;
}