#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

// This project will calcuate the area of a rectangle and the area of a circle
// This Project is to demonstrate the use of methods

// gets an integer from the user and returns it 
// make 3 calls to this function: 
//  - get the length of the rectangle from the user and return it to main 
//  - get the width of the rectangle from the user and return it to main 
//  - get the radius of the circle from the user and return it to main
int GetNum(void);

// takes two arguments, the length and width of the rectangle and returns the area 
int CalculateAreaR(int length1, int width1);

// takes one argument, the radius of the circle and returns the area 
double CalculateAreaC(int radius1);

int main()
{
	// declare variables
    int length;
    int width;
    int areaR;
    int radius;
    double areaC;
	// get numbers
    length = GetNum();
	width = GetNum();
	radius = GetNum();
	// calculate area of a rectangle
	areaR = CalculateAreaR(length, width);
	printf ("A rectangle with length %d and width %d has an area of %d.\n", length, width, areaR);
	// calculate area of a circle
	areaC = CalculateAreaC(radius);
	printf ("A circle with a radius %d has an area of %f.\n", radius, areaC);
	return;
}

// get a number from the user
int GetNum(void)
{
	int num;
	printf ("Please enter the Integer.\n");
    scanf (" %d", &num);
	return num;
}
 
// caculate the area of a rectangle
int CalculateAreaR(int length1, int width1)
{
	int areaR1;
	areaR1 = length1*width1;
    return areaR1;
}
 
// calculate the area of a circle
double CalculateAreaC(int radius1)
{
	double areaC1;
	areaC1 = radius1*radius1*3.14;
	return areaC1;
}