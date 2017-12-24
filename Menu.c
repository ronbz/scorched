#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void game();
void rules();
void score();


int main() {
	int i;
	printf("   _____    _____    ____    _____     _____   _    _   ______   _____  \n");
	printf("  / ____|  / ____|  / __ \\  |  __ \\   / ____| | |  | | |  ____| |  __ \\  \n");
	printf(" | (___   | |      | |  | | | |__) | | |      | |__| | | |__    | |  | | \n");
	printf("  \\___ \\  | |      | |  | | |  _  /  | |      |  __  | |  __|   | |  | | \n");
	printf("  ____) | | |____  | |__| | | | \\ \\  | |____  | |  | | | |____  | |__| | \n");
	printf(" |_____/   \\_____|  \\____/  |_|  \\_\\  \\_____| |_|  |_| |______| |_____/  \n");
	
	
	do{
		printf("        Main Menu \n");
		printf("        ---------\n");
		printf("1. Start a Game \n");
		printf("2. Game Rules \n");
		printf("3. High Scores \n");
		printf("4. Exit \n");
		printf("\n");
		printf("Enter a number to choose your option...\n");
		scanf("%d", &i);
		while (i != 1 && i != 2 && i != 3 && i != 4) {
				printf("Wrong input! please choose between options 1-4...\n");
				scanf("%d", &i);
			}
		switch (i) {
			case 1:
				game();
				break;
			case 2:
				rules();
				break;
			case 3:
				score();
				break;
			case 4:
				printf("Thanks for playing!\n");
				break;
			}
			getchar();
		} while (i != 4);
		
		
	return 0;
}


void game() {
	printf("\nTesting game\n\n");
}
void rules() {
	printf("\n        Game Rules:\n");
	printf("       ------------\n");
	printf("This game is based on your math calculation skills, strategy planning and on your simple love to hit other tanks\n");
	printf("Scorched can be played by 2-4 players at the same time\n");
	printf("Each tank has 3 health points, which means it will be destroyed on the third hit!\n");
	printf("The goal of the game is to destroy all the other tanks and to remain the last one standing\n");
	printf("In each turn, a tank can move up to 5 steps.\n \n");
	printf("There are 4 shooting options:\n");
	printf("The first option is the ''Straight (linear) Shot'', shot by the equation: Y=MX+N\n");
	printf("The second option is the ''Parabolic Shot'', shot by the equation: Y=AX^2+BX+C\n");
	printf("The third is the ''Guided Shot'', shot by the equation: Y=A*log X base B\n");
	printf("The forth is the ''Crazy Sheep'', shot by the equation: Y=A*sin(BX)\n\n");
	printf("             **MAY THE ODDS BE EVER IN YOUR FAVOR!** \n\n\n");
	printf("Press any key to return to the main menu\n");
	getchar();
}

void score() {
	printf("\nTesting score\n\n");
}