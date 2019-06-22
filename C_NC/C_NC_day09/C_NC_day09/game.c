#include"game.h"

void Menu()
{
	printf("*********************************************\n");
	printf("********          0. 退出游戏       *********\n");
	printf("********          1. 开始游戏       *********\n");
	printf("*********************************************\n");
}

void UpdateMineMap(char mine_map[ROW][COL], int row, int col, int now_row, int now_col)
{
	if (now_row - 1 >= 0 && now_col - 1 >= 0)
	{
		if (mine_map[now_row - 1][now_col - 1] == MINE)
		{
			mine_map[now_row][now_col]++;
		}
	}
	if (now_row - 1 >= 0)
	{
		if (mine_map[now_row - 1][now_col] == MINE)
		{
			mine_map[now_row][now_col]++;
		}
	}
	if (now_row - 1 >= 0 && now_col + 1 < col)
	{
		if (mine_map[now_row - 1][now_col + 1] == MINE)
		{
			mine_map[now_row][now_col]++;
		}
	}
	if (now_col - 1 >= 0)
	{
		if (mine_map[now_row][now_col - 1] == MINE)
		{
			mine_map[now_row][now_col]++;
		}
	}
	if (now_col + 1 < col)
	{
		if (mine_map[now_row][now_col + 1] == MINE)
		{
			mine_map[now_row][now_col]++;
		}
	}
	if (now_row + 1 < row && now_col - 1 >= 0)
	{
		if (mine_map[now_row + 1][now_col - 1] == MINE)
		{
			mine_map[now_row][now_col]++;
		}
	}
	if (now_row + 1 < row)
	{
		if (mine_map[now_row + 1][now_col] == MINE)
		{
			mine_map[now_row][now_col]++;
		}
	}
	if (now_row + 1 < row && now_col + 1 < col)
	{
		if (mine_map[now_row + 1][now_col + 1] == MINE)
		{
			mine_map[now_row][now_col]++;
		}
	}
}

void Init(char play_map[ROW][COL], char mine_map[ROW][COL], int row, int col, int mine)
{
	int now_row, now_col;
	for (now_row = 0; now_row < row; now_row++)
	{
		for (now_col = 0; now_col < col; now_col++)
		{
			play_map[now_row][now_col] = GRASS;
			mine_map[now_row][now_col] = '0';
		}
	}

	srand((unsigned int)time(NULL));
	while (mine)
	{
		now_row = rand() % row;
		now_col = rand() % col;
		if (now_row >= 0 && now_row < row && now_col >= 0 && now_col < col)
		{
			if (mine_map[now_row][now_col] != MINE)
			{
				mine_map[now_row][now_col] = MINE;
				mine--;
			}
		}
	}
	for (now_row = 0; now_row < row; now_row++)
	{
		for (now_col = 0; now_col < col; now_col++)
		{
			if (mine_map[now_row][now_col] != MINE) 
			{
				UpdateMineMap(mine_map, row, col, now_row, now_col);
			}
		}
	}
}


void ShowMap(char play_map[ROW][COL], int row, int col)
{
	int now_row, now_col;
	printf("   |");
	for (now_col = 0; now_col < col; now_col++)
	{
		printf(" %d ", now_col + 1);
	}
	putchar('\n');
	for (now_col = 0; now_col < col + 1; now_col++)
	{
		printf("---");
	}
	putchar('\n');
	for (now_row = 0; now_row < row; now_row++)
	{
		printf(" %d |", now_row + 1);
		for (now_col = 0; now_col < col; now_col++)
		{
			printf(" %c ", play_map[now_row][now_col]);
		}
		putchar('\n');
	}
	putchar('\n');
}

