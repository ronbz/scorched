//magic number//global constants//




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define length 250
#define height 50

typedef struct Player{
	char Name[10];
	int i;
	int j;
	int Lives;
	char id;
}Player;

Player NewPlayer(Player*, int);
void writeNewPlayerToDatabase(char*, char*);
void UpdatePlace(Player*,char[height][length],int);
int CreatMap(char[height][length]);
void printMap(char[height][length]);


int main() {

	int choise,map,counter=0;
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
		NewPlayer(pl1,counter);
		printf("\nenter second player name:\t");
		counter++;
		NewPlayer(pl2, counter);
		map = CreatMap(mat);
		printf("\n\n\nTEST1\n\n\n");
		UpdatePlace(pl1,mat,map);	
		UpdatePlace(pl2,mat,map);
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
		UpdatePlace(pl1,mat,map);
		UpdatePlace(pl2,mat,map);
		UpdatePlace(pl3,mat,map);
		printMap(mat);
		break;

	case 4:
		printf("\nenter first player name:\t");
		counter++;
		NewPlayer(pl1,counter);
		printf("\nenter second player name:\t");
		counter++;
		NewPlayer(pl2,counter);
		printf("\nenter third player name:\t");
		counter++;
		NewPlayer(pl3,counter);
		printf("\nenter fourth player name:\t");
		counter++;
		NewPlayer(pl4,counter);
		map = CreatMap(mat);
		UpdatePlace(pl1,mat,map);
		UpdatePlace(pl2,mat,map);
		UpdatePlace(pl3,mat,map);
		UpdatePlace(pl4,mat,map);
		printMap(mat);
		break;
	}
	return 0;
}

Player NewPlayer(Player *pl,int counter) {
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

	while (map > 3 || map < 1)
	{
		printf("\nwrong entery please try again:\t");
		scanf("%d", &map);
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

void UpdatePlace(Player *pl, char mat[height][length],int map) {

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

/*
int UpdateLIVES(Player pl1) {
//if player loose
pl1.Lives--;
if (pl1.Lives = 0) {
//call function KILL-PLAYER
}
}*/
/*
void writeNewPlayerToDatabase(char* fileName, char* userName) {
	FILE *fp;
	char buff[10];
	int flag = 0;
	fp = fopen(fileName, "r");
	printf("START WRITE\n");
	printf("%s\n", fileName);
	if (fp == NULL)printf("null file\n");
	if (fp == NULL) {
		printf("FILE ERROR line 400\n");
		exit(1);
	}
	while (fscanf(fp, "%s", buff) != EOF) {
		//printf("buff is: %s", buff);
		if (strcmp(userName, buff) == 0) {
			flag = 1;
		}
	}
	fclose(fp);
	fp = fopen(fileName, "a");

	if (fp == NULL) {
		printf("FILE ERROR line 413\n");
		exit(1);
	}
	//printf("test2\n");
	if (flag == 0) {
		fprintf(fp, "%s\t\t0\t\t  0\n", userName);
	}
	fclose(fp);
	printf("END WRITE\n");
}
*/
