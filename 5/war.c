#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void welcome();
int drawCard();
int runRound();

//Card 0 is ace, 1 is two, 2 is three, etc...
char * cardNames[] = 
{
	"Ace",  //1
	"Two",  //2
	"Three",
	"Four",
	"Five",
	"Six",
	"Seven",
	"Eight",
	"Nine",
	"Ten",
	"Jack", //11
	"Queen",//12
	"King"  //13
};

int main()
{
	int correct = 0;
	char choice;
	
	int userSeed, seed, rounds, i;
	//Run welcome sequence
	welcome();

	//Get a true random, not computer-generated number
	printf("Enter a random number between 1 and 10,000: ");
	fflush(stdout);
	scanf("%d", &userSeed);

	seed = time(0) + userSeed;
	srand(seed);

	//Ascertain number of rounds
	printf("How many rounds would you like to play? ");
	fflush(stdout);
	scanf("%d", &rounds);
	getchar();

	//Run the rounds!
	for(i = 0; i < rounds; i++)
	{
		correct += runRound();
	}

	//End Report
	printf("All done!! \n");
	printf("You won %d of %d rounds\n", correct, rounds);

	return 0;
}

void welcome()
{
	printf("----------------------------------\n");
	printf("--   Welcome to Modified War!   --\n");
	printf("--                              --\n");
	printf("-- Where the cards are made up  --\n");
	printf("--  and the probabilities make  --\n");
	printf("--    no sense whatsoever!      --\n");
	printf("----------------------------------\n");

	return;
}



int drawCard()
{
	int card;
	card = rand() % 13;
	return card;
}

int runRound()
{
	int computerHand, userHand;
	char choice;
	int correct = 0;
	//Draw a card
	computerHand = drawCard();
	userHand = drawCard();

	do
	{
		printf("Your card is %s\n", cardNames[userHand]);
		printf("Is yours (H)igher or (L)ower than the computer? Or (T)ie? \n");
		scanf("%c", &choice);
		getchar();

		choice = tolower(choice);

		//Guessed Correctly
		if((choice == 'h' && userHand > computerHand) || (choice == 'l' && userHand < computerHand) || (choice == 't' && userHand == computerHand))
		{
			printf("Correct! The computer had a %s\n", cardNames[computerHand]);
			correct++;
		}
		else if(choice == 'h' || choice == 'l' || choice == 't')		//Guessed incorrectly
			printf("Incorrect. The computer had a %s\n", cardNames[computerHand]);
		else	//Invalid Option
			printf("Invalid option, try again!\n");

	}while(choice != 'h' && choice != 'l' && choice != 't');
	return correct;
}