int UpdatePlayMap(char play_map[ROW][COL], char mine_map[ROW][COL], 
	int row, int col, int now_row, int now_col)
{
	int count = 1;
	play_map[now_row][now_col] = mine_map[now_row][now_col];

	if (mine_map[now_row][now_col] == '0')
	{
		if (now_row - 1 >= 0 && now_col - 1 >= 0 && play_map[now_row - 1][now_col - 1] == GRASS)
		{
			if (play_map[now_row - 1][now_col - 1] = mine_map[now_row - 1][now_col - 1])
			{
				count += UpdatePlayMap(play_map, mine_map, row, col, now_row - 1, now_col - 1) - 1;
			}
			count++;
		}
		if (now_row - 1 >= 0 && play_map[now_row - 1][now_col] == GRASS)
		{
			if (play_map[now_row - 1][now_col] = mine_map[now_row - 1][now_col])
			{
				count += UpdatePlayMap(play_map, mine_map, row, col, now_row - 1, now_col) - 1;
			}
			count++;
		}
		if (now_row - 1 >= 0 && now_col + 1 < col && play_map[now_row - 1][now_col + 1] == GRASS)
		{
			if (play_map[now_row - 1][now_col + 1] = mine_map[now_row - 1][now_col + 1])
			{
				count += UpdatePlayMap(play_map, mine_map, row, col, now_row - 1, now_col + 1) - 1;
			}
			count++;
		}
		if (now_col - 1 >= 0 && play_map[now_row][now_col - 1] == GRASS)
		{
			if (play_map[now_row][now_col - 1] = mine_map[now_row][now_col - 1])
			{
				count += UpdatePlayMap(play_map, mine_map, row, col, now_row, now_col - 1) - 1;
			}
			count++;
		}
		if (now_col + 1 < col && play_map[now_row][now_col + 1] == GRASS)
		{
			if (play_map[now_row][now_col + 1] = mine_map[now_row][now_col + 1])
			{
				count += UpdatePlayMap(play_map, mine_map, row, col, now_row, now_col + 1) - 1;
			}
			count++;
		}
		if (now_row + 1 < row && now_col - 1 >= 0 && play_map[now_row + 1][now_col - 1] == GRASS)
		{
			if (play_map[now_row + 1][now_col - 1] = mine_map[now_row + 1][now_col - 1])
			{
				count += UpdatePlayMap(play_map, mine_map, row, col, now_row + 1, now_col - 1) - 1;
			}
			count++;
		}
		if (now_row + 1 < row && play_map[now_row + 1][now_col] == GRASS)
		{
			if (play_map[now_row + 1][now_col] = mine_map[now_row + 1][now_col])
			{
				count += UpdatePlayMap(play_map, mine_map, row, col, now_row + 1, now_col) - 1;
			}
			count++;
		}
		if (now_row + 1 < row && now_col + 1 < col && play_map[now_row + 1][now_col + 1] == GRASS)
		{
			if (play_map[now_row + 1][now_col + 1] = mine_map[now_row + 1][now_col + 1])
			{
				count += UpdatePlayMap(play_map, mine_map, row, col, now_row + 1, now_col + 1) - 1;
			}
			count++;
		}
	}

	return count;
}


int Player(char play_map[ROW][COL], char mine_map[ROW][COL], int row, int col)
{
	int now_row, now_col, count = 0;

	printf("请输入您要点开的位置(row col):>");
	if (scanf("%d%d", &now_row, &now_col) == 0)
	{
		getchar();
	}
	
	now_row = now_row - 1;
	now_col = now_col - 1;
	if (now_row < 0 || now_row >= row || now_col < 0 || now_col >= col)
	{
		printf("输入有误，请重新输入！\n");
		return count;
	}
	if (play_map[now_row][now_col] != GRASS)
	{
		printf("输入位置已经翻开，请重新输入！\n");
		return count;
	}
	if (mine_map[now_row][now_col] == MINE)
	{
		return EXIT;
	}
	else
	{
		count = UpdatePlayMap(play_map, mine_map, row, col, now_row, now_col);
	}

	return count;
}

void Play()
{
	int count = 0;
	char play_map[ROW][COL];
	char mine_map[ROW][COL];
	Init(play_map, mine_map, ROW, COL, MINE_NUM);
	ShowMap(play_map, ROW, COL);
	//ShowMap(mine_map, ROW, COL);
	while (1)
	{
		count += Player(play_map, mine_map, ROW, COL);
		system("cls");

		if (count < 0)
		{
			break;
		}
		else if (count == ROW * COL - MINE_NUM)
		{
			printf("您赢了！\n");
			break;
		}

		printf("距离完成还有区域:> %d个\n", ROW * COL - MINE_NUM - count);
		ShowMap(play_map, ROW, COL);
		//ShowMap(mine_map, ROW, COL);
	}

	printf("游戏结束！\n");
}