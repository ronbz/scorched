#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define length 250
#define height 50

typedef struct Player {
	char Name[10];
	int i;
	int j;
	int Lives;
	char id;
}Player;

void game();
void movement(char mat[height][length], Player *pl);
void rules();
void score();
Player NewPlayer(Player*, int);
void UpdatePlace(Player*, char[height][length], int);
int CreatMap(char[height][length]);
void printMap(char[height][length]);
////*void writeNewPlayerToDatabase(char* fileName, char* userName);
//void updatePlayer(char *fileName, char* userName, int upDown);
//int returnWin(char* fileName, char* playerName);
//int returnLose(char* fileName, char* playerName);
//void highscoreTable(char *players);*//

int main() {
	int i;
	printf("   _____    _____    ____    _____     _____   _    _   ______   _____  \n");
	printf("  / ____|  / ____|  / __ \\  |  __ \\   / ____| | |  | | |  ____| |  __ \\  \n");
	printf(" | (___   | |      | |  | | | |__) | | |      | |__| | | |__    | |  | | \n");
	printf("  \\___ \\  | |      | |  | | |  _  /  | |      |  __  | |  __|   | |  | | \n");
	printf("  ____) | | |____  | |__| | | | \\ \\  | |____  | |  | | | |____  | |__| | \n");
	printf(" |_____/   \\_____|  \\____/  |_|  \\_\\  \\_____| |_|  |_| |______| |_____/  \n");


	do {
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

	int choise, map, counter = 0;
	struct Player *pl1 = (struct Player*)malloc(sizeof(struct Player));
	struct Player *pl2 = (struct Player*)malloc(sizeof(struct Player));
	struct Player *pl3 = (struct Player*)malloc(sizeof(struct Player));
	struct Player *pl4 = (struct Player*)malloc(sizeof(struct Player));

	char mat[height][length];
	printf("\nplaese enter the number of players(2 - 4):\t");
	scanf("%d", &choise);


	while (choise > 4 || choise < 2)
	{
		printf("wrong number of players, please try again:");
		scanf("%d", &choise);
	}

	switch (choise)
	{
	case 2:
		printf("\nenter first player name:\t");
		counter++;
		NewPlayer(pl1, counter);
		printf("\nenter second player name:\t");
		counter++;
		NewPlayer(pl2, counter);
		map = CreatMap(mat);
		printf("\n\n\nTEST1\n\n\n");
		UpdatePlace(pl1, mat, map);
		UpdatePlace(pl2, mat, map);
		printMap(mat);
		break;
	case 3:
		printf("\nenter first player name:\t");
		counter++;
		NewPlayer(pl1, counter);
		printf("\nenter second player name:\t");
		counter++;
		NewPlayer(pl2, counter);
		printf("\nenter third player name:\t");
		counter++;
		NewPlayer(pl3, counter);
		map = CreatMap(mat);
		UpdatePlace(pl1, mat, map);
		UpdatePlace(pl2, mat, map);
		UpdatePlace(pl3, mat, map);
		printMap(mat);
		break;

	case 4:
		printf("\nenter first player name:\t");
		counter++;
		NewPlayer(pl1, counter);
		printf("\nenter second player name:\t");
		counter++;
		NewPlayer(pl2, counter);
		printf("\nenter third player name:\t");
		counter++;
		NewPlayer(pl3, counter);
		printf("\nenter fourth player name:\t");
		counter++;
		NewPlayer(pl4, counter);
		map = CreatMap(mat);
		UpdatePlace(pl1, mat, map);
		UpdatePlace(pl2, mat, map);
		UpdatePlace(pl3, mat, map);
		UpdatePlace(pl4, mat, map);
		printMap(mat);
		break;
	}
	movement(mat,pl1);
	movement(mat,pl2);
	movement(mat,pl3);
	movement(mat,pl4);
}

Player NewPlayer(Player *pl, int counter) {
	scanf("%s", pl->Name);
	//writeNewPlayerToDatabase("test.txt", pl->Name);
	pl->Lives = 2;
	pl->i = 0;
	pl->j = 0;
	pl->id = counter + '0';
	return *pl;
}

int CreatMap(char mat[height][length]) {
	int map;
	printf("\nplease select the level difficulty (1-3):\t");
	scanf("%d", &map);
	getchar();

	while (map > 3 || map < 1)
	{
		printf("\nwrong entery please try again:\t");
		scanf("%d", &map);
		getchar();
	}

	switch (map)
	{
		//first map//
	case 1:
	{
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 250; j++)
			{
				mat[i][j] = ' ';
			}
		}
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 250; j++)
			{
				if (i < 50 && i>40)
				{
					mat[i][j] = 'x';
				}
			}
		}
		for (int i = 0; i < 49; i++)
		{

			for (int j = 0; j < i; j++)
			{
				mat[i][j] = 'x';
			}
		}
		// left sharp tringle//
		int k = 249;
		while (k != 300)
		{
			for (int i = 0; i < 50; i++)
			{
				for (int j = 199; j < 250; j++)
				{
					if (i + j == k)
					{
						mat[i][j] = 'x';
					}
				}
			}
			k++;
		}
		//print map//
		printMap(mat);
		break;
	}
	// second map //
	case 2:
	{
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 250; j++)
			{
				mat[i][j] = ' ';
			}
		}
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 250; j++)
			{
				if (i < 50 && i>45)
				{
					mat[i][j] = 'x';
				}
			}
		}
		for (int i = 24; i < 50; i++)
		{

			for (int j = 0; j < i + 10; j++)
			{
				mat[i][j] = 'x';
			}
		}

		for (int i = 49; i > 24; i--)
		{
			for (int j = 249; j > 200; j--)
			{
				mat[i][j] = 'x';
			}
		}
		for (int i = 49; i > 34; i--)
		{
			for (int j = 200; j > 150; j--)
			{
				mat[i][j] = 'x';
			}
		}

		//print map//
		printMap(mat);
		break;
	}
	// third map //
	case 3:
	{
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 250; j++)
			{
				mat[i][j] = ' ';
			}
		}
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 250; j++)
			{
				if (i < 50 && i>40)
				{
					mat[i][j] = 'x';
				}
			}
		}

		for (int i = 24; i < 50; i++)
		{
			for (int j = 0; j < 62; j++)
			{
				mat[i][j] = 'x';
			}
		}
		for (int i = 24; i < 50; i++)
		{
			for (int j = 249; j > 187; j--)
			{
				mat[i][j] = 'x';
			}
		}

		int k = 117;
		while (k != 175)
		{
			for (int i = 24; i < 50; i++)
			{
				for (int j = 93; j < 125; j++)
				{
					if (i + j == k + 29)
					{
						mat[i][j] = 'x';
					}
				}
			}
			k++;
		}
		for (int i = 24; i < 50; i++)
		{
			for (int j = 125; j < i + 101; j++)
			{
				mat[i][j] = 'x';
			}
		}
		for (int i = 15; i < 30; i++)
		{
			int j = 123;
			mat[i][j] = 'x';
		}

		//print map//
		printMap(mat);
		break;
	}
	}
	return map;
}

