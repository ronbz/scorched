
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<math.h>

typedef struct Player {
	char Name[10];
	int i;
	int j;
	int Lives;
	int id;
}Player;


void updatePlayer(char fileName[], char* userName, int upDown) {
	FILE *fp;
	char buff[10];
	int flag = 0;
	char temp = '0';
	fp = fopen(fileName, "r+");

	if (fp == NULL) {
		exit(1);
	}
	if (upDown > 0) {
		while (strcmp(buff, userName) != 0) {
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
void Player_get_hit(char board[][250], int x, int y, Player *player) {
	player->Lives--;
	if (player->Lives == 0) {
		printf("PLAYER %c has no lives left, %s has been KILLED!\n", board[player->i][player->j], player->Name);
		printf("x: %d\ty: %d\n", x, y);
		board[y][x] = ' ';
		char buff[10];
		strcpy(buff, player->Name);
		updatePlayer("test.txt", buff, -1);

	}
	else {
		printf("PLAYER %c got HIT!, %s has %d live left!\n", board[x][y], player->Name, player->Lives);
		printf("x: %d\ty: %d\n", x, y);
	}

}
void linearShot(char board[][250], int x, int y,Player* p1,Player *p2,Player *p3,Player *p4) {
	
	/*MUST CHANGE BOARD BORDERS FOR THE REAL BOARD!!*/
	/*NEED TO ADD TANK STRUCT FOR X,Y CALIBRATION*/
	/*NEED TO ADD 'HIT' FUNCTION*/
	int m, n=0, xtemp = 0, y_val=0;
	int flag = 0;
	float angleChoice, radFromDeg, angleRad;
	char leftRight[10];
	printf("Are you shooting left or right?\nEnter your choice: 'left' or 'right'\n");
	scanf("%s", leftRight);
	if (strcmp(leftRight, "right") == 0) {
		printf("Choose angle to shoot from 0-90:\n");
		scanf("%f", &angleChoice);
		//printf("angle choice: %f\n", angleChoice);
		radFromDeg = ((float)(angleChoice*3.14) /(float) 180.0);//returnRad(angleChoice);
		//printf("radfromdeg is: %f\n", radFromDeg);
		angleRad = tan(radFromDeg);
		//printf("angle rad :%f\n", angleRad);
		//printf("test3\n");
		
		while (flag==0){
			int y_val_temp = 0;
			y_val_temp = angleRad*(xtemp);
			//printf("y_val is: %d ",y_val_temp);
			//printf("xtemp is: %d\n", xtemp);
			if ( y_val_temp+y> 49) { flag = 1; }
			if (xtemp+x > 249) { flag = 1; }
			if (board[49- y_val_temp - y][xtemp+x] == 'x') { flag = 1; }
			if (board[49- y_val_temp - y][xtemp+x] == '1' || board[49- y_val_temp - y][xtemp+x] == '2' || board[49- y_val_temp - y][xtemp+x] == '3' || board[49- y_val_temp - y][xtemp+x] == '4') {
				flag = 1;
				//!function for hit!
				if (board[49 - y_val_temp-y][xtemp+x] == '1'&&p1!=NULL) {Player_get_hit(board, p1->i, p1->j, p1);}
				if (board[49 - y_val_temp - y][xtemp+x] == '2'&&p2 != NULL) { Player_get_hit(board, p2->i, p2->j, p2); }
				if (board[49 - y_val_temp - y][xtemp+x] == '3'&&p3 != NULL) { Player_get_hit(board, p3->i, p3->j, p3); }
				if (board[49 - y_val_temp - y][xtemp+x] == '4'&&p4 != NULL) { Player_get_hit(board, p4->i, p4->j, p4); }
			}
			if (flag == 0) {board[49 - y_val_temp - y][xtemp+x] = '*';}
			xtemp++;
		}
		
	}
	else {
		printf("Choose angle to shoot from 0-90:\n");
		scanf("%f", &angleChoice);
		//printf("angle choice: %f\n", angleChoice);
		radFromDeg = ((float)(angleChoice*3.14) / (float) 180.0);//returnRad(angleChoice);
		//printf("radfromdeg is: %f\n", radFromDeg);
		angleRad = tan(radFromDeg);
		//printf("angle rad :%f\n", angleRad);
		//xtemp = 49;
		while (flag == 0) {
			int y_val_temp = 0;			
			//y_val = return_Y_value_linearshot(xtemp, 1.0, n);
			y_val_temp = angleRad*(xtemp);
			//printf("y_val is: %d ", y_val_temp);
			//printf("xtemp is: %d\n", xtemp);
			if (y_val_temp - y> 49) { flag = 1; }
			if (xtemp+x >249) { flag = 1; }
			if (board[49 - y_val_temp - y][249-xtemp-x] == 'x') { flag = 1; }
			if (board[49 - y_val_temp - y][249- xtemp - x] == '1' || board[49 - y_val_temp - y][249- xtemp - x] == '2' || board[49 - y_val_temp - y][249- xtemp - x] == '3' || board[49 - y_val_temp - y][249- xtemp - x] == '4') {
				flag = 1;
				//!function for hit!
				if (board[49 - y_val_temp - y][249- xtemp - x] == '1'&&p1 != NULL) { Player_get_hit(board, p1->i, p1->j, p1); }
				if (board[49 - y_val_temp - y][249- xtemp - x] == '2'&&p2 != NULL) { Player_get_hit(board, p2->i, p2->j, p2); }
				if (board[49 - y_val_temp - y][249- xtemp - x] == '3'&&p3 != NULL) { Player_get_hit(board, p3->i, p3->j, p3); }
				if (board[49 - y_val_temp - y][249- xtemp - x] == '4'&&p4 != NULL) { Player_get_hit(board, p4->i, p4->j, p4); }
			}
			if (flag == 0) { board[49 - y_val_temp - y][249- xtemp - x] = '*'; }
			xtemp++;
		}
	}
	
	for (int i = 0; i <= 49; i++) {
		for (int j = 0; j <= 249; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	//printf("over linear\n");
}
float returnRad(float deg) {
	printf("val is: %f\n deg: %f\nacos: %f", (deg*acos(-1) / 180),&deg,acos(-1));
	return (deg*3.14 / 180);

}

void parabolicShot(char board[][250], int x, int y, Player* p1, Player *p2, Player *p3, Player *p4) {
	float a = 0, b = 0, d = 1; int c = y, xtemp = 0;
	int flag = 0;
	char leftRight[10];
	printf("Are you shooting left or right?\nEnter your choice: 'left' or 'right'\n");
	scanf("%s", leftRight);
	if (strcmp(leftRight, "right") == 0) {
		printf("For the equation 'y=a(x*1/d)^2+b(x*1/d)+c'\n");
		printf("Choose the value for 'a' : \n");
		scanf("%f", &a);
		printf("Choose the value for 'b' :\n");
		scanf("%f", &b);
		printf("Choose the value for 'd'\n*DISCLOSURE*'d' is used mostly for distance\n :\n");
		scanf("%f", &d);
		while (flag == 0) {
			int y_val_temp = 0;
			
			y_val_temp = -a*pow(((float)(xtemp/d)), 2) + b*((float)(xtemp/d))+c;

			printf("y_val is: %d ", y_val_temp);
			printf("xtemp is: %d\n", xtemp);
			if (y_val_temp + y> 49) { flag = 1; }
			if (y_val_temp < 0) { flag = 1; }
			if (xtemp + x > 249) { flag = 1; }
			if (board[49 - y_val_temp - y][xtemp + x] == 'x') { flag = 1; }
			if (board[49 - y_val_temp - y][xtemp + x] == '1' || board[49 - y_val_temp - y][xtemp + x] == '2' || board[49 - y_val_temp - y][xtemp + x] == '3' || board[49 - y_val_temp - y][xtemp + x] == '4') {
				flag = 1;
				//!function for hit!
				if (board[49 - y_val_temp - y][xtemp + x] == '1'&&p1 != NULL) { Player_get_hit(board, p1->i, p1->j, p1); }
				if (board[49 - y_val_temp - y][xtemp + x] == '2'&&p2 != NULL) { Player_get_hit(board, p2->i, p2->j, p2); }
				if (board[49 - y_val_temp - y][xtemp + x] == '3'&&p3 != NULL) { Player_get_hit(board, p3->i, p3->j, p3); }
				if (board[49 - y_val_temp - y][xtemp + x] == '4'&&p4 != NULL) { Player_get_hit(board, p4->i, p4->j, p4); }
			}
			if (flag == 0) { board[49 - y_val_temp - y][xtemp + x] = '*'; }
			xtemp++;
		}
	
	}
	else{
		printf("For the equation 'y=ax^2+bx+c'\n");
		printf("Choose the value for 'a' : \n");
		scanf("%f", &a);
		printf("Choose the value for 'b' :\n");
		scanf("%f", &b);
		printf("Choose the value for 'd'\n*DISCLOSURE*'d' is used mostly for distance\n :\n");
		scanf("%f", &d);
		while (flag == 0) {
			int y_val_temp = 0;
			
			y_val_temp = -a*pow(((float)(-xtemp / d)), 2) - b*((float)(-xtemp / d)) + c;
		//	printf("y_val is: %d ", y_val_temp);
			//printf("xtemp is: %d\n", xtemp);
			if (y_val_temp - y> 49) { flag = 1; }
			if (y_val_temp < 0) { flag = 1; }

			if (xtemp + x >249) { flag = 1; }
			if (board[49 - y_val_temp - y][249 - xtemp - x] == 'x') { flag = 1; }
			if (board[49 - y_val_temp - y][249 - xtemp - x] == '1' || board[49 - y_val_temp - y][249 - xtemp - x] == '2' || board[49 - y_val_temp - y][249 - xtemp - x] == '3' || board[49 - y_val_temp - y][249 - xtemp - x] == '4') {
				flag = 1;
				//!function for hit!
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '1'&&p1 != NULL) { Player_get_hit(board, p1->i, p1->j, p1); }
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '2'&&p2 != NULL) { Player_get_hit(board, p2->i, p2->j, p2); }
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '3'&&p3 != NULL) { Player_get_hit(board, p3->i, p3->j, p3); }
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '4'&&p4 != NULL) { Player_get_hit(board, p4->i, p4->j, p4); }
			}
			if (flag == 0) { board[49 - y_val_temp - y][249 - xtemp - x] = '*'; }
			xtemp++;
		}

	}

	for (int i = 0; i <= 49; i++) {
		for (int j = 0; j <= 249; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}


}

void logShot(char board[][250], int x, int y, Player* p1, Player *p2, Player *p3, Player *p4) {
	float a = 1, base = 1;
	int flag = 0, xtemp = 1;
	char leftRight[10];

	printf("Are you shooting left or right?\nEnter your choice: 'left' or 'right'\n");
	scanf("%s", leftRight);
	printf("From the equation y=a*log(base)(argument)\n");
	printf("Enter value for 'a': \n");
	scanf("%f", &a);
	printf("Enter value for the base: \n");
	scanf("%f", &base);
	if (strcmp(leftRight, "right") == 0) {
		
		while (flag == 0) {
			int y_val_temp = 0;

			y_val_temp = a*(log(xtemp) / log(base));

			//printf("y_val is: %d ", y_val_temp);
			//printf("xtemp is: %d\n", xtemp);
			if (y_val_temp + y> 49) { flag = 1; }
			if (y_val_temp < 0) { flag = 1; }
			if (xtemp + x > 249) { flag = 1; }
			if (board[49 - y_val_temp - y][xtemp + x-1] == 'x') { flag = 1; }
			if (board[49 - y_val_temp - y][xtemp + x-1] == '1' || board[49 - y_val_temp - y][xtemp + x-1] == '2' || board[49 - y_val_temp - y][xtemp + x-1] == '3' || board[49 - y_val_temp - y][xtemp + x-1] == '4') {
				flag = 1;
				//!function for hit!
				if (board[49 - y_val_temp - y][xtemp + x-1] == '1'&&p1 != NULL) { Player_get_hit(board, p1->i, p1->j, p1); }
				if (board[49 - y_val_temp - y][xtemp + x-1] == '2'&&p2 != NULL) { Player_get_hit(board, p2->i, p2->j, p2); }
				if (board[49 - y_val_temp - y][xtemp + x-1] == '3'&&p3 != NULL) { Player_get_hit(board, p3->i, p3->j, p3); }
				if (board[49 - y_val_temp - y][xtemp + x-1] == '4'&&p4 != NULL) { Player_get_hit(board, p4->i, p4->j, p4); }
			}
			if (flag == 0) { board[49 - y_val_temp - y][xtemp + x-1] = '*'; }
			xtemp++;
		}
	
	}
	else {

		while (flag == 0) {
			int y_val_temp = 0;

			y_val_temp = a*(log(xtemp) / log(base));

			//	printf("y_val is: %d ", y_val_temp);
			//printf("xtemp is: %d\n", xtemp);
			if (y_val_temp - y> 49) { flag = 1; }
			if (y_val_temp < 0) { flag = 1; }

			if (xtemp + x >249) { flag = 1; }
			if (board[49 - y_val_temp - y][249 - xtemp - x] == 'x') { flag = 1; }
			if (board[49 - y_val_temp - y][249 - xtemp - x] == '1' || board[49 - y_val_temp - y][249 - xtemp - x] == '2' || board[49 - y_val_temp - y][249 - xtemp - x] == '3' || board[49 - y_val_temp - y][249 - xtemp - x] == '4') {
				flag = 1;
				//!function for hit!
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '1'&&p1 != NULL) { Player_get_hit(board, p1->i, p1->j, p1); }
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '2'&&p2 != NULL) { Player_get_hit(board, p2->i, p2->j, p2); }
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '3'&&p3 != NULL) { Player_get_hit(board, p3->i, p3->j, p3); }
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '4'&&p4 != NULL) { Player_get_hit(board, p4->i, p4->j, p4); }
			}
			if (flag == 0) { board[49 - y_val_temp - y][249 - xtemp - x] = '*'; }
			xtemp++;
		}

	}
	for (int i = 0; i <= 49; i++) {
		for (int j = 0; j <= 249; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}


}

