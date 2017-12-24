#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void game();
void maps();
void rules();
void score();
void writeNewPlayerToDatabase(char* fileName, char* userName);
void updatePlayer(char *fileName, char* userName, int upDown);
int returnWin(char* fileName, char* playerName);
int returnLose(char* fileName, char* playerName);
void highscoreTable(char *players);
void linearShot(char board[][10], int x, int y);
float returnRad(float deg);
int return_Y_value_linearshot(int x, float m, int n);


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
	maps();
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
	writeNewPlayerToDatabase("test.txt", "Keren");
	writeNewPlayerToDatabase("test.txt", "Keren");
	writeNewPlayerToDatabase("test.txt", "Viktor");
	writeNewPlayerToDatabase("test.txt", "Yogev");
	writeNewPlayerToDatabase("test.txt", "Nico");
	
	updatePlayer("test.txt", "Keren", 1);
	updatePlayer("test.txt", "Keren", 1);
	updatePlayer("test.txt", "Viktor", 1);
	updatePlayer("test.txt", "Viktor", -1);
	updatePlayer("test.txt", "Yogev", 1);
	updatePlayer("test.txt", "Nico", 1);
	updatePlayer("test.txt", "Nico", 1);
	updatePlayer("test.txt", "Nico", -1);
	
	highscoreTable("test.txt");
}

void maps(){
	{
		int choise=0, map;
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
			for (int i = 0;i < 50;i++)
			{
				for (int j = 0;j < 250;j++)
				{
					mat[i][j] = ' ';
				}
			}
			for (int i = 0;i < 50;i++)
			{
				for (int j = 0;j < 250;j++)
				{
					if (i < 50 && i>45)
					{
						mat[i][j] = 'x';
					}
				}
			}
			for (int i = 24;i < 50;i++)
			{

				for (int j = 0;j < i+10 ;j++)
				{
					mat[i][j] = 'x';
				}
			}

			for (int i = 49;i > 24;i--)
			{
				for (int j = 249;j > 200;j--)
				{
					mat[i][j] = 'x';
				}
			}
			for (int i = 49;i > 34;i--)
			{
				for (int j = 200;j > 150;j--)
				{
					mat[i][j] = 'x';
				}
			}

			//print//
			for (int i = 0;i < 50;i++)
			{
				for (int j = 0;j < 250;j++)
				{
					printf("%c", mat[i][j]);
				}
				printf("\n");
			}
			break;
		}
		case 1:
		{
			for (int i = 0;i < 50;i++)
			{
				for (int j = 0;j < 250;j++)
				{
					mat[i][j] = ' ';
				}
			}
			for (int i = 0;i < 50;i++)
			{
				for (int j = 0;j < 250;j++)
				{
					if (i < 50 && i>40)
					{
						mat[i][j] = 'x';
					}
				}
			}
			for (int i = 0;i < 49;i++)
			{

				for (int j = 0;j < i ;j++)
				{
					mat[i][j] = 'x';
				}
			}
			// left st//
			int k = 249;
			while (k != 300)
			{
				for (int i = 0;i < 50;i++)
				{
					for (int j = 199;j < 250;j++)
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
			for (int i = 0;i < 50;i++)
			{
				for (int j = 0;j < 250;j++)
				{
					printf("%c", mat[i][j]);
				}
				printf("\n");
			}

			break;
		}
		case 3:
		{
			for (int i = 0;i < 50;i++)
			{
				for (int j = 0;j < 250;j++)
				{
					mat[i][j] = ' ';
				}
			}
			for (int i = 0;i < 50;i++)
			{
				for (int j = 0;j < 250;j++)
				{
					if (i < 50 && i>40)
					{
						mat[i][j] = 'x';
					}
				}
			}

			for (int i = 24;i < 50;i++)
			{
				for (int j = 0;j < 62;j++)
				{
					mat[i][j] = 'x';
				}
			}
			for (int i = 24;i < 50;i++)
			{
				for (int j = 249;j > 187;j--)
				{
					mat[i][j] = 'x';
				}
			}
			
			int k = 117;
			while (k != 175)
			{
				for (int i = 24;i < 50;i++)
				{
					for (int j = 93;j < 125;j++)
					{
						if (i + j == k+29)
						{
							mat[i][j] = 'x';
						}
					}
				}
				k++;
			}
			for (int i = 24;i < 50;i++)
			{
				for (int j = 125;j < i+101;j++)
				{
					mat[i][j] = 'x';
				}
			}
			for (int i = 15;i < 30;i++)
			{
				int j = 123;
				mat[i][j] = 'x';
			}

			//print//
			for (int i = 0;i < 50;i++)
			{
				for (int j = 0;j < 250;j++)
				{
					printf("%c", mat[i][j]);
				}
				printf("\n");
			}
			break;
		}
		}

}
}

