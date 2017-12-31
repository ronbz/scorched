
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char Name[10];
	int i;
	int j;
	int Lives;
}Player;

Player NewPlayer();
void writeNewPlayerToDatabase(char*, char*);
void Place0(Player);
void Place1(Player);
void Place2(Player);
void Place3(Player);
void UpdatePlace(Player);
void CreatMap();



int main() {
	int choise;
	Player pl1, pl2, pl3, pl4;
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
		pl1 = NewPlayer();
		printf("\nenter second player name:\t");
		NewPlayer();
		CreatMap();
		UpdatPlace(pl1);
		UpdatPlace(pl2);
		break;
	case 3:
		printf("\nenter first player name:\t");
		NewPlayer();
		printf("\nenter second player name:\t");
		NewPlayer();
		printf("\nenter third player name:\t");
		NewPlayer();
		CreatMap();
		UpdatPlace(pl1);
		UpdatPlace(pl2);
		UpdatPlace(pl3);
		break;

	case 4:
		printf("\nenter first player name:\t");
		NewPlayer();
		printf("\nenter second player name:\t");
		NewPlayer();
		printf("\nenter third player name:\t");
		NewPlayer();
		printf("\nenter fourth player name:\t");
		NewPlayer();
		CreatMap();
		UpdatPlace(pl1);
		UpdatPlace(pl2);
		UpdatPlace(pl3);
		UpdatPlace(pl4);
		break;
	}


	return 0;
}

Player NewPlayer() {
	Player *pl;
	int size = 1;
	pl = (Player*)malloc(size * sizeof(Player));
	if (pl == NULL) {
		exit(1);
	}

	printf("Choose your player name: \n");
	gets(pl->Name);
	//puts(pl1->Name);
	writeNewPlayerToDatabase("test.txt", pl->Name);

	pl->Lives = 2;
	return *pl;
}

void CreateMap() {
	int map;
	char mat[50][250];
	printf("\nplease select the level difficulty (1-3):\t");
	scanf("%d", &map);

	while (map > 3 || map < 1)
	{
		printf("\nwrong entery please try again:\t");
		scanf("%d", &map);
	}

	switch (map)
	{
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

		//print//
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 250; j++)
			{
				printf("%c", mat[i][j]);
			}
			printf("\n");
		}
		break;
	}
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
		// left st//
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
		//print//
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 250; j++)
			{
				printf("%c", mat[i][j]);
			}
			printf("\n");
		}

		break;
	}
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

		//print//
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 250; j++)
			{
				printf("%c", mat[i][j]);
			}
			printf("\n");
		}
		break;
	}
	}

}


void UpdatePlace(Player pl) {

	time_t choosePLACE;
	srand((unsigned)time(&choosePLACE));
	int placing = 0;
	placing = rand() % 3;
	printf("%d\n", placing);
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	if (placing == 0) {
		if (count0 = 0) {
			count0++;
		}
		else placing++;
	}

	if (placing == 1) {
		if (count0 = 0) {
			count0++;
		}
		else placing++;
	}
	if (placing == 2) {
		if (count0 = 0) {
			count0++;
		}
		else placing++;
	}
	if (placing == 3) {
		if (count0 = 0) {
			count0++;
		}
		else placing = 1;
	}



	char MATRIX[50][250];
	switch (placing) {
	case 0:
		Place0(pl);
		break;
	case 1:
		Place1(pl);
		break;
	case 2:
		Place2(pl);
		break;
	case 3:
		Place3(pl);
		break;
	}
	MATRIX[pl.i][pl.j] = 'T';
}


void Place0(Player pl) {
	pl.i = 25;
	pl.j = 25;
}
void Place1(Player pl) {
	pl.i = 25;
	pl.j = 45;
}
void Place2(Player pl) {
	pl.i = 25;
	pl.j = 87;
}
void Place3(Player pl) {
	pl.i = 45;
	pl.j = 163;
}
/*
int UpdateLIVES(Player pl1) {
//if player loose
pl1.Lives--;
if (pl1.Lives = 0) {
//call function KILL-PLAYER
}
}*/

void writeNewPlayerToDatabase(char* fileName, char* userName) {
	FILE *fp;
	char buff[10];
	int flag = 0;
	fp = fopen(fileName, "r");

	if (fp == NULL) {
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
		exit(1);
	}
	//printf("test2\n");
	if (flag == 0) {
		fprintf(fp, "%s\t\t0\t\t  0\n", userName);
	}
	fclose(fp);

}







/*



int main() {

//void startGame()
{


int  map;
char mat[50][250];
/*
*/

/*
return 0;
}


*/
