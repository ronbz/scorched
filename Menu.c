void movement(char mat[height][length], Player *pl) {
	int count = 5, steps = 0, x = pl->i, y = pl->j, tempcount = 0;
	char dir;
	while (count > 0)
	{
		printf("\n %s,", pl->Name);
		printf(" Which direction would you like to move? L/R/N=don't move \n");
		scanf("%c", &dir);
		getchar();
		fflush(stdin);
		while ((dir != 'r') && (dir != 'R') && (dir != 'l') && (dir != 'L') && (dir != 'n') && (dir != 'N')) {
			printf("Wrong key, please try again:\nWhich direction would you like to move? L/R/N=don't move \n");
			getchar();
			scanf("%c", &dir);
			getchar();
			fflush(stdin);
		}
		if ((dir >= 65) && (dir <= 90)) {
			dir = dir + 32;
		}
		if (dir == 'n') {
			break;
		}
		
		printf("You have %d steps left. \nHow many steps would you like to move?\n", count);
		scanf("%d", &steps);
		getchar();
		while (steps > count)
		{
			printf("cant move try again:\t");
			scanf("%d", &steps);
			getchar();
		}
		int stepflag = steps;
		tempcount = 0;
		int oldy = 0;
		int oldx = 0;
		if (dir == 'r') {
			oldy = y;
			oldx = x;
			while (steps > 0) {
				//*regular movement right*//
				if ((mat[x][y + 1] == ' ') && (mat[x + 1][y + 1] == 'x') && ((y + 1) != 250)) {
					tempcount++;
					steps--;
					y++;
				}
				//*right and down*//
				else if ((mat[x][y + 1] == ' ') && (mat[x + 1][y + 1] == ' ') && ((y + 1) != 250) && (mat[x + 2][y + 1] == 'x')) {
					tempcount++;
					steps--;
					y++;
					x++;
				}
				//*right and up*//
				else if ((mat[x][y + 1] == 'x') && (mat[x + 1][y + 1] == 'x') && ((y + 1) != 250) && (mat[x - 1][y + 1] == ' ')) {
					tempcount++;
					steps--;
					y++;
					x--;
				}
				else {
					printf("can't move, choose fewer steps \n");
					y = y - tempcount;
					scanf("%d", &steps);
					getchar();
					stepflag = steps;
					tempcount = 0;
				}
			
			}
			if ((tempcount == stepflag) && ((count - tempcount) >= 0)) {
				mat[oldx][oldy] = ' ';
				count = count - tempcount;
				pl->i = x;
				pl->j = y;
				mat[pl->i][pl->j] = pl->id;
				printMap(mat);
				printf("\nMOVED! %d steps left!\n", count);
			}
			else {
				//printf("can't move, choose other direction or fewer steps \n");
				y = oldy;
				x = oldx;
				break;
			}
		}
		else if (dir == 'l') {
			oldy = y;
			oldx = x;
			while (steps > 0) {
				//*regular movement left*//
				if ((mat[x][y - 1] == ' ') && (mat[x + 1][y - 1] == 'x') && ((y + 1) >=0)) {
					tempcount++;
					steps--;
					y--;
				}
				//*left and down*//
				else if ((mat[x][y - 1] == ' ') && (mat[x + 1][y - 1] == ' ') && ((y + 1) >=0) && (mat[x + 2][y - 1] == 'x')) {
					tempcount++;
					steps--;
					y--;
					x++;
				}
				//*left and up*//
				else if ((mat[x][y - 1] == 'x') && (mat[x + 1][y - 1] == 'x') && ((y + 1) >=0) && (mat[x - 1][y - 1] == ' ')) {
					tempcount++;
					steps--;
					y--;
					x--;
				}
				else {
					printf("can't move, choose fewer steps \n");
					y = y + tempcount;
					scanf("%d", &steps);
					getchar();
					stepflag = steps;
					tempcount = 0;
				}
			}
			if ((tempcount == stepflag) && ((count - tempcount) >= 0)) {
				mat[oldx][oldy] = ' ';
				count = count - tempcount;
				pl->i = x;
				pl->j = y;
				mat[pl->i][pl->j] = pl->id;
				printMap(mat);
				printf("\nMOVED! %d steps left!\n", count);
			}
			else {
				//printf("can't move, choose other direction or fewer steps \n");
				y = oldy;
				x = oldx;
				break;
			}
		}
	}
}
