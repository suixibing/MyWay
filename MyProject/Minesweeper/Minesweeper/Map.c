#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Map.h"
#include"Control.h"

int coveredBlank = 16 * 16;
char map[26][32] = { 0 };
char tag[26][32] = { 0 };

void MapInit(int row, int col, int mine, Point point)
{
	int i, j, tmp;
	srand((unsigned int)time(NULL));
	
	coveredBlank = row * col - mine;
	for (i = 0; i < row + 2; i++)
	{
		for (j = 0; j < col + 2; j++)
		{
			map[i][j] = BLANK;
			tag[i][j] = COVERED;
		}
	}
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			map[point.row + i][point.col + j] = MINE;
		}
	}
	while (mine--)
	{
		tmp = rand() % (row * col);
		if (map[tmp / col + 1][tmp % col + 1] == BLANK)
		{
			map[tmp / col + 1][tmp % col + 1] = MINE;
		}
		else
		{
			while (map[tmp / col + 1][tmp % col + 1] == MINE)
			{
				tmp = (tmp + 1) % (row * col);
			}
			map[tmp / col + 1][tmp % col + 1] = MINE;
		}
	}
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			map[point.row + i][point.col + j] = BLANK;
		}
	}
}

void MapPrint(int row, int col, int mineLeast, Point point, int flag, int isFirst)
{
	int i, j;
	char page[2000] = { 0 };
	char change[9][4] = { "　", "１", "２", "３", "４", "５", "６", "７", "８" };
	
	for (i = 0; i < col + 2; i++)
	{
		strcat(page, "█");
	}
	strcat(page, "\n");
	for (i = 1; i <= row; i++)
	{
		strcat(page, "█");
		for (j = 1; j <= col; j++)
		{
			if (flag && i == point.row && j == point.col)
			{
				strcat(page, "□");
			}
			else if (tag[i][j] == COVERED || isFirst)
			{
				strcat(page, "■");
			}
			else if(tag[i][j] == OPENED)
			{
				strcat(page, change[map[i][j]]);
			}
			else
			{
				strcat(page, "△");
			}
		}
		strcat(page, "█\n");
	}
	for (i = 0; i < col + 2; i++)
	{
		strcat(page, "█");
	}
	strcat(page, "\n　　　　方向键控制 空格键确定\n");
	strcat(page, "　　　　h-隐藏光标 m-标记地雷\n");
	strcat(page, "　　　　  未标记雷数： %3d\n");
	system("cls");
	printf(page, mineLeast);
}

void MapOpen(int row, int col, int pointx, int pointy)
{
	int i, j;

	if (pointx < 1 || pointx > row || pointy < 1 || pointy > col || tag[pointx][pointy] != COVERED || map[pointx][pointy] == MINE)
	{
		return;
	}
	tag[pointx][pointy] = OPENED;
	coveredBlank--;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (pointx + i >= 1 && pointx + i <= row && pointy + j >= 1 && pointy + j <= col && map[pointx + i][pointy + j] == MINE)
			{
				map[pointx][pointy]++;
			}
		}
	}
	if (!map[pointx][pointy])
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
	int i, j, flag = 0, count = 0;

	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (tag[point.row + i][point.col + j] == MARKED)
			{
				count++;
				if (map[point.row + i][point.col + j] != MINE)
				{
					flag = 1;
				}
			}

		}
	}
	if (count == map[point.row][point.col])
	{
		if (flag)
		{
			return 1;
		}
		else
		{
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (tag[point.row + i][point.col + j] != MARKED)
					{
						MapOpen(row, col, point.row + i, point.col + j);
					}
				}
			}
		}
	}

	return 0;
}

void GameOver(int row, int col, int mineLeast)
{
	int i, j;
	char page[2000] = { 0 };
	char change[9][4] = { "　", "１", "２", "３", "４", "５", "６", "７", "８" };

	for (j = 0; j < col + 2; j++)
	{
		strcat(page, "█");
	}
	strcat(page, "\n");
	for (i = 1; i <= row; i++)
	{
		strcat(page, "█");
		for (j = 1; j <= col; j++)
		{
			if (map[i][j] == MINE)
			{
				if (tag[i][j] == MARKED)
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
				if (tag[i][j] == OPENED)
				{
					strcat(page, change[map[i][j]]);
				}
				else if (tag[i][j] == MARKED)
				{
					strcat(page, "×");
				}
				else
				{
					strcat(page, "■");
				}
			}
		}
		strcat(page, "█\n");
	}
	for (j = 0; j < col + 2; j++)
	{
		strcat(page, "█");
	}
	strcat(page, "\n　　　　      你输了…\n");
	strcat(page, "　　　　    按回车键继续\n");
	strcat(page, "　　　　  未标记雷数： %3d\n");
	system("cls");
	printf(page, mineLeast);
}

void GameWin(int row, int col, int mineLeast)
{
	int i, j;
	char page[2000] = { 0 };
	char change[9][4] = { "　", "１", "２", "３", "４", "５", "６", "７", "８" };

	for (j = 0; j < col + 2; j++)
	{
		strcat(page, "█");
	}
	strcat(page, "\n");
	for (i = 1; i <= row; i++)
	{
		strcat(page, "█");
		for (j = 1; j <= col; j++)
		{
			if (map[i][j] == MINE)
			{
				if (tag[i][j] == MARKED)
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
				if (tag[i][j] == OPENED)
				{
					strcat(page, change[map[i][j]]);
				}
				else
				{
					strcat(page, "■");
				}
			}
		}
		strcat(page, "█\n");
	}
	for (j = 0; j < col + 2; j++)
	{
		strcat(page, "█");
	}
	strcat(page, "\n　　　　      你赢了…\n");
	strcat(page, "　　　　    按回车键继续\n");
	strcat(page, "　　　　  未标记雷数： %3d\n");
	system("cls");
	printf(page, mineLeast);
}

void MapCheck(int row, int col, int mineLeast)
{
	int i, j;
	char page[2000] = { 0 };
	char change[9][4] = { "　", "１", "２", "３", "４", "５", "６", "７", "８" };

	for (j = 0; j < col + 2; j++)
	{
		strcat(page, "█");
	}
	strcat(page, "\n");
	for (i = 1; i <= row; i++)
	{
		strcat(page, "█");
		for (j = 1; j <= col; j++)
		{
			if (map[i][j] == MINE)
			{
				if (tag[i][j] == MARKED)
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
				if (tag[i][j] == OPENED)
				{
					strcat(page, change[map[i][j]]);
				}
				else if (tag[i][j] == MARKED)
				{
					strcat(page, "×");
				}
				else
				{
					strcat(page, "■");
				}
			}
		}
		strcat(page, "█\n");
	}
	for (j = 0; j < col + 2; j++)
	{
		strcat(page, "█");
	}
	strcat(page, "\n　　　　方向键控制 空格键确定\n");
	strcat(page, "　　　　h-隐藏光标 m-标记地雷\n");
	strcat(page, "　　　　  未标记雷数： %3d\n");
	system("cls");
	printf(page, mineLeast);
}