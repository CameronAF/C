#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

typedef struct 
{
	char name[SIZE];
	int cost;
	char speed;
	int landAtk;
	int airAtk;
	int seaAtk;
	double avgAtk;
	char skill[SIZE];
	double value;
}Fantasica;

//beginning message
void Intro();

//displays menu commands and returns users choice by pointer
void MainMenu(char *choice);

//capitalizes first letter of word and sets the rest to lower case
void SameWordCase(char str[]);

//add and entry to the roster
void AddEntry(Fantasica unit[], int *filled);

//delete an entry from the roster
void DeleteEntry(Fantasica units[], int *filled);

//display all records in the roster
void ShowAll(Fantasica units[], int filled);

//display a chosen record in the roster
void ShowOne(Fantasica units[], int filled);

//makes a file with all roster information
void Report(Fantasica units[], int filled);

//clears the roster of any data
void Clear(int *filled);

int main()
{
	//declare and initialize variables
	Fantasica roster[SIZE] = {
		"Nina", 15, 'C', 66505, 79575, 63800, 69960, "Knockback", .5, 
		"Isis", 15, 'D', 65084, 69685, 76255, 70341.33, "Poison", .5, 
		"Charles", 10, 'S', 49430, 22730, 44090, 38750, "None", .2, 
		"Monica", 30, 'D', 90010, 63870, 103150, 85676.66, "Slow", 0.45, 
		"Clarissa", 30, 'D', 69545, 79470, 86075, 78363.33, "Area_Attack", .8};
	int entries = 5;
	char action;
	Intro();
	//loop to repeat actions till user enters Q
	do{
		//call main menu
		MainMenu(&action);
		//switch to navigate through main menu by action variable
		switch (action)
		{
			case 'A':	AddEntry(roster, &entries);
						break;
			case 'D':	DeleteEntry(roster, &entries);
						break;
			case 'S':	ShowAll(roster, entries);
						break;
			case 'O':	ShowOne(roster, entries);
						break;
			case 'R':	Report(roster, entries);
						break;
			case 'C':	Clear(&entries);
						break;
			case 'Q':	break;
			default:	printf("error: invalid action chosen\n");
		}
	}while(action!='Q');
	return 0;
}

//beginning message
void Intro()
{
	printf("########    ###    ##    ## ########    ###     ######  ####  ######     ### \n");
	printf("##         ## ##   ###   ##    ##      ## ##   ##    ##  ##  ##    ##   ## ##\n");
	printf("##        ##   ##  ####  ##    ##     ##   ##  ##        ##  ##        ##   ##\n");
	printf("######   ##     ## ## ## ##    ##    ##     ##  ######   ##  ##       ##     ##\n");
	printf("##       ######### ##  ####    ##    #########       ##  ##  ##       #########\n");
	printf("##       ##     ## ##   ###    ##    ##     ## ##    ##  ##  ##    ## ##     ##\n");
	printf("##       ##     ## ##    ##    ##    ##     ##  ######  ####  ######  ##     ##\n\n");
	printf("This is a roster to creat a team of units for arenas in the game of Fantasica\n\n\n");
	return;
}

//displays menu commands and returns users choice by pointer
void MainMenu(char *choice)
{
	//display menu
	printf("\n~~~~~~~~~~Main Menu~~~~~~~~~~\n");
	printf("Please ENTER what action you would like to do\n");
	printf("A....Add a new unit\n");
	printf("D....Delete a unit from the roster\n");
	printf("S....Show all units and stats\n");
	printf("O....Show one stat of all units\n");
	printf("R....Create a current report\n");
	printf("C....Clear roster\n");
	printf("Q....Quit\n");
	//receive users input
	scanf(" %c", choice);
	//sets users input to upper case
	*choice = toupper(*choice);
	return;
}

//capitalizes first letter of word and sets the rest to lower case
void SameWordCase(char str[])
{
	//declare variable i for loop
	int i=0;
	//makes first letter upper case
	str[i]=toupper(str[i]);
	//loop that makes all elements after first letter lower case
	for(i=1; i<SIZE ; i++)
	{
		str[i]=tolower(str[i]);
	}
	return;
}

//add and entry to the roster
void AddEntry(Fantasica unit[], int *filled)
{
	printf("\n~~~~~~~~~~ Add Entry Menu ~~~~~~~~~~\n");
	//displays instructions followed by receiving input for all elements in structure Fantasica
	printf("You have chosen to add a unit to the arena roster\n");
	printf("Begin by ENTERing the units Name\n");
	scanf(" %s", unit[*filled].name);
	SameWordCase(unit[*filled].name);
	printf("ENTER the Cost of the unit\n");
	scanf(" %d", &unit[*filled].cost);
	printf("ENTER the Speed of the unit\n");
	scanf(" %c", &unit[*filled].speed);
	unit[*filled].speed = toupper(unit[*filled].speed);
	printf("ENTER the Land Attack of the unit\n");
	scanf(" %d", &unit[*filled].landAtk);
	printf("ENTER the Air Attack of the unit\n");
	scanf(" %d", &unit[*filled].airAtk);
	printf("ENTER the Sea Attack of the unit\n");
	scanf(" %d", &unit[*filled].seaAtk);
	unit[*filled].avgAtk = (unit[*filled].landAtk + unit[*filled].airAtk + unit[*filled].seaAtk) / 3;
	printf("Average Attack has been calculated to %.2f\n",unit[*filled].avgAtk);
	printf("ENTER the Skill of the unit\n");
	scanf(" %s", unit[*filled].skill);
	SameWordCase(unit[*filled].skill);
	printf("ENTER the Value of the unit\n");
	scanf(" %lf", &unit[*filled].value);
	//increase units in roster by 1
	(*filled)++;
	return;
}

