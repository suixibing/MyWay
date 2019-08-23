#include"Map.h"

int g_coveredBlank = INITIALROWS * INITIALCOLS;
char g_map[MAXROW + BOUNDARY_NUM][MAXCOL + BOUNDARY_NUM];
char g_tag[MAXROW + BOUNDARY_NUM][MAXCOL + BOUNDARY_NUM];
static char s_mineNum[][4] = { "　", "１", "２", "３", "４", "５", "６", "７", "８" };

void MapInit(int row, int col, int mine, Point point)
{
	int i, j, tmp;
	srand((unsigned int)time(NULL));
	
	g_coveredBlank = row * col - mine;
	for (i = 0; i < row + BOUNDARY_NUM; i++)
	{
		for (j = 0; j < col + BOUNDARY_NUM; j++)
		{
			g_map[i][j] = BLANK;
			g_tag[i][j] = COVERED;
		}
	}
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			g_map[point.row + i][point.col + j] = MINE;
		}
	}
	while (mine--)
	{
		tmp = rand() % (row * col);
		if (g_map[tmp / col + 1][tmp % col + 1] == BLANK)
		{
			g_map[tmp / col + 1][tmp % col + 1] = MINE;
		}
		else
		{
			while (g_map[tmp / col + 1][tmp % col + 1] == MINE)
			{
				tmp = (tmp + 1) % (row * col);
			}
			g_map[tmp / col + 1][tmp % col + 1] = MINE;
		}
	}
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			g_map[point.row + i][point.col + j] = BLANK;
		}
	}
}

void MapJump(int row, int col, int mineLeast, Point point, int showPoint, int isFirst)
{
	int i, j;
	char page[PAGESIZE_MINE] = { 0 };
	char lineNum[][4] = { "⑩", "①", "②", "③", "④", "⑤", "⑥", "⑦", "⑧", "⑨" };

	SetConsoleSize((col + 2) * 2, (row + 2) + 3);
	strcat(page, "█");
	for (j = 1; j <= col; j++)
	{
		strcat(page, lineNum[j % 10]);
	}
	strcat(page, "█");
	for (i = 1; i <= row; i++)
	{
		strcat(page, lineNum[i % 10]);
		for (j = 1; j <= col; j++)
		{
			if (showPoint && i == point.row && j == point.col)
			{
				strcat(page, "□");
			}
			else if (g_tag[i][j] == COVERED || isFirst)
			{
				strcat(page, "■");
			}
			else if (g_tag[i][j] == OPENED)
			{
				strcat(page, s_mineNum[g_map[i][j]]);
			}
			else
			{
				strcat(page, "△");
			}
		}
		strcat(page, "█");
	}
	for (i = 0; i < col + BOUNDARY_NUM; i++)
	{
		strcat(page, "█");
	}
	strcat(page, "未标记雷数： %3d\n");
	system("cls");
	printf(page, mineLeast);
}

void MapPrint(int row, int col, int mineLeast, Point point, int showPoint, int isFirst)
{
	int i, j;
	char page[PAGESIZE_MINE] = { 0 };

	SetConsoleSize((col + 2) * 2, (row + 2) + 3);
	for (j = 0; j < col + BOUNDARY_NUM; j++)
	{
		strcat(page, "█");
	}
	for (i = 1; i <= row; i++)
	{
		strcat(page, "█");
		for (j = 1; j <= col; j++)
		{
			if (showPoint && i == point.row && j == point.col)
			{
				strcat(page, "□");
			}
			else if (g_tag[i][j] == COVERED || isFirst)
			{
				strcat(page, "■");
			}
			else if(g_tag[i][j] == OPENED)
			{
				strcat(page, s_mineNum[g_map[i][j]]);
			}
			else
			{
				strcat(page, "△");
			}
		}
		strcat(page, "█");
	}
	for (j = 0; j < col + BOUNDARY_NUM; j++)
	{
		strcat(page, "█");
	}
	strcat(page, "h-隐藏光标 m-标记地雷\n");
	strcat(page, "未标记雷数： %3d");
	system("cls");
	printf(page, mineLeast);
}

void MapOpen(int row, int col, int pointx, int pointy)
{
	int i, j;

	if (pointx < 1 || pointx > row || pointy < 1 || pointy > col || g_tag[pointx][pointy] != COVERED || g_map[pointx][pointy] == MINE)
	{
		return;
	}
	g_tag[pointx][pointy] = OPENED;
	g_coveredBlank--;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (pointx + i >= 1 && pointx + i <= row && pointy + j >= 1 && pointy + j <= col && g_map[pointx + i][pointy + j] == MINE)
			{
				g_map[pointx][pointy]++;
			}
		}
	}
	if (!g_map[pointx][pointy])
	{
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				MapOpen(row, col, pointx + i, pointy + j);
			}
		}
	}
}

int OpenAround(int row, int col, Point point, int mineLeast)
{
	int i, j, count = 0, flag = CONTINUE;

	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (g_tag[point.row + i][point.col + j] == MARKED)
			{
				count++;
				if (g_map[point.row + i][point.col + j] != MINE)
				{
					flag = OVER;
				}
			}
		}
	}
	if (count == g_map[point.row][point.col])
	{
		if (flag)
		{
			return OVER;
		}
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				if (g_tag[point.row + i][point.col + j] != MARKED)
				{
					MapOpen(row, col, point.row + i, point.col + j);
				}
			}
		}
	}

	return CONTINUE;
}

void GameState(int row, int col, int mineLeast, int state)
{
	int i, j;
	char page[PAGESIZE_MINE] = { 0 };

	SetConsoleSize((col + 2) * 2, (row + 2) + 3);
	for (j = 0; j < col + BOUNDARY_NUM; j++)
	{
		strcat(page, "█");
	}
	for (i = 1; i <= row; i++)
	{
		strcat(page, "█");
		for (j = 1; j <= col; j++)
		{
			if (g_map[i][j] == MINE)
			{
				if (g_tag[i][j] == MARKED)
				{
					strcat(page, "△");
				}
				else
				{
					strcat(page, "¤");
				}
			}
			else
			{
				if (g_tag[i][j] == OPENED)
				{
					strcat(page, s_mineNum[g_map[i][j]]);
				}
				else if (state == OVER && g_tag[i][j] == MARKED)
				{
					strcat(page, "×");
				}
				else
				{
					strcat(page, "■");
				}
			}
		}
		strcat(page, "█");
	}
	for (j = 0; j < col + BOUNDARY_NUM; j++)
	{
		strcat(page, "█");
	}

	if (state == OVER)
	{
		strcat(page, "你输了…\n");
	}
	else if(state == WIN)
	{
		strcat(page, "你赢了…\n");
	}
	else if (state == MINECHECK)
	{
		strcat(page, "h-隐藏光标 m-标记地雷\n");
	}
	strcat(page, "未标记雷数： %3d");
	system("cls");
	printf(page, mineLeast);
}
