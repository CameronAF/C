#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

//Write a small program that calculates the sum and the difference of two integers with three user-defined functions:

//takes two integer arguments and returns the sum of the two arguments
int CalculateSum(int num1, int num2);

//takes two integer arguments and returns the difference of the two arguments
int CalculateDifference(int num1, int num2);

//takes two integer arguments and two integer pointer arguments
//1. calculate the sum and stores the result in sumptr
//2. calculate the difference and store the result in diffPtr
void CalculateBoth(int num1, int num2, int*sumPtr, int *diffPtr);


//Call all three functions from main.
//Print the results in both the function definitions (value at) and back in main.
int main()
{
	// declare variables
	int num1;
	int num2;
	int sum;
	int diff;
	// user enters numbers
	printf("This program will calculates the sum and the difference of two integers.\n");
	printf("Please ENTER the 1st integer.\n");
	scanf(" %d", &num1);
	printf("Please ENTER the 2nd integer.\n");
	scanf(" %d", &num2);
	// calculate sum and difference, set address
	CalculateBoth(num1, num2, &sum, &diff);
	printf("the sum of %d and %d is %d\n", num1, num2, sum);
	printf("the difference of %d and %d is %d\n", num1, num2, diff);
	// calculate sum and difference return value
	sum=CalculateSum(num1, num2);
	diff=CalculateDifference(num1, num2); 
	printf("the sum of %d and %d is %d\n", num1, num2, sum);
	printf("the difference of %d and %d is %d\n", num1, num2, diff);
	return 0;
}

//takes two integer arguments and two integer pointer arguments
//1. calculate the sum and stores the result in sumptr
//2. calculate the difference and store the result in diffPtr
void CalculateBoth(int num1, int num2, int *sumPtr, int *diffPtr)
{
	*sumPtr=CalculateSum(num1, num2);
	printf("the sum of %d and %d is %d\n", num1, num2, *sumPtr);
	*diffPtr=CalculateDifference(num1, num2);
	printf("the difference of %d and %d is %d\n", num1, num2, *diffPtr);
	return;
}

//takes two integer arguments and returns the sum of the two arguments
int CalculateSum(int num1, int num2)
{
	int sum;
	sum=num1+num2;
	printf("the sum of %d and %d is %d\n", num1, num2, sum);
	return sum;
}

//takes two integer arguments and returns the difference of the two arguments
int CalculateDifference(int num1, int num2)
{
	int diff;
	diff=num1-num2;
	printf("the difference of %d and %d is %d\n", num1, num2, diff);
	return diff;
}