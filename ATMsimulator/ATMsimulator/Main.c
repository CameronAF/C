#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <ctype.h>

// This project is a ATM simulator
// User will be able to make deposits, make withdrawals, or view ballance for 3 seporate accounts

//Displays the list of options available
//Prompts for the user's selection and sets the value of the selection
void MainMenu(int *option);

//Ask the user which type of account they would like to access and sets the value of the selection
void AccountMenu(char *accType);

//Prompts the user for the amount of deposit and updates the selected account
void MakeDeposit(double *balance);

//Prompts the user for the amount of the withdrawal
//Determines if there are sufficient funds and updates the selected account if funds are dispensed
void MakeWithdrawal(double *balance, char accType);

//Display the user's current account balance for the selected account
void GetBalance(double balance);

//Ask the user if they want another transaction
void KeepGoing(char *goagain);

int main()
{
	//declare and initialize variables 
	double checking = 850.00;
	double savings = 2500.00;
	double credit = -1850.00;
	double tempBalance;
	int transaction;
	char account;
	char repeat;
	//welcome message
	printf("Welcome to MyBank\n");
	do{
		//call to MainMenu
		MainMenu(&transaction);
		//call to AccountMenu
		AccountMenu(&account);
		//switch controlled by the condition of the variable transaction 
		switch (transaction)
		{
			case 1:		switch (account)  //switch controlled by the condition of the variable account
						{
							case 'C':	printf("Checking - Deposit\n");  //executes if checking and deposit are chosen
										GetBalance(checking);		
										MakeDeposit(&checking);
										break;
							case 'S':	printf("Savings - Deposit\n");  //executes if savings and deposit are chosen
										GetBalance(savings);		
										MakeDeposit(&savings);
										break;
							case 'R':	printf("Credit - Deposit\n");  //executes if credit and deposit are chosen
										MakeDeposit(&credit);
										break;
							default:	printf("errer: invalid account\n\n");  //errer for invalid input
										break;
						}
						break;
			case 2:		switch (account)  //switch controlled by the condition of the variable account
						{
							case 'C':	printf("Checking - Withdrawal\n");  //executes if checking and withdrawal are chosen
										GetBalance(checking);
										MakeWithdrawal(&checking, account);  
										break;
							case 'S':	printf("Savings - Withdrawal\n");  //executes if savings and withdrawal are chosen
										GetBalance(savings);
										MakeWithdrawal(&savings, account);
										break;
							case 'R':	printf("Credit - Withdrawal\n");  //executes if credit and withdrawal are chosen
										GetBalance(credit);
										MakeWithdrawal(&credit, account);
										break;
							default:	printf("errer: invalid account\n\n");  //errer for invalid input
										break;
						}
						break;
			case 3:		switch (account)  //switch controlled by the condition of the variable account
						{
							case 'C':	printf("Checking - Balance\n");  //executes if checking and account balance are chosen
										GetBalance(checking);
										break;
							case 'S':	printf("Savings - Balance\n");  //executes if savings and account balance are chosen
										GetBalance(savings);
										break;
							case 'R':	printf("Credit - Balance\n");  //executes if credit and account balance are chosen
										GetBalance(credit);
										break;
							default:	printf("errer: invalid account\n\n"); //errer for invalid input
										break;
						}
						break;
			default:	printf("errer: invalid transaction\n\n");  //errer for invalid input
						break;
		}
		// call to function to repeat loop
		KeepGoing(&repeat);
	}while(repeat=='Y');
	return 0;
}

//Displays the list of options available
//Prompts for the user's selection and sets the value of the selection
void MainMenu(int *option)
{
	//menu display
	printf("\nPlease ENTER what type of transaction you wish to proceed with:\n");
	printf("DEPOSIT.............1\n");
	printf("WITHDRAWAL..........2\n");
	printf("ACCOUNT BALANCE.....3\n");
	printf("To transfer money, first WITHDRAWAL(2) then DEPOSIT(1)\n");
	//users input
	scanf(" %d", option);
	//input recall
	printf("\nYou have selected:  %d \n\n", *option);
	return;
}

//Ask the user which type of account they would like to access and sets the value of the selection
void AccountMenu(char *accType)
{
	//menu display
	printf("Please ENTER the account you would like to proceed with:\n");
	printf("CHECKING............C\n");
	printf("SAVINGS.............S\n");
	printf("CREDIT..............R\n");
	//users input
	scanf(" %c", accType);
	//atuo-upercase for computing simplisity
	*accType = toupper(*accType);
	//unput recall
	printf("\nYou have selected:  %c \n\n", *accType);
	return;
}

//Prompts the user for the amount of deposit and updates the selected account
void MakeDeposit(double *balance)
{
	//declare variable
	double deposit;
	//display intructions
	printf("Please ENTER the amount you would like to deposit\n");
	//user inputs amount to be deposited
	scanf(" %lf", &deposit);
	//balance is ajusted
	*balance= *balance + deposit;
	//recall of balance after transaction
	printf("Your new balance for this account is $%.2f\n", *balance);
	return;
}

//Prompts the user for the amount of the withdrawal
//Determines if there are sufficient funds and updates the selected account if funds are dispensed
void MakeWithdrawal(double *balance, char accType)
{
	//declare variable
	double withdraw;
	//display instructions
	printf("Please ENTER the amount you would like to withdraw\n");
	//user inputs amount to be withdrawn
	scanf(" %lf", &withdraw);
	//IfElse to distingush between checking & savings or credit
	if(accType=='C' || accType=='S')
	{
		//if to prevent overdrafting account
		if(*balance >= withdraw)
		{
			*balance = *balance - withdraw;
			printf("Your new balance for this account is $%.2f\n", *balance);
		}
		else
		{
			printf("This transaction cannot be completed at this time due to insufficient funds\n");
		}
	}
	else
	{
		*balance = *balance - withdraw;
		printf("Your new balance for this account is $%.2f\n", *balance);
	}
	return;
}

//Display the user's current account balance for the selected account
void GetBalance(double balance)
{
	printf("Your balance for this account is $%.2f\n", balance);
	return;
}

//Ask the user if they want another transaction
void KeepGoing(char *goagain)
{
	//intruction if user wants to continue with another transaction
	printf("\n\nDo you want to continue with another transaction?\n");
	printf("Please ENTER:\n");
	printf("YES.................Y\n");
	printf("NO..................N\n");
	//users input
	scanf(" %c", goagain);
	*goagain = toupper(*goagain);
	return;
}