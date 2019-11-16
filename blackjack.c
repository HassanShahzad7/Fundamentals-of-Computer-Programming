#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main()
{
	// declaring variables
	int user1, user2, dealer1, dealersecret, totaluser, totaldealer;
	char choice;
	// This allows you to generate the same sequence of random numbers 
	srand(time(NULL));
	// assigning values to variables
	user1 = 2 + rand() % 11;
	user2 = 2 + rand() % 11;
	dealer1 = 2 + rand() % 11;
	dealersecret = 2 + rand() % 11;
	totaluser = 0;
	totaldealer = 0;

	// displays welcome message and tells about basic information about blackjack
	printf("Welcome to simple blackjack program!\n");
	printf("It is a game of cards in which dealer has drawn two cards and two cards from the deck are given to you too.\n");
	printf("The dealer has a hidden card and one shown card the user has the choice either to hit or stay.\n");
	printf("The one who gets more than 21 score loses the match or the who has scored below the score of the opponent in case both have below 21 score.\n");
	printf("Lets get started!\n");

	// displays user's cards and calculates the total of it
	printf("You get a %d and a %d.\n", user1, user2);
	totaluser = totaluser + user1 + user2;
	printf("Your total is %d\n\n", totaluser); // displays total of user cards
	printf("The dealer has a %d showing, and a hidden card.\n", dealer1);
	totaldealer = totaldealer + dealer1 + dealersecret; // calculating dealer's total
	printf("His total is hidden, too.\n\n");

	printf("Would you like to \"hit\" or \"stay\"?"); // asking from the user to play or forfeit
	printf("Enter 'h' for \"hit\" and 's' for \"stay\".");
	scanf("%c", &choice);
	printf("\n\n");

	while (choice == 'h') // while choice is hit it executes the block of code
	{
		printf("You drew a %d\n", user1);
		totaluser = totaluser + user1; // calculates total of user's cards
		printf("Your total is %d\n\n", totaluser); // displays user total
		if (totaluser > 21) // if total of user is greater than 21 than dealer wins
		{
			printf("The dealer wins\n");
			return 0;
		}
		printf("Would you like to \"hit\" or \"stay\"?"); // asking from the user to play or forfeit
		scanf(" %c", &choice); // accepts the input
		printf("\n\n");


		while (choice == 'h') // while choice is hit it executes following the block of code
		{
			printf("You drew a %d\n", user1);
			totaluser = totaluser + user1;
			printf("Your total is %d\n\n", totaluser);
			if (totaluser > 21)
			{
				printf("The dealer wins\n");
				return 0;
			}
			printf("Would you like to \"hit\" or \"stay\"?");
			scanf(" %c", &choice);
			printf("\n\n");
		}
	}

	if (choice == 's') // if choice is stay it executes the following block of code
	{
		printf("Okay, dealer’s turn.\n");
		printf("His hidden card was a %d\n", dealersecret); // displays dealer's hidden card
		printf("His total was %d.", totaldealer); // displays total of user's card

		while (totaldealer <= 16) // while total of dealer cards is less than 16 it executes the following block of code
		{
			printf("Dealer chooses to hit\n");
			printf("He draws a %d\n", dealer1); // displays the dealer's new card
			totaldealer = totaldealer + dealer1; // calculates dealer's total
			printf("His total is %d\n", totaldealer);
			if (totaldealer > 21)
			{
				printf("YOU WIN\n"); // if total of dealer is 21 then displays you win
				return 0;
			}
		}
		if (totaldealer > 16)
		{
			printf("Dealer stays.\n\n"); // if total of dealer's cards is greater than 16 then dealer stays
		}
	}

	if (totaluser > totaldealer) // if total of user's card is greater than dealer's card then display that user wins
	{
		printf("YOU WIN\n");
	}
	if (totaluser <= totaldealer)
	{
		printf("YOU LOST\n"); // if total of delaer's cards is greater than user's cards then display that dealer wins
	}

	return 0;
}