
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
