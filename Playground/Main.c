// ==================================
// Author: 
//		Kirushanth Aruldas
//		kirushanth@live.ca
// ==================================

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// =======================
// Variable Declarations
// =======================

// NOTE: Bellow is a string with a max char of 20, use %s to insert it to printf.
char playerName[20] = { 0 };
int noNameCount = 0;
int hadEnough = 0;
char pickedGame;
int gameOver = 0;
int money = 0;
int finalBet = 0;

// =======================
// Function Declarations
// =======================

void HandleNoName();
void ClearInputStream();
void Game0();
int checkCharInput(char userInput, char possiblities[], char respond[]);
void pause();
void getBet();
// int validateBet();
int checkIntInput(char *userInput, int size);

int main(void) {
	printf("Welcome to Mini-Games by Kiru\n\n");

	do {
		printf("Please enter your nickname: ");
		// NOTE: Using fgets to make empty input possible
		fgets(playerName, sizeof playerName, stdin);

		// NOTE: strcmp(string compare) takes 2 strings a compares them
		if (strcmp(playerName, "\n") == 0) {
			HandleNoName();
		}
	} while (strcmp(playerName, "\n") == 0);
 
	for (int i = 0; i < sizeof(playerName); i++) {
		if (playerName[i] == '\n') {
			playerName[i] = NULL;
		}
	}

	printf("\nWelcome %s\n\n", playerName);

	while (!gameOver) {
		printf("Please pick which game you would like to play\n");
		printf("	0-Exit Game\n");
		printf("	1-Card Guess(Name WIP)\n\n");

		do {
			do {
				printf("Please enter the number assioated with the game: ");
				pickedGame = fgetchar();
			} while (pickedGame == '\n');
			ClearInputStream();
		} while (checkCharInput(pickedGame, "01", "Entred value is not valid.\n") != 1);

		printf("\n************************************************************");
		printf("\n************************************************************");
		printf("\n************************************************************\n");

		switch (pickedGame) {
			case '0':
				printf("\nThank you for playing %s", playerName);
				gameOver = 1;
				break;
			case '1':
				Game0();
				break;
			// DEFAULT UNNESSOSSRY
		}

		printf("Care for another game?\n");
	}

	return 0;
}

// =======================
// Function Definitions
// =======================

void HandleNoName() {
	noNameCount++;
	if (noNameCount > 5) {
		if (!hadEnough) {
			printf("For sanity sake, just put a name down.\n\n");
			hadEnough = 1;
		} else {
			printf("Alright you are just Guest now.\n\n");
			// NOTE: strcpy(string copy) copies string in to variable, including the null char
			strcpy(playerName, "Guest\n");
		}
	}
	else {
		printf("No name means no game.\n");
	}
}

// NOTE: ONLY USE AFTER CHAR INPUT
void ClearInputStream() {
	char temp;
	do {
		temp = fgetchar();
	} while(temp != '\n');
}

int checkCharInput(char userInput, char possiblities[], char respond[]) {
	int retval = 0;

	for (int i = 0; i < sizeof(possiblities); i++) {
		if (userInput == possiblities[i]) {
			retval = 1;
		}
	}

	if (retval == 0) { printf(respond); }

	return retval;
}

void pause() {
	while (getchar() == "\n");
}

void getBet() {
	char bet[] = { 0 };
	do {
		scanf("%[^\n]s", bet);
	} while (checkIntInput(bet, sizeof(bet)));
}
//
//int validateBet() {
//	int valid = 1;
//	while (valid = 1) {
//		scanf("%d", &bet);
////		if (isdigit(bet)) {
//			if (bet < money) {
//				printf("Please enter an amount within your available money");
//			} else {
//				valid = 0;
//			}
////		} else {
////			printf("Please enter a number!! You fucking illiterate scum!"); //Completely NESSOSSRY
////		}
//	}
//}

int checkIntInput(char *userInput, int size) {
	int i, invalid = 0;
	for (i = 0; i < size && !invalid; i++) {
		if (userInput[i] < 48 || userInput[i] > 59) {
			invalid = 1;
			printf("Common... in numbers next time... Pretty please....\n");
		}
	}

	return invalid;
}

void Game0() {
	// NOTE:Game Logic
	// Used cards are A, 2, 3, 4, 5, 6
	// Ask the player to bet an amount between and including the min and max
	// Randomly pick a card and asks the player if its odd or even
	// if the player guesses right we show the card and move on to round 2
	// ask the player to bet more then what they already bet or start with the current bet
	// then draw another card and ask the player if its higher or lower then the pervious card
	// if the player guesses correct they win the bet ammount, if not they lose

	char shallWePlay;
	int gameOver = 0;

	printf("\nWelcome %s to Game 0\n\n", playerName);

	printf("In this game I will be using these 6 cards\n\n");
	printf("-----------     -----------     -----------     -----------     -----------     -----------\n");
	printf("|A        |     |2        |     |3        |     |4        |     |5        |     |6        |\n");
	printf("|         |     |         |     |         |     |         |     |         |     |         |\n");
	printf("|    Ω    |     |    Ω    |     |    Ω    |     |    Ω    |     |    Ω    |     |    Ω    |\n");
	printf("|         |     |         |     |         |     |         |     |         |     |         |\n");
	printf("|        A|     |        2|     |        3|     |        4|     |        5|     |        6|\n");
	printf("-----------     -----------     -----------     -----------     -----------     -----------\n\n");
	
	while (!gameOver) {
		do {
			printf("Shall we begin? or whould you like some instructions? (Yes, No or Help) ");
			shallWePlay = fgetchar();
			ClearInputStream();
		} while (checkCharInput(shallWePlay, "YyNnHh", "It's a simple question.\n") != 1);

		switch (shallWePlay) {
		case 'y':
		case 'Y':
			printf("\nAlright let's get started.\n");
			// TODO: FINISH THIS

			// TEMP 
			pause();

			printf("Let's take care of the most important part of this,\n");
			printf("How much do you bet? ");

			getBet();

			break;
		case 'n':
		case 'N':
			printf("Be back soon %s\n", playerName);
			gameOver = 1;
			break;
		case 'h':
		case 'H':
			printf("\nPress 'Enter' to continue\n");
			printf("\nThere are two rounds to this game");
			pause();
			printf("Before each round you will be able to place your bet.");
			pause();
			printf("During the first round I will pick one of the 6 cards i showed ealier,");
			pause();
			printf("and your objective is to guess if the card contains an odd or an even number.");
			pause();
			printf("If you guess right, round one ends.");
			pause();
			printf("If you choose to keep playing and increase your bet we move to round 2,");
			pause();
			printf("if not i double your bet and game end there.");
			pause();
			printf("During round 2, I will pick another card,");
			pause();
			printf("and your objective is to guess if the second card is higher or lower then then pervious card.");
			pause();
			printf("If you managed to guess correctly, I will double the bet.");
			pause();
			printf("If not you will loose the bet.");
			pause();
			printf("\n");
			break;
			// DEFAULT UNNESSOSSRY
		}
	}
}