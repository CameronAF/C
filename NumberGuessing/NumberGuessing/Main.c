#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> //for input/output
#include <time.h> //to use the internal system clock for random number generation
#include <stdlib.h> //to use the random number generator

// This is a number guessing game 
// the user will get 6 chances to guess a randomly generated number from 1 to 100
// If guessed incorectly, the user will be notified if there guess it to low or to high.

#define MAXGUESSES 6
#define MAX 99 

//function prototypes with a comment for each one describing what the function does

//this function will use a random number generator to create a file of numbers
void MakeFile();

//this function runs one game. It repeats for up to 6 times if the guesses are incorrect
//it stops running the game when the user has guessed the number correctly or has run our of guesses
int Play(int answer);

//this function prompts the player to make a guess and returns the guess
//this function is called from the Play() function described above
int GetGuess();

//this function takes two arguments, the guess from the player and the answer from the file
//it lets the user know if the guess is to high, to low or correct
//this function returns 0 if not correct , 1 if correct
int CompareGuess(int guess, int answer);

int main()
{
	int gamesToPlay;
	int i;
	int answer;
	int outPut;
	FILE *answers;
	//display instructions
	printf("Are you feeling lucky?\n");
	printf("Lets Play a game.\n");
	printf("Guess what number im thinking of from 1 to 100.\n");
	printf("You have 6 chances to guess the answer.\n");
	printf("OH!!\n");
	printf("But first, Enter how many games you want to play.\n");
	printf("Just so you know, the max is 20 games.\n");
	//make file
	MakeFile();
	//open file to get numbers
	answers = fopen("numbers.txt","r");
	//get number of games to play
	scanf(" %d", &gamesToPlay);
	//loop for number of games
	for(i=1; i<=gamesToPlay; i++)
	{
		//get number from file and save to variable
		fscanf(answers, " %d", &answer);
		//Play one game
		outPut = Play(answer);
		//Check for win or lose	
		if(outPut > 0)
		{
			printf("WOW, YOU WON!!\n");
			printf("Dont you feel smart.\n\n");
		}
		else 
		{
			printf("Thats all 6 guesses.\n");
			printf("the answer was %d.\n", answer);
			printf("You loose.\n\n");
		}
		if(i<gamesToPlay)
		{
			printf("Next Game.\n");
		}
	}
	
	//close file
	fclose(answers);
	//end program
	return 0;
}


//this function will use a random number generator to create a file of numbers
void MakeFile()
{
	//declare variables
	int num;
	int i;
	FILE *nums;
	//open file to save numbers
	nums = fopen("numbers.txt","w");
	//seeds the number generator to randomize
	srand(time(NULL));
	for(i=0;i<20;i++)
	{
		//calculates a random number from 1 and 100
		num = rand()%MAX +1;
		//save number to the file
		fprintf(nums, "%d ", num);
	}
	//close file
	fclose(nums);
}



//this function runs one game. It repeats for up to 6 times if the guesses are incorrect
//it stops running the game when the user has guessed the number correctly or has run our of guesses
int Play(int answer)
{	
	//declare variables
	int outPut = 0;
	int guess;
	int numGuesses = 0;	
	//ask to pick number
	printf("Pick a number.\n");
	//loop to recive and compare 
	do{	
		//get guess
		guess = GetGuess();
		//compare guess
		outPut = CompareGuess(guess, answer);
		if(outPut == 1)
		{
			numGuesses = 6;
		}
		//increases number of guesses made
		numGuesses = numGuesses +1;
	} while(numGuesses < MAXGUESSES);
	//return int
	return outPut;
}


//this function prompts the player to make a guess and returns the guess
//this function is called from the Play() function described above
int GetGuess()
{
	//declare variables
	int guess;
	//get guess
	scanf(" %d", &guess);
	//return guess
	return guess;

}


//this function takes two arguments, the guess from the player and the answer from the file
//it lets the user know if the guess is to high, to low or correct
//this function returns 0 if not correct , 1 if correct
int CompareGuess(int guess, int answer)
{
	//declare output
	int outPut;
	//compare guess
	if(guess > answer)
	{
		printf("Your guess of %d is to high.\n", guess);
		printf("Pick another number.\n");
		outPut = 0;
	}
	else if(guess < answer)
	{
		printf("Your guess of %d is to low.\n", guess);
		printf("Pick another number.\n");
		outPut = 0;
	}
	else if(guess == answer)
	{
		outPut = 1;
	}
	//return int
	return outPut;
}