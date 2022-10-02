#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int chkSecret(int a)
{
  if (a % 2 == 0)
    return 1;
  else
    return 0;
}


int main(int argc, char** argv)
{
	// variables
	char name[500] = {0};
	int secretNumber, guess, eo;

	// get user name
	printf("Enter your name: ");
	fgets(name,500,stdin);

	// get a secret number
	srand(time(0));
	secretNumber = rand() % 100;
	eo = chkSecret(secretNumber);

	// greet the user
	printf("Hi there ");
	printf(name);

	// play the game
	guess = 0;
	printf("The secret number is %s\n", eo?"even":"odd");
	printf("What is the number? ");
	scanf("%d", &guess);
	if (guess == secretNumber)
		printf("Great work! The number was %d\n", secretNumber);
	else
		printf("Incorrect - the number was %d\n", secretNumber);
	return 0;
}