void UpdatePlace(Player *pl, char mat[height][length], int map) {

	time_t choosePLACE;
	srand((unsigned)time(&choosePLACE));
	int placing = rand() % 3;
	printf("%d\n", placing);

	int flag = 0;

	while (flag != 4)
	{
		if (map == 1)
		{
			if (placing == 0)
			{
				flag++;
				if (mat[24][24] == '1' || mat[24][24] == '2' || mat[24][24] == '3' || mat[24][24] == '4')
					placing++;
			}

			if (placing == 1)
			{
				flag++;
				if (mat[24][224] == '1' || mat[24][224] == '2' || mat[24][224] == '3' || mat[24][224] == '4')
				{
					placing++;
				}
			}
			if (placing == 2)
			{
				flag++;
				if (mat[40][65] == '1' || mat[40][65] == '2' || mat[40][65] == '3' || mat[40][65] == '4')
				{
					placing++;
				}
			}
			if (placing == 3)
			{
				flag++;
				if (mat[40][184] == '1' || mat[40][184] == '2' || mat[40][184] == '3' || mat[40][184] == '4')
				{
					placing = 0;
				}
			}
		}
		if (map == 2)
		{
			if (placing == 0)
			{
				flag++;
				if (mat[23][17] == '1' || mat[23][17] == '2' || mat[23][17] == '3' || mat[23][17] == '4')
					placing++;
			}

			if (placing == 1)
			{
				flag++;
				if (mat[24][225] == '1' || mat[24][225] == '2' || mat[24][225] == '3' || mat[24][225] == '4')
				{
					placing++;
				}
			}
			if (placing == 2)
			{
				flag++;
				if (mat[45][100] == '1' || mat[45][100] == '2' || mat[45][100] == '3' || mat[45][100] == '4')
				{
					placing++;
				}
			}
			if (placing == 3)
			{
				flag++;
				if (mat[34][175] == '1' || mat[34][175] == '2' || mat[34][175] == '3' || mat[34][175] == '4')
				{
					placing = 0;
				}
			}
		}
		if (map == 3)
		{
			if (placing == 0)
			{
				flag++;
				if (mat[23][30] == '1' || mat[23][30] == '2' || mat[23][30] == '3' || mat[23][30] == '4')
					placing++;
			}

			if (placing == 1)
			{
				flag++;
				if (mat[23][218] == '1' || mat[23][218] == '2' || mat[23][218] == '3' || mat[23][218] == '4')
				{
					placing++;
				}
			}
			if (placing == 2)
			{
				flag++;
				if (mat[40][83] == '1' || mat[40][83] == '2' || mat[40][83] == '3' || mat[40][83] == '4')
				{
					placing++;
				}
			}
			if (placing == 3)
			{
				flag++;
				if (mat[40][167] == '1' || mat[40][167] == '2' || mat[40][167] == '3' || mat[40][167] == '4')
				{
					placing = 0;
				}
			}
		}
	}

	switch (placing) {
	case 0:
		if (map == 1)
		{
			pl->i = 24;
			pl->j = 24;
		}
		else if (map == 2)
		{
			pl->i = 23;
			pl->j = 17;
		}
		else
		{
			pl->i = 23;
			pl->j = 30;
		}
		break;
	case 1:
		if (map == 1)
		{
			pl->i = 24;
			pl->j = 224;
		}
		else if (map == 2)
		{
			pl->i = 24;
			pl->j = 225;
		}
		else
		{
			pl->i = 23;
			pl->j = 218;
		}
		break;
	case 2:
		if (map == 1)
		{
			pl->i = 40;
			pl->j = 65;
		}
		else if (map == 2)
		{
			pl->i = 45;
			pl->j = 100;
		}
		else
		{
			pl->i = 40;
			pl->j = 83;
		}
		break;
	case 3:
		if (map == 1)
		{
			pl->i = 40;
			pl->j = 184;
		}
		else if (map == 2)
		{
			pl->i = 34;
			pl->j = 175;
		}
		else
		{
			pl->i = 40;
			pl->j = 167;
		}
		break;
	}
	mat[pl->i][pl->j] = pl->id;

}

