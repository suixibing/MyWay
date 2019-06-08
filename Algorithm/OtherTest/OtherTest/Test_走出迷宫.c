#include"Test.h"

#define ROW 100
#define COL 100

typedef struct 
{
	int x;
	int y;
	int step;
	int last;
}Step;

typedef struct
{
	Step step[100];
	int head;
	int tail;
}Queue;

Queue q;
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

int BFS(int x, int y, int step)
{
	int tx, ty;

	q.head = 0;
	q.tail = 0;
	q.step[q.tail].x = x;
	q.step[q.tail].y = y;
	q.step[q.tail].step = step;
	q.step[q.tail].last = -1;
	q.tail++;
	while (q.head < q.tail)
	{
		for (int i = 0; i < 4; i++)
		{
			tx = q.step[q.head].x + next[i][0];
			ty = q.step[q.head].y + next[i][1];
			if (tx < 1 || tx > row || ty < 1 || ty >col)
			{
				continue;
			}
			if (board[tx][ty] == 0 && book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				q.step[q.tail].x = tx;
				q.step[q.tail].y = ty;
				q.step[q.tail].step = q.step[q.head].step + 1;
				q.step[q.tail].last = q.head;
				q.tail++;
			}
			if (tx == endx && ty == endy)
			{
				return q.step[q.tail - 1].step;
			}
		}
		q.head++;
	}

	return ERROR;
}

void ExitMaze()
{
	int i, j, flag = 1;

	scanf("%d%d", &row, &col);
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	scanf("%d%d%d%d", &startx, &starty, &endx, &endy);
	while (flag)
	{
		printf("0、退出\n");
		printf("1、深度优先遍历实现\n");
		printf("2、广度优先遍历实现\n");
		printf("请选择:>");
		scanf("%d", &flag);
		switch (flag)
		{
		case 0:
			printf("退出!\n");
			break;
		case 1:
			printf("深度优先遍历实现:>\n");
			DFS(startx, starty, 0);
			printf("最小步数为%d\n", min);
			break;
		case 2:
			printf("广度优先遍历实现:>\n");
			min = BFS(startx, starty, 0);
			for (i = q.tail - 1; i > 0; i = q.step[i].last)
			{
				printf("(%d,%d)<-", q.step[i].x, q.step[i].y);
			}
			printf("(%d,%d)\n", startx, starty);
			printf("最小步数为%d\n", min);
			break;
		default:
			break;
		}
	}
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