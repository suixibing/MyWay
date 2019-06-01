#include"Test.h"

#define ROW 100
#define COL 100
int min = INT_MAX;
int row, col, startx, starty, endx, endy;
int book[ROW][COL] = { 0 };
int board[ROW][COL] = { 0 };
int next[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

void DFS(int x, int y, int step)
{
	int xx, yy;

	if (x == endx && y == endy)
	{
		if (step < min)
		{
			min = step;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		xx = x + next[i][0];
		yy = y + next[i][1];
		if (xx < 1 || xx > row || yy < 1 || yy > col)
		{
			continue;
		}
		if (board[xx][yy] == 0 && book[xx][yy] == 0)
		{
			book[xx][yy] = 1;
			DFS(xx, yy, step + 1);
			book[xx][yy] = 0;
		}
	}
}

void ExitMaze()
{
	int i, j;

	scanf("%d%d", &row, &col);
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	scanf("%d%d%d%d", &startx, &starty, &endx, &endy);
	DFS(startx, starty, 0);
	printf("最小步数为%d\n", min);
}

/*

5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3

*/