void printMap(char mat[height][length])
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 250; j++)
		{
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
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
	////writeNewPlayerToDatabase("test.txt", "Keren");
	//writeNewPlayerToDatabase("test.txt", "Keren");
	//writeNewPlayerToDatabase("test.txt", "Viktor");
	//writeNewPlayerToDatabase("test.txt", "Yogev");
	//writeNewPlayerToDatabase("test.txt", "Nico");

	//updatePlayer("test.txt", "Keren", 1);
	//updatePlayer("test.txt", "Keren", 1);
	//updatePlayer("test.txt", "Viktor", 1);
	//updatePlayer("test.txt", "Viktor", -1);
	//updatePlayer("test.txt", "Yogev", 1);
	//updatePlayer("test.txt", "Nico", 1);
	//updatePlayer("test.txt", "Nico", 1);
	//updatePlayer("test.txt", "Nico", -1);

	//highscoreTable("test.txt");
}

void movement(char mat[height][length], Player *pl) {
	int count = 5, steps = 0, x = pl->i, y = pl->j, tempcount = 0;
	char dir;
	while (count > 0) {
		printf("\n %s,",pl->Name);
		printf("Which direction would you like to move? L/R/N=don't move \n");
		scanf("%c", &dir);
		getchar();
		if ((dir >= 65) && (dir <= 90)) {
			dir = dir + 32;
		}
		if (dir == 'n') {
			break;
		}
		printf("You have %d steps left. \nHow many steps would you like to move?\n", count);
		scanf("%d", &steps);
		getchar();
		int stepflag = steps;
		tempcount = 0;
		int oldy = 0;
		int oldx = 0;
		if (dir == 'r') {
			oldy = y;
			oldx = x;
			while (steps > 0) {
				//*regular movement right*//
				if ((mat[x][y + 1] == ' ') && (mat[x + 1][y + 1] == 'x') && ((y + 1) != 249)) {
					tempcount++;
					steps--;
					y++;
				}
				//*right and down*//
				else if ((mat[x][y + 1] == ' ') && (mat[x + 1][y + 1] == ' ') && ((y + 1) != 249) && (mat[x + 2][y + 1] == 'x')) {
					tempcount++;
					steps--;
					y++;
					x++;
				}
				//*right and up*//
				else if ((mat[x][y + 1] == 'x') && (mat[x + 1][y + 1] == 'x') && ((y + 1) != 249) && (mat[x - 1][y + 1] == ' ')) {
					tempcount++;
					steps--;
					y++;
					x--;
				}
			}
			if ((tempcount == stepflag) && ((count - tempcount) >= 0)) {
				mat[oldx][oldy] = ' ';
				count = count - tempcount;
				printMap(mat);
				printf("MOVED! %d steps left!\n", count);
			}
			else {
				printf("can't move, choose other direction or fewer steps \n");
				break;
			}
		}
		if (dir == 'l') {
			oldy = y;
			oldx = x;
			while (steps > 0) {
				//*regular movement left*//
				if ((mat[x][y - 1] == ' ') && (mat[x + 1][y - 1] == 'x') && ((y + 1) != 0)) {
					tempcount++;
					steps--;
					y--;
				}
				//*left and down*//
				else if ((mat[x][y - 1] == ' ') && (mat[x + 1][y - 1] == ' ') && ((y + 1) != 0) && (mat[x + 2][y - 1] == 'x')) {
					tempcount++;
					steps--;
					y--;
					x++;
				}
				//*left and up*//
				else if ((mat[x][y - 1] == 'x') && (mat[x + 1][y - 1] == 'x') && ((y + 1) != 0) && (mat[x - 1][y - 1] == ' ')) {
					tempcount++;
					steps--;
					y--;
					x--;
				}
			}
			if ((tempcount == stepflag) && ((count - tempcount) >= 0)) {
				mat[oldx][oldy] = ' ';
				count = count - tempcount;
				printMap(mat);
				printf("MOVED! %d steps left!\n", count);
			}
			else {
				printf("can't move, choose other direction or fewer steps \n");
				y = oldy;
				x = oldx;
				break;
			}
		}
	}
	pl->i = x;
	pl->j = y;
	mat[pl->i][pl->j] = pl->id;

}
