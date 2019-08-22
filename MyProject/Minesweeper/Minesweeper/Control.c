#include <conio.h>
#include<stdio.h>
#include"Map.h"
#include"Page.h"
#include"Save.h"
#include"Control.h"

extern int coveredBlank;
extern char map[26][32];
extern char tag[26][32];

int gameLevel = LEVEL2;

int GetKeyBoard()
{
	int flag = _getch();

	if ((signed char)flag < 0)
	{
		flag = (flag << 8) | _getch();
	}

	return flag;
}

void Game(int row, int col, int mine, int isFirst)
{
	Point offSet = { 0, 0 };
	Point point = { (row + 1) / 2, (col + 1) / 2 };
	int input, showPoint = TRUE, state = CONTINUE;
	int mineLeast = mine;

	MapPrint(row, col, mine, point, showPoint, isFirst);
	while (!state)
	{
		input = GetKeyBoard();
		switch (input)
		{
		case UP:
		case ARROW_UP:
			point.row--;
			showPoint = TRUE;
			if (point.row <= 0)
			{
				point.row = row;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			point.row++;
			showPoint = TRUE;
			if (point.row >= row + 1)
			{
				point.row = 1;
			}
			break;
		case LEFT:
		case ARROW_LEFT:
			point.col--;
			showPoint = TRUE;
			if (point.col <= 0)
			{
				point.col = col;
			}
			break;
		case RIGHT:
		case ARROW_RIGHT:
			point.col++;
			showPoint = TRUE;
			if (point.col >= col + 1)
			{
				point.col = 1;
			}
			break;
		case MINECHECK:
			if (!isFirst)
			{
				MapCheck(row, col, mineLeast);
				while (GetKeyBoard() != ESC);
			}
			break;
		case JUMP:
			JumpMap(row, col, mineLeast, point, showPoint, isFirst);
			printf("请输入您要跳转的坐标(row, col)：> ");
			while (!scanf("%d%d", &point.row, &point.col));
			showPoint = TRUE;
			break;
		case ENTER:
			if (isFirst == TRUE)
			{
				MapInit(row, col, mine, point);
				isFirst = FALSE;
			}
			if (map[point.row][point.col] == MINE)
			{
				state = OVER;
			}
			else if (tag[point.row][point.col] == COVERED)
			{
				MapOpen(row, col, point.row, point.col);
			}
			else
			{
				if (OpenAround(row, col, point, mineLeast))
				{
					state = OVER;
				}
			}
			break;
		case HIDEPOINT:
			showPoint = FALSE;
			break;
		case MINEMARK:
			if (tag[point.row][point.col] != OPENED)
			{
				if (tag[point.row][point.col] == COVERED)
				{
					tag[point.row][point.col] = MARKED;
					mineLeast--;
				}
				else
				{
					tag[point.row][point.col] = COVERED;
					mineLeast++;
				}
			}
			break;
		case SAVE:
			Save(row, col, mineLeast);
			break;
		case ESC:
			SaveData(row, col, mineLeast, TMP);
			return;
		default:
			break;
		}
		if (!coveredBlank && !isFirst)
		{
			state = WIN;
		}
		MapPrint(row, col, mineLeast, point, showPoint, isFirst);
		showPoint = !showPoint;
	}
	GameFinish(row, col, mineLeast, state);
	getchar();
}

int SetLevel()
{
	while (1)
	{
		SetPage(gameLevel);
		switch (GetKeyBoard())
		{
		case UP:
		case ARROW_UP:
			gameLevel--;
			if (gameLevel == LEVEL1 - 1)
			{
				gameLevel = FREE;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			gameLevel++;
			if (gameLevel == FREE + 1)
			{
				gameLevel = LEVEL1;
			}
			break;
		case ENTER:
			return gameLevel;
		case ESC:
			return ESC;
		default:
			break;
		}
	}
}

void Set(int *row, int *col, int *mine)
{
	switch (SetLevel())
	{
	case LEVEL1:
		*row = 9;
		*col = 9;
		*mine = 10;
		break;
	case LEVEL2:
		*row = 16;
		*col = 16;
		*mine = 40;
		break;
	case LEVEL3:
		*row = 16;
		*col = 30;
		*mine = 99;
		break;
	case FREE:
		FreeDefine(row, col, mine);
		break;
	case ESC:
		return;
	default:
		break;
	}
}

void FreeDefine(int *row, int *col, int *mine)
{
	static int flag = 0;
	int maxMine = 0;

	while (1)
	{
		DefinePage(*row, *col, *mine, flag);
		maxMine = MAXMINE(*row, *col);
		switch (GetKeyBoard())
		{
		case UP:
		case ARROW_UP:
			flag--;
			if (flag == DEFINEHEIGHT - 1)
			{
				flag = DEFINEMINE;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			flag++;
			if (flag == DEFINEMINE + 1)
			{
				flag = DEFINEHEIGHT;
			}
			break;
		case LEFT:
		case ARROW_LEFT:
			if (flag == DEFINEMINE)
			{
				(*mine)--;
				break;
			}
			flag ? (*col)-- : (*row)--;
			break;
		case RIGHT:
		case ARROW_RIGHT:
			if (flag == DEFINEMINE)
			{
				(*mine)++;
				break;
			}
			flag ? (*col)++ : (*row)++;
			break;
		case ENTER:
			return;
		default:
			break;
		}
		if (*col < MINCOL)
		{
			*col = MINCOL;
		}
		else if(*col > MAXCOL)
		{
			*col = MAXCOL;
		}
		if (*row < MINROW)
		{
			*row = MINROW;
		}
		else if (*row > MAXROW)
		{
			*row = MAXROW;
		}
		if (*mine < MINMINE)
		{
			*mine = MINMINE;
		}
		else if (*mine > maxMine)
		{
			*mine = maxMine;
		}
	}
}

int Welcome()
{
	static int flag = 1;

	while (1)
	{
		WelcomePage(flag);
		switch (GetKeyBoard())
		{
		case UP:
		case ARROW_UP:
			flag--;
			if (flag == WELCOMECONTINUE - 1)
			{
				flag = WELCOMEEXIT;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			flag++;
			if (flag == WELCOMEEXIT + 1)
			{
				flag = WELCOMECONTINUE;
			}
			break;
		case ENTER:
			return flag;
		default:
			break;
		}
	}
}

void GameControl()
{
	int row = 16, col = 16, mine = 40;
	int o_row, o_col, o_mine;

	LoadList(0);
	while (1)
	{
		switch (Welcome())
		{
		case GAMECONTINUE:
			Load(&o_row, &o_col, &o_mine);
			break;
		case NEWGAME:
			Game(row, col, mine, TRUE);
			break;
		case GAMESET:
			Set(&row, &col, &mine);
			break;
		case EXIT:
			return;
		default:
			break;
		}
	}
}
