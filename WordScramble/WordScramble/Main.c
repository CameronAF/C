#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// This is a scrambled word game
// The user is given a scrambled word and they get 3 chances to guess the word
// As extra help, the user can pick a letter, and the location of the letter in the word will be given
// after winning or loosing the user is asked if they want to continue.

#define SIZE 100
#define MAXGUESSES 3

//Displays instructions
void Instructions();

//this function sets all of the characters in a word to the same case
void DownCase(char str[], int len);

//this function reads from file to prep 4 strings to play game
int PrepString(FILE *words, char scrambled[], char answer[], char partial[], char guess[]);

//this function runs one game. It repeats for up to 3 times if the guesses are incorrect
//stops running game when the user has guessed the word correctly or has run out of guesses
void Play(char scrambled[], char answer[], char partial[], char guess[], int length);

//this function prompts the user to pick a letter
char PickLtr(char scrambled[], char partial[]);

//this function replaces *'s in the partial word with the users letter in its proper place 
void PlaceLtr(char ltr, char answer[], char partial[], int ele);

//this function prompts the player to make a guess
void MakeGuess();

//this function compares guess and answer and returns 0 if the words match 
int CompareGuess(char guess[], char answer[]);

//this function lets the player know if they won or if they lost
void GameResults(int win, int *numGuesses, char answer[]);

//Ask the user if they want to Play Again
void PlayAgain(char *goagain);

int main()
{
	// declare variables
	char scrambled[SIZE];
	char answer[SIZE];
	char partial[SIZE];
	char guess[SIZE];
	int length;
	char repeat;
	FILE *words;
	//open file
	words = fopen("words.txt","r");
	//call instructions to display
	Instructions();
	//loop for number of games till user doesn't want to play
	do{		
		//set up strings to play game and establish strings length 
		length=PrepString(words, scrambled, answer, partial, guess);
		//plays one game
		Play(scrambled, answer, partial, guess, length);
		// call to function to repeat loop if user chooses to
		PlayAgain(&repeat);
	}while(repeat=='Y');
	//close file
	fclose(words);
	//end program
	return 0;
}

//Displays instructions
void Instructions()
{
	printf("\n~~~~~Welcome to the game of SCRAMBLED~~~~~\n");
	printf("I will give you a few letter that make up a word.\n");
	printf("You get 3 chances to guess the word.\n");
	printf(" STEP 1: Pick a letter to display where it belongs in the word.\n");
	printf(" STEP 2: Guess the word from the scrambled letters and partially solved word.\n");
	printf("         If you can not guess the word ENTER PASS.\n");
	printf("         PASSing counts as a guess.\n");
	printf(" STEP 3: Repeat from STEP 1 till all 3 guesses are used.\n");
	return;
}

//this function sets all of the characters in a word to the same case
void DownCase(char str[], int ele)
{
	//declare variable i
	int i;
	//loot that makes all elements in an array lower case
	for(i=0; i<ele ; i++)
	{
		str[i]=tolower(str[i]);
	}
	return;
}

//this function reads from file to prep 4 strings to play game
int PrepString(FILE *words, char scrambled[], char answer[], char partial[], char guess[])
{
	//declare variables
	int length;
	int i;
	//take words from file
	fscanf(words, " %s", scrambled);
	fscanf(words, " %s", answer);
	//find number of elements in string
	length = strlen(answer);
	//set strings to lower case
	DownCase(scrambled, length);
	DownCase(answer, length);
	//copy length of trings to guess and partial
	strcpy(partial, answer);
	strcpy(guess, answer);
	//fills partial with '*'
	for(i=0; i<length; i++)
	{
		partial[i] = '*';
	}
	//return length to use in other functions
	return length;
}
//this function runs one game. It repeats for up to 3 times if the guesses are incorrect
//stops running game when the user has guessed the word correctly or has run our of guesses
void Play(char scrambled[], char answer[], char partial[], char guess[], int length)
{	
	//declare and initialize variables
	char ltr;
	int outPut = 1;
	int numGuesses = 0;	
	//loop to play game controlled by MAXGUESSES
	do{	
		//user picks a letter
		ltr=PickLtr(scrambled, partial);
		//places the lettter in the right spot
		PlaceLtr(ltr, answer, partial, length);
		//user guess word
		MakeGuess(scrambled, partial, guess);
		////sets all of the characters in guess to lower case
		DownCase(guess, length);
		//increases numGuesses by 1
		numGuesses++;
		//compare guess
		outPut = CompareGuess(guess, answer);
		//game results or guess results
		if(outPut == 0 || numGuesses == MAXGUESSES)
		{
			GameResults(outPut, &numGuesses, answer);
		}
		else
		{
			// displays incorrect guess results
			printf("\nSorry, you could not guess the right word.\n", guess);
			printf("That was guess %d of %d.\n", numGuesses, MAXGUESSES);
		}
	} while(numGuesses < MAXGUESSES);
	return;
}

//this function prompts the user to pick a letter
char PickLtr(char scrambled[], char partial[])
{
	//declare letter variable 
	char ltr;
	//display
	printf("\n\n~~~~~~~~~~ PICK A LETTER ~~~~~~~~~~\n");
	printf("Here is the scrambled word:\n");
	printf("     %s \n", scrambled);
	printf("Here are the letters you have so far:\n");
	printf("     %s \n", partial);
	printf("WHAT LETTER WOULD YOU LIKE TO PLACE?\n");
	//receave letter from the user
	scanf(" %c", &ltr);
	//makes ltr lower case
	ltr=tolower(ltr);
	return ltr;
}

//this function replaces *'s in the partial word with the users letter in its proper place 
void PlaceLtr(char ltr, char answer[], char partial[], int ele)
{
	//declare loop variable
	int i;
	//putts letter in partial array
	for(i=0; i<ele; i++)
	{
		if (answer[i] == ltr)
		{
			partial[i] = ltr;
		}
	}
	return;
}

//this function prompts the player to make a guess
void MakeGuess(char scrambled[], char partial[], char guess[])
{
	//display
	printf("\n\n~~~~~~~~~~ GUESS THE WORD~~~~~~~~~~\n");
	printf("Here is the scrambled word:\n");
	printf("     %s \n", scrambled);
	printf("Here are the letters you have so far:\n");
	printf("     %s \n", partial);
	printf("GUESS THE WORD:\n");
	//receave guess from user
	scanf(" %s", guess);
	return;
}


//this function compares guess and answer and returns 0 if the words match 
int CompareGuess(char guess[], char answer[])
{
	//declare match
	int match;
	//compare guess to answer
	match = strcmp(guess, answer);
	//returns int match
	return match;
}

//this function lets the player know if they won or if they lost
void GameResults(int win, int *numGuesses, char answer[])
{
	//win ot loose
	if(win == 0)
	{
		//win
		*numGuesses = 4;
		printf("\nYOU WON!!\n");
	}
	else 
	{
		//loose
		printf("\nThats all 3 guesses.\n");
		printf("the answer was %s.\n", answer);
		printf("You loose.\n\n");
	}
	return;
}

//Ask the user if they want to Play Again
void PlayAgain(char *goagain)
{
	//intruction if user wants to continue with another game
	printf("\n\nDo you want to play again?\n");
	printf("Please ENTER:\n");
	printf("YES.................Y\n");
	printf("NO..................N\n");
	//users input
	scanf(" %c", goagain);
	*goagain = toupper(*goagain);
	return;
}