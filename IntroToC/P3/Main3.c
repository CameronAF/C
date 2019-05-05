#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

// encourage the use of user-defined functions
// (calculates  different sales tax based on an item price)

//1. Ask the user to enter the price of an item.
//2. Get the item price from the user.
//3. Calculate the sales tax of the item:
//		- 7% if the item costs less than $200.
//		- 5% if the item costs $200 or more.
//4. Display the original item price and sales tax amount onto the screen.
//5. Calculate new cost of the item with the sales tax.
//6. Display the total price of the item onto the screen.

double CalcSalesTax(double item);
double TotalPrice(double item, double tax);

int main()
{
	// declare variables
	double item;
	double tax;
	double tot;
	// get price of an item
	printf("I am going to help you calaculate sales tax of an item.\n");
	printf("Please enter the price of the item.\n");
	scanf(" %lf", &item);	
	// calculate tax
	tax = CalcSalesTax(item);
	printf("For an item costing you $ %.2f the tax is $ %.2f.\n", item, tax);
	// calculate total price
	tot = TotalPrice(item, tax);
	printf("In total you will spend $ %.2f\n", tot);
	return 0;
}

// Calculate the sales tax of the item:
//  - 7% if the item costs less than $200.
//	- 5% if the item costs $200 or more.
double CalcSalesTax (double item)
{
	double tax;
	if(item<200)
	{
		tax = item*.07;
	}
	else
	{
		tax = item*.05;
	}
	return tax;
}

// calculate total price
double TotalPrice(double item, double tax)
{
	double tot;
	tot = item + tax;
	return tot;
}