
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<math.h>

void linearShot(char board[][50], int x, int y) {
	
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
		printf("angle choice: %f\n", angleChoice);
		radFromDeg = ((float)(angleChoice*3.14) /(float) 180.0);//returnRad(angleChoice);
		printf("radfromdeg is: %f\n", radFromDeg);
		angleRad = tan(radFromDeg);
		printf("angle rad :%f\n", angleRad);
		//printf("test3\n");
		
		while (flag==0){
			int y_val_temp = 0;
			//y_val = return_Y_value_linearshot(xtemp, 1.0, n);

			y_val_temp = angleRad*(xtemp);


			printf("y_val is: %d ",y_val_temp);
			printf("xtemp is: %d\n", xtemp);
			if ( y_val_temp> 49) { flag = 1; }
			if (xtemp > 49) { flag = 1; }
			if (board[49-y_val_temp][xtemp] == 'x') { flag = 1; }
			if (board[49-y_val_temp][xtemp] == '1' || board[49-y_val_temp][xtemp] == '2' || board[49-y_val_temp][xtemp] == '3' || board[49-y_val_temp][xtemp] == '4') {
				flag = 1;
				//!function for hit!
			}
			if (flag == 0) {board[49 - y_val_temp][xtemp] = '*';}
			xtemp++;
		}
		
	}
	else {
		printf("Choose angle to shoot from 0-90:\n");
		scanf("%f", &angleChoice);
		printf("angle choice: %f\n", angleChoice);
		radFromDeg = ((float)(angleChoice*3.14) / (float) 180.0);//returnRad(angleChoice);
		printf("radfromdeg is: %f\n", radFromDeg);
		angleRad = tan(radFromDeg);
		printf("angle rad :%f\n", angleRad);
		//xtemp = 49;
		while (flag == 0) {
			int y_val_temp = 0;
			
			//y_val = return_Y_value_linearshot(xtemp, 1.0, n);

			y_val_temp = angleRad*(xtemp);


			printf("y_val is: %d ", y_val_temp);
			printf("xtemp is: %d\n", xtemp);
			if (y_val_temp> 49) { flag = 1; }
			if (xtemp >49) { flag = 1; }
			if (board[49 - y_val_temp][49-xtemp] == 'x') { flag = 1; }
			if (board[49 - y_val_temp][49-xtemp] == '1' || board[49 - y_val_temp][49-xtemp] == '2' || board[49 - y_val_temp][49-xtemp] == '3' || board[49 - y_val_temp][49-xtemp] == '4') {
				flag = 1;
				//!function for hit!
			}
			if (flag == 0) { board[49 - y_val_temp][49-xtemp] = '*'; }
			xtemp++;
		}



	}
	

	for (int i = 0; i <= 49; i++) {
		for (int j = 0; j <= 49; j++) {
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

int main() {
	int i, j/*x,y,ty,tx,shot,sangle*/;
	char mat[50][50];
	/*printf("choose place for tank (x,y): \n");
	scanf("%d %d", &x, &y);
	x = x - 1;
	y = y - 1;*/
	for (i = 0; i <= 49; i++) {
		for (j = 0; j <= 49; j++) {
			/*if ((i==x)&&(j==y)) {
			mat[i][j] = ' ';
			}
			else {*/
			mat[i][j] = ' ';
		}
	}
	for (i = 0; i <= 49; i++) {
		for (j = 0; j <= 49; j++) {
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	linearShot(mat, 0, 0);


	

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