void crazyShot(char board[][250], int x, int y, Player* p1, Player *p2, Player *p3, Player *p4) {
	int flag = 0, xtemp = 0;
	float a, b;
	char leftRight[10];
	printf("Are you shooting left or right?\nEnter your choice: 'left' or 'right'\n");
	scanf("%s", leftRight);
	printf("From the equation y=a*sin(bx) \n");
	printf("Enter the value of 'a'\n");
	scanf("%f", &a);
	printf("Enter the value of 'b'\n");
	scanf("%f", &b);

	if (strcmp(leftRight, "right") == 0) {

		while (flag == 0) {
			int y_val_temp = 0;

			y_val_temp = a*sin(b*xtemp*(3.14/180));

			printf("y_val is: %d ", y_val_temp);
			printf("xtemp is: %d\n", xtemp);
			if (y_val_temp + y> 49) { flag = 1; }
			//if (y_val_temp < 0) { flag = 1; }
			if (xtemp + x > 249) { flag = 1; }
			if (board[49 - y_val_temp - y][xtemp + x ] == 'x') { flag = 1; }
			if (board[49 - y_val_temp - y][xtemp + x ] == '1' || board[49 - y_val_temp - y][xtemp + x] == '2' || board[49 - y_val_temp - y][xtemp + x] == '3' || board[49 - y_val_temp - y][xtemp + x ] == '4') {
				flag = 1;
				//!function for hit!
				if (board[49 - y_val_temp - y][xtemp + x ] == '1'&&p1 != NULL) { Player_get_hit(board, p1->i, p1->j, p1); }
				if (board[49 - y_val_temp - y][xtemp + x ] == '2'&&p2 != NULL) { Player_get_hit(board, p2->i, p2->j, p2); }
				if (board[49 - y_val_temp - y][xtemp + x ] == '3'&&p3 != NULL) { Player_get_hit(board, p3->i, p3->j, p3); }
				if (board[49 - y_val_temp - y][xtemp + x ] == '4'&&p4 != NULL) { Player_get_hit(board, p4->i, p4->j, p4); }
			}
			if (flag == 0) { board[49 - y_val_temp - y][xtemp + x] = '*'; }
			xtemp++;
		}

	}
	else {

		while (flag == 0) {
			int y_val_temp = 0;

			y_val_temp = a*sin(b*xtemp);

			printf("y_val is: %d ", y_val_temp);
			printf("xtemp is: %d\n", xtemp);
			if (y_val_temp - y> 49) { flag = 1; }
			//if (y_val_temp < 0) { flag = 1; }

			if (xtemp + x >249) { flag = 1; }
			if (board[49 - y_val_temp - y][249 - xtemp - x] == 'x') { flag = 1; }
			if (board[49 - y_val_temp - y][249 - xtemp - x] == '1' || board[49 - y_val_temp - y][249 - xtemp - x] == '2' || board[49 - y_val_temp - y][249 - xtemp - x] == '3' || board[49 - y_val_temp - y][249 - xtemp - x] == '4') {
				flag = 1;
				//!function for hit!
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '1'&&p1 != NULL) { Player_get_hit(board, p1->i, p1->j, p1); }
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '2'&&p2 != NULL) { Player_get_hit(board, p2->i, p2->j, p2); }
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '3'&&p3 != NULL) { Player_get_hit(board, p3->i, p3->j, p3); }
				if (board[49 - y_val_temp - y][249 - xtemp - x] == '4'&&p4 != NULL) { Player_get_hit(board, p4->i, p4->j, p4); }
			}
			if (flag == 0) { board[49 - y_val_temp - y][249 - xtemp - x] = '*'; }
			xtemp++;
		}

	}
	for (int i = 0; i <= 49; i++) {
		for (int j = 0; j <= 249; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

int return_Y_value_linearshot(int x, float m, int n) {
	//printf("y val: %d\n", (int)((m*x) + n));
	int result = 0;
	result= ((((int)m)*x) + n);
	return result;

}

void clear_shot_path(char board[][250]) {
	for (int i = 0; i < 49; i++) {
		for (int j = 0; j < 249; j++) {
			if (board[i][j] == '*') { board[i][j] = ' '; }
		}
	}
}

int main() {
	int i, j/*x,y,ty,tx,shot,sangle*/;
	char mat[50][250];
	/*printf("choose place for tank (x,y): \n");
	scanf("%d %d", &x, &y);
	x = x - 1;
	y = y - 1;*/
	for (i = 0; i <= 49; i++) {
		for (j = 0; j <= 249; j++) {
			/*if ((i==x)&&(j==y)) {
			mat[i][j] = ' ';
			}
			else {*/
			mat[i][j] = ' ';
		}
	}
	for (i = 0; i <= 49; i++) {
		for (j = 0; j <= 249; j++) {
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}

/*
	for (i = 0; i < 249; i++) {
		mat[20][i] = 'x';
	}
*/	
	struct Player *p1 = (struct Player*)malloc(sizeof(struct Player));
	struct Player *p2 = (struct Player*)malloc(sizeof(struct Player));
	struct Player *p3 = (struct Player*)malloc(sizeof(struct Player));
	struct Player *p4 = (struct Player*)malloc(sizeof(struct Player));
	p1->i = 20; p1->j = 30; p1->Lives = 2; strcpy(p1->Name, "Yogev");
	mat[p1->i][p1->j] = '1';
	printf("p1 lives before: %d\n", p1->Lives);

	//linearShot(mat, 30, 10,p1,p2=NULL,p3=NULL,p4=NULL);
	//parabolicShot(mat, 0, 10, p1, p2 = NULL, p3 = NULL, p4 = NULL);
	//logShot(mat, 50, 10, p1, p2 = NULL, p3 = NULL, p4 = NULL);

	crazyShot(mat, 100, 25, p1, p2 = NULL, p3 = NULL, p4 = NULL);

	printf("p1 lives after: %d\n", p1->Lives);

	

	/*printf("choose shot type:\n");
	scanf("%d", &shot);
	printf("choose shot angle:");
	scanf("%d", &sangle);
	ty = sangle*x + y;
	tx = ((ty - y) / sangle) + x;

	printf("%d %d", tx, ty);
	*/
	
	return 0;
}