void writeNewPlayerToDatabase(char* fileName, char* userName) {
	FILE *fp;
	char buff[10];
	int flag = 0;
	fp = fopen(fileName, "r");

	if (fp == NULL) {
		exit(1);
	}
	while (fscanf(fp,"%s",buff)!=EOF){
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

void updatePlayer(char *fileName, char* userName, int upDown) {
	FILE *fp;
	char buff[10];
	int flag = 0;
	char temp='0';
	fp = fopen(fileName, "r+");

	if (fp == NULL) {
		exit(1);
	}
	if (upDown > 0) {
		while (strcmp(buff,userName)!=0) {
			fscanf(fp, "%s", buff);
		}
		
		fscanf(fp, "%s", buff);
		//printf("buff is: %s\n", buff);
		buff[0] = buff[0]++;
		//printf("buff is: %s\n", buff);
		fseek(fp, -1, SEEK_CUR);
		fputc(buff[0], fp);
		fseek(fp, 0, SEEK_CUR);
		
	}
	else {
		while (strcmp(buff, userName) != 0) {
			fscanf(fp, "%s", buff);
		}
		fscanf(fp, "%s", buff);
		fscanf(fp, "%s", buff);
		printf("buff is: %s\n", buff);
		buff[0] = buff[0]++;
		printf("buff is: %s\n", buff);
		fseek(fp, -1, SEEK_CUR);
		fputc(buff[0], fp);
		fseek(fp, 0, SEEK_CUR);

	}

	fclose(fp);
}
int returnWin(char* fileName, char* playerName) {
	//printf("tsetttt\n");
	char buff[10];
	FILE *fp;
	fp = fopen(fileName, "r");
	//printf("%s\n",fileName);
	if (fp==NULL) { exit(1); }
	//printf("test returnwin\n");
	while (strcmp(buff, playerName) != 0) {
		fscanf(fp, "%s", buff);
	}
	fscanf(fp, "%s", buff);
	//printf("buff from returnwin is: %s \t%c\n", buff, buff[0]);
	//printf("%d\n", atoi(buff));
	return atoi(buff);
}
int returnLose(char* fileName, char* playerName) {
	char buff[10];
	FILE *fp;
	fp = fopen(fileName, "r");
	if (!fp) { exit(1); }
	while (strcmp(buff, playerName) != 0) {
		fscanf(fp, "%s", buff);
	}
	fscanf(fp, "%s", buff);
	fscanf(fp, "%s", buff);
	//printf("buff from returnwin is: %s \t%c\n", buff, buff[0]);
	return atoi(buff);
}



void highscoreTable(char *players) {
	char buffName[10], swapName[10];
	int counter = 0,temp=0, swapWin=0, swapLose=0;
	FILE* fpPlayers, *fpHighscoreTable;
	fpPlayers = fopen(players, "r");
	if (fpPlayers == NULL) { return exit(1); }
	fpHighscoreTable = fopen("HighscoreTable.txt", "w");
	if (fpHighscoreTable == NULL) { return exit(1); }
	//printf("test3\n");
	while (fscanf(fpPlayers, buffName) != EOF) {
		
		counter++;
		fscanf(fpPlayers,"%s", buffName);//win
		fscanf(fpPlayers, "%s", buffName);//lose
	}
	counter -= 2;
	//char** arrName = (char*)malloc(sizeof(char)*counter);
	//printf("test2\n");
	char **arrName = malloc(counter * sizeof(char *)); // Allocate row pointers
	for (int i = 0; i < counter; i++)
		arrName[i] = malloc(10* sizeof(char));

	arrName[counter-1] = '\0';

	int* arrWin = (int)malloc(sizeof(int)*counter);
	int* arrLose = (int)malloc(sizeof(int)*counter);
	fseek(fpPlayers, 0, SEEK_SET);
	//printf("test1\n");
	while (fscanf(fpPlayers, "%s",buffName) != EOF) {
		//printf("test while\n");
		//printf("buff name: %s\n", buffName);
		strcpy(arrName[temp], buffName);
		//printf("arrname is: %s\n",arrName[temp]);
		fscanf(fpPlayers,"%s", buffName);
		//printf("why keren why???\n");
		arrWin[temp] = returnWin(players, arrName[temp]);
		//printf("why?????\n");
		fscanf(fpPlayers,"%s", buffName);
		arrLose[temp] = returnLose(players, arrName[temp]);
		temp++;
		//printf("temp is: %d\n", temp);
	}
	//printf("test\n");
	fseek(fpPlayers, 0, SEEK_SET);

	for (int i = counter - 2; i >= 0; i--) {
		//printf("counter is: %d\n", counter);
		printf("name: %s win: %d lose: %d\n", arrName[i], arrWin[i],arrLose[i]);
		//fprintf(fpHighscoreTable, "%s\t\t%d\t\t  %d\n", arrName[i], arrWin[i], arrLose[i]);
	}

	for (int i = 0; i < (counter - 1); i++)
	{
		for (int j = 0; j < counter - i - 1; j++)
		{
			//printf("name: %s\n", arrName[j]);
			if (arrWin[j] < arrWin[j + 1]) 
			{
				swapWin = arrWin[j];
				arrWin[j] = arrWin[j + 1];
				arrWin[j + 1] = swapWin;

				swapLose = arrLose[j];
				arrLose[j] = arrLose[j + 1];
				arrLose[j + 1] = swapLose;

				strcpy(swapName, arrName[j]);
				strcpy(arrName[j], arrName[j + 1]);
				strcpy(arrName[j + 1] , swapName);
			}
			
			else if (arrWin[j] == arrWin[j + 1]) {
				if (arrLose[j] > arrLose[j + 1])
				{
					swapWin = arrWin[j];
					arrWin[j] = arrWin[j + 1];
					arrWin[j + 1] = swapWin;

					swapLose = arrLose[j];
					arrLose[j] = arrLose[j + 1];
					arrLose[j + 1] = swapLose;

					strcpy(swapName, arrName[j]);
					strcpy(arrName[j], arrName[j + 1]);
					strcpy(arrName[j + 1], swapName);
				}
			}
		}
	}
	for (int i =0 ; i<counter - 1; i++) {
		//printf("counter is: %d\n", counter);
		printf("name: %s win: %d\n", arrName[i],arrWin[i]);
		fprintf(fpHighscoreTable, "%s\t\t%d\t\t  %d\n", arrName[i],arrWin[i],arrLose[i]);
	}


	fclose(fpHighscoreTable);
	fclose(fpPlayers);
}
void linearShot(char board[][10], int x, int y) {
	int m, n=0, xtemp = 0, y_val=0;
	int flag = 0;
	float angleChoice, radFromDeg, angleRad;
	char leftRight[10];
	printf("Are you shooting left or right?\nEnter your choice: 'left' or 'right'\n");
	scanf("%s", leftRight);
	if (strcmp(leftRight, "right") == 0) {
		printf("Choose angle to shoot from 0-90:\n");
		scanf("%f", &angleChoice);
		printf("angle choice: %f\n", angleChoice);
		radFromDeg = ((float)(angleChoice*3.14) /(float) 180.0);//returnRad(angleChoice);
		printf("radfromdeg is: %f\n", radFromDeg);
		angleRad = tan(radFromDeg);
		printf("angle rad :%f\n", angleRad);
		printf("test3\n");
		while (flag==0){
			y_val = 0;
			y_val = return_Y_value_linearshot(xtemp, 1.0, n);

			printf("y_val is: %d ",y_val);
			printf("xtemp is: %d\n", xtemp);
			if ( y_val== 9) { flag = 1; }
			if (xtemp == 9) { flag = 1; }
			/*
			return_Y_value_linearshot(xtemp, angleRad, y) < 50 && board[return_Y_value_linearshot(xtemp, angleRad, y)][xtemp] != ' '&&
			board[return_Y_value_linearshot(xtemp, angleRad, y)][xtemp] != 'X'&&
			board[return_Y_value_linearshot(xtemp, angleRad, y)][xtemp] != 'T'&& xtemp<250) {
			*/
			
			//printf("test\n");
			
			//printf("char is: %c\t", board[y_val][xtemp]);
			//printf("between\n");
			board[y_val][xtemp] = '*';
			//printf("test4\n");
			xtemp++;
		}
		
	}
	
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	printf("over linear\n");
}
float returnRad(float deg) {
	printf("val is: %f\n deg: %f\nacos: %f", (deg*acos(-1) / 180),&deg,acos(-1));
	return (deg*3.14 / 180);

}
int return_Y_value_linearshot(int x, float m, int n) {
	//printf("y val: %d\n", (int)((m*x) + n));
	int result = 0;
	result= ((((int)m)*x) + n);
	return result;

}
