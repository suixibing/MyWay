#include"game.h"

void Menu()
{
	printf("****************************************************\n");
	printf("**********               0、 exit         **********\n");
	printf("**********               1、 play         **********\n");
	printf("****************************************************\n");
}

void Display(char board[ROW][COL], int row, int col)
{
	int i, j;
	
	//打印棋盘
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j != col - 1)
			{
				printf("     |");
			}
			else
			{
				printf("     \n");
			}
		}
		for (j = 0; j < col; j++)
		{
			if (j != col - 1)
			{
				printf("  %c  |", board[i][j]);
			}
			else
			{
				printf("  %c   %d \n", board[i][j], i + 1);//i+1是行标
			}
		}
		for (j = 0; j < col; j++)
		{
			if (j != col - 1)
			{
				printf("     |");
			}
			else
			{
				printf("     \n");
			}
		}
		for (j = 0; j < col && i != col - 1; j++)
		{
			if (j != col - 1)
			{
				printf("-----|");
			}
			else
			{
				printf("-----\n");
			}
		}
	}
	//打印行标
	for (j = 0; j < col; j++)
	{
		printf("  %d   ", j + 1);//j+1是列标
	}
	putchar('\n');
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;

	printf("玩家下:>\n");

	while (1)
	{
		printf("请输入你要下的坐标:>");
		while (!scanf("%d%d", &x, &y))
		{
			getchar();
		}
		if (x <= ROW && x >= 1 && y <= COL && y >= 1)
		{
			if (board[x - 1][y - 1] == '\0')
			{
				board[x - 1][y - 1] = PLAYER;
				break;
			}
			else
			{
				printf("输入错误，请重新输入!a\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入!b\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;

	printf("电脑下:>\n");

	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == '\0')
		{
			board[x][y] = COMPUTER;
			break;
		}
	}
}

//检测十字上的棋子
char CheckCross(char board[ROW][COL], int row, int col)
{
	int i, j, flag;

	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col - 1; j++)
		{
			flag++;
			if (board[i][j] == '\0' || board[i][j] != board[i][j + 1])
			{
				flag = 0;
			}
			if (flag == N - 1)
			{
				return board[i][j];
			}
		}
	}
	for (j = 0; j < col; j++)
	{
		flag = 0;
		for (i = 0; i < row - 1; i++)
		{
			flag++;
			if (board[i][j] == '\0' || board[i][j] != board[i + 1][j])
			{
				flag = 0;
			}
			if (flag == N - 1)
			{
				return board[i][j];
			}
		}
	}

	return CONTINUE;
}
//
//只能检测对角线上的棋子是否完成
//
//char CheckXCross(char board[ROW][COL], int row, int col)
//{
//	int i, j, flag;
//
//	for (i = 0, flag = 0; i + 1 < row; i++)
//	{
//		flag++;
//		if (board[i][i] == '\0' || board[i][i] != board[i + 1][i + 1])
//		{
//			flag = 0;
//		}
//		if (flag == N - 1)
//		{
//			return board[i][i];
//		}
//	}
//
//	for (i = row - 1, j = 0, flag = 0; i - 1 >= 0 && j + 1 < col; i--, j++)
//	{
//		flag++;
//		if (board[i][j] == '\0' || board[i][j] != board[i - 1][j + 1])
//		{
//			flag = 0;
//		}
//		if (flag == N - 1)
//		{
//			return board[i][j];
//		}
//	}
//
//	return CONTINUE;
//}

//所有斜线上棋子都能检测
char CheckXCross(char board[ROW][COL], int row, int col)
{
	int i, j, k, flag;
	for (k = 0; k < col; k++)
	{
		for (i = 0, flag = 0; i + 1 < row; i++)
		{
			flag++;
			if (board[i][i + k] == '\0' || board[i][i + k] != board[i + 1][i + k + 1])
			{
				flag = 0;
			}
			if (flag == N - 1)
			{
				return board[i][i + k];
			}
		}
		for (i = 0, flag = 0; i + k + 1 < row; i++)
		{
			flag++;
			if (board[i + k][i] == '\0' || board[i + k][i] != board[i + k + 1][i + 1])
			{
				flag = 0;
			}
			if (flag == N - 1)
			{
				return board[i + k][i];
			}
		}
		for (i = row - 1, j = 0, flag = 0; i - k - 1 >= 0 && j + 1 < col; i--, j++)
		{
			flag++;
			if (board[i - k][j] == '\0' || board[i - k][j] != board[i - k - 1][j + 1])
			{
				flag = 0;
			}
			if (flag == N - 1)
			{
				return board[i - k][j];
			}
		}
		for (i = row - 1, j = 0, flag = 0; i - 1 >= 0 && j + k + 1 < col; i--, j++)
		{
			flag++;
			if (board[i][j + k] == '\0' || board[i][j + k] != board[i - 1][j + k + 1])
			{
				flag = 0;
			}
			if (flag == N - 1)
			{
				return board[i][j + k];
			}
		}
	}

	return CONTINUE;
}

char CheckWin(char board[ROW][COL], int row, int col)
{
	int ch;
	int i, j, flag;
	
	if ((ch = CheckCross(board, row, col)) != CONTINUE)
	{
		return ch;
	}

	if ((ch = CheckXCross(board, row, col)) != CONTINUE)
	{
		return ch;
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '\0')
			{
				return CONTINUE;
			}
		}
	}
	return END;
}

void Play()
{
	char ch;
	char board[ROW][COL] = { 0 };
	system("cls");

	printf("游戏开始:>\n");
	Display(board, ROW, COL);

	while (1)
	{
		PlayerMove(board, ROW, COL);
		system("cls");
		Display(board, ROW, COL);
		ch = CheckWin(board, ROW, COL);
		if (ch != CONTINUE)
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		system("cls");
		Display(board, ROW, COL);
		ch = CheckWin(board, ROW, COL);
		if (ch != CONTINUE)
		{
			break;
		}
	}
	if (ch == COMPUTER)
	{
		printf("电脑赢！\n");
	}
	else if (ch == PLAYER)
	{
		printf("玩家赢！\n");
	}
	else if(ch == END)
	{
		printf("平局！\n");
	}
}