//delete an entry from the roster
void DeleteEntry(Fantasica units[], int *filled)
{
	//declare variables
	int i;
	char trashUnit[SIZE];
	int match;
	int foundIt=0;
	printf("\n~~~~~~~~~~ Delete Entry Menu ~~~~~~~~~~\n");
	//displays all names in roster
	printf("Which unit do you want to delete from the roster?\n");
	printf("ENTER 'Q' to Quit Deleting\n");
	printf("\n~~~ Roster ~~~\n");
	for (i=0; i<*filled; i++)
	{
		printf("   %s\n",units[i].name);
	}
	//receives desired unit to be deleted
	scanf(" %s", trashUnit);
	SameWordCase(trashUnit);
	//searches for to-be-deleted unit
	for (i=0; i<*filled; i++)
	{
		match=strcmp(units[i].name, trashUnit);
		if(match==0)
		{
			//replaces to-be-deleted unit with last unit in roster
			units[i]=units[(*filled)-1];
			//reduces the units in roster by 1
			(*filled)--;
			printf("%s was successfully deleted from roster\n", trashUnit);
			foundIt=1;
		}
	}
	//if unit was not found in roster
	if(foundIt==0)
	{
		printf("Unit not found in roster\n");
	}
	return;
}

//display all records in the roster
void ShowAll(Fantasica units[], int filled)
{ 
	int i;
	printf("\n~~~~~~~~~~ Full Roster ~~~~~~~~~~\n");
	//display all units and their stats
	for (i=0; i<filled; i++)
	{
		printf("Name............ %s\n",units[i].name);
		printf("Cost............. %d\n",units[i].cost);
		printf("Speed............ %c\n",units[i].speed);
		printf("Land Attack...... %d\n",units[i].landAtk);
		printf("Air Attack....... %d\n",units[i].airAtk);
		printf("Sea Attack....... %d\n",units[i].seaAtk);
		printf("Average Attack... %.2f\n",units[i].avgAtk);
		printf("Skill............ %s\n",units[i].skill);
		printf("Value............ %.2f\n\n",units[i].value);
	}
	printf("     END DISPLAY\n\n");
	return;
}

//display a chosen record in the roster
void ShowOne(Fantasica units[], int filled)
{
	char action;
	int i;
	//display menu
	printf("\n~~~~~~~~~~ Display Menu ~~~~~~~~~~\n");
	printf("What field would you like to display of the units\n");
	printf("C.............Cost\n");
	printf("P............Speed\n");
	printf("L......Land Attack\n");
	printf("A.......Air Attack\n");
	printf("S.......Sea Attack\n");
	printf("G...Average Attack\n");
	printf("K............Skill\n");
	printf("V............Value\n");
	//receive users input
	scanf(" %c", &action);
	//sets users input to upper case
	action = toupper(action);
	//loop to display state for all units
	for (i=0; i<filled; i++)
	{
		printf("\n%s  ",units[i].name);
		//switch to show desired stat
		switch (action)
		{
			case 'C':	printf(" %d",units[i].cost);
						break;
			case 'P':	printf(" %c",units[i].speed);
						break;
			case 'L':	printf(" %d",units[i].landAtk);
						break;
			case 'A':	printf(" %d",units[i].airAtk);
						break;
			case 'S':	printf(" %d",units[i].seaAtk);
						break;
			case 'G':	printf(" %.2f",units[i].avgAtk);
						break;
			case 'K':	printf(" %s",units[i].skill);
						break;
			case 'V':	printf(" %.2f",units[i].value);
						break;
			default:	printf("error: invalid action chosen\n");
						return;
		}
	}
	//space
	printf("\n");
	return;
}

//makes a file with all roster information
void Report(Fantasica units[], int filled)
{
	int i;
	FILE *team;
	//make-open a file
	team=fopen("ArenaTeam.txt","w");
	fprintf(team, "Fantasica Arena Team Roster\n");
	//loop to store all units and stats in file
	for(i=0; i<filled; i++)
	{
		fprintf(team, "\nName............ %s\n",units[i].name);
		fprintf(team, "Cost............. %d\n",units[i].cost);
		fprintf(team, "Speed............ %c\n",units[i].speed);
		fprintf(team, "Land Attack...... %d\n",units[i].landAtk);
		fprintf(team, "Air Attack....... %d\n",units[i].airAtk);
		fprintf(team, "Sea Attack....... %d\n",units[i].seaAtk);
		fprintf(team, "Average Attack... %.2f\n",units[i].avgAtk);
		fprintf(team, "Skill............ %s\n",units[i].skill);
		fprintf(team, "Value............ %.2f\n",units[i].value);
	}
	//close file
	fclose;
	printf("\nReport Successfully Created\n");
	return;
}

//clears the roster of any data
void Clear(int *filled)
{
	char choice;
	//confirm if user wants to clear roster
	printf("\n~~~~~~~~~~ Clear Menu ~~~~~~~~~~\n");
	printf("ARE YOU SURE YOU WOULD LIKE TO CLEAR THE ROSTER\n");
	printf("Please ENTER:\n");
	printf("Y..........YES\n");
	printf("N..........NO\n");
	scanf(" %c", &choice);
	//sets users input to upper case
	choice = toupper(choice);
	if(choice=='Y')
	{
		//sets filled to 0 which clears roster
		*filled=0;
		printf("clear successful\n");
	}
	else
	{
		//doesn't clear roster
		printf("clear cancelled\n");
	}
	return;
}

