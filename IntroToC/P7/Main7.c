#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>
#include <stdio.h>

// This porject demonstrates the use of a structure
// struct book contains title, ISBN, number of pages, and cost
// instance of book gets created by user input or copied by already created instance

#define SIZE 20

typedef struct{
 char title[SIZE];
 char ISBN[SIZE];
 int numPages;
 double cost;
}book;

//Function Prototypes

// fills the data fields of a book instance
//returns the filled book 
book FillBook();

//fills the data fields of a book instance
//by reference using a pointer to a book
void FillBookPtr(book *bookptr);

//fills an array of books
void FillBookArray(book arrayB[], int *size);

//displays one book
void DisplayBook(book anyBook);

int main()
{
	//Declare variables
	book myBook, myBook1, myBook2;
	book manyBooks[SIZE];
	int bSize;
	int i;

	//Fill structures with a function
	myBook = FillBook();
	myBook1 = FillBook();

	//print using display function
	printf("\n---------Display myBook\n");
	DisplayBook(myBook);
	printf("\n---------Display myBook1\n");
	DisplayBook(myBook1);

	//Fill structure using pointers and dispay it
	FillBookPtr(&myBook2);
	printf("\n---------Display myBook2\n");
	DisplayBook(myBook2);

	//Fill the array with the function
	printf("\n---------Fill array manyBooks\n");
	FillBookArray(manyBooks, &bSize);

	//display an array of books
	printf("\n---------Display array manyBooks\n");
	for(i=0;i<bSize; i++)
	{
		DisplayBook(manyBooks[i]);
	}

	return 0;
}

//Function Definitions

// fills the data fields of a book instance
//returns the filled book
book FillBook()
{
	//Declare local variables
	book tempB;
	//prompt and get information
	printf("\nplease enter the title of your book:  ");
	scanf("%s", tempB.title);
	//print to check
	printf("title:  %s\n", tempB.title);

	//prompt and get information
	printf("\nplease enter the ISBN of your book:  ");
	scanf("%s", tempB.ISBN);
	//print to check
	printf("ISBN:  %s\n", tempB.ISBN);

	//prompt and get information
	printf("\nplease enter the number of pages of your book:  ");
	scanf("%d", &tempB.numPages);
	printf("Number of Pages:  %d\n", tempB.numPages);
	return tempB;
}

//displays one book
void DisplayBook(book anyBook)
{
	printf("\n\nBook:  %s\n", anyBook.title);
	printf("ISBN:  %s\n", anyBook.ISBN);
	printf("Number of Pages:  %d\n", anyBook.numPages);
}

//fills the data fields of a book instance
//by reference using a pointer to a book
void FillBookPtr(book *bookptr)
{
	//prompt and get information
	printf("\nplease enter the title of your book:  ");
	scanf("%s", (*bookptr).title);

	//prompt and get information
	printf("\nplease enter the ISBN of your book:  ");
	scanf("%s", bookptr->ISBN);

	//prompt and get information
	printf("\nplease enter the number of pages of your book:  ");
	scanf("%d", &(*bookptr).numPages);
}

//fills an array of books
void FillBookArray(book arrayB[], int *size)
{
	int i;
	//prompt the user
	printf("\nenter the number of Books:  ");
	scanf("%d", size);

	//print to check
	printf("size:  %d\n", *size);

	for (i=0; i < *size; i++)
	{
		printf("enter title:  ");
		scanf("%s", arrayB[i].title);

		printf("enter ISBN:  ");
		scanf("%s", arrayB[i].ISBN);

		printf("enter number of pages:  ");
		scanf("%d", &arrayB[i].numPages);
	}
}