int choise = 0, map;
		char mat[50][250];

		printf("\nplease select the level difficulty (1-3):\t");
		scanf("%d", &map);
		getchar();

		while (map > 3 || map < 1)
		{
			printf("\nwrong entry please try again:\t");
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

			/*print*///
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
			 //left st//
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

	





	int count = 5, steps=0, x=40, y=40, tempcount=0;
	char dir;
	mat[x][y] = 'T';
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 250; j++)
		{
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	while (count > 0) {
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
		/***GET MAP FUNCTION***/
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
					else if ((mat[x][y + 1] == ' ') && (mat[x + 1][y + 1] == ' ') && ((y + 1) != 249) && (mat[x+2][y+1]=='x')) {
							tempcount++;
							steps--;
							y++;
							x++;
					}
					//*right and up*//
					else if ((mat[x][y + 1] == 'x') && (mat[x + 1][y + 1] == 'x') && ((y + 1) != 249) && (mat[x-1][y+1]==' ')) {
						tempcount++;
						steps--;
						y++;
						x--;
					}
				}
					if((tempcount==stepflag)&&((count - tempcount)>=0)) {
						mat[oldx][oldy] = ' ';
						count = count - tempcount;
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
	mat[x][y] = 'T';
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 250; j++)
		{
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
