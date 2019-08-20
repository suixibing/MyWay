#include <conio.h>
#include<stdio.h>
#include"Map.h"
#include"Show.h"
#include"Control.h"

void(*set[4])() = { SetPrimary, SetIntermediate, SetExpert, SetFree };
void (*define[3])(int *, int *, int *) = { DefineHeight , DefineWidth, DefineMine };

extern int coveredBlank;
extern char map[26][32];
extern char tag[26][32];

int GetKeyBoard()
{
	int flag = _getch();

	if ((signed char)flag < 0)
	{
		flag = (flag << 8) | _getch();
	}

	return flag;
}

int Game(int row, int col, int mine, int isFirst)
{
	Point point = { row / 2, col / 2 };
	int input, flag = 1, state = CONTINUE;
	int mineLeast = mine;

	MapPrint(row, col, mine, point, flag, isFirst);
	while (!state)
	{
		input = GetKeyBoard();
		switch (input)
		{
		case ARROW_UP:
			point.row--;
			flag = 1;
			if (point.row == 0)
			{
				point.row = row;
			}
			break;
		case ARROW_DOWN:
			point.row++;
			flag = 1;
			if (point.row == row + 1)
			{
				point.row = 1;
			}
			break;
		case ARROW_LEFT:
			point.col--;
			flag = 1;
			if (point.col == 0)
			{
				point.col = col;
			}
			break;
		case ARROW_RIGHT:
			point.col++;
			flag = 1;
			if (point.col == col + 1)
			{
				point.col = 1;
			}
			break;
		case MINECHECK:
			if (!isFirst)
			{
				MapCheck(row, col, mineLeast);
			}
			break;
		case ENTER:
			if (isFirst == FIRST)
			{
				MapInit(row, col, mine, point);
				isFirst = NOTFIRST;
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
			flag = 0;
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
		case ESC:
			return mineLeast;
		default:
			break;
		}
		if (!coveredBlank && !isFirst)
		{
			state = WIN;
		}
		MapPrint(row, col, mineLeast, point, flag, isFirst);
		flag = !flag;
	}
	if (state == WIN)
	{
		GameWin(row, col, mineLeast);
	}
	else
	{
		GameOver(row, col, mineLeast);
	}
	getchar();

	MapInit(row, col, 0, point);
	return 0;
}

int SetPage()
{
	int x = 0;

	while (1)
	{
		set[x]();
		switch (GetKeyBoard())
		{
		case ARROW_UP:
			x--;
			if (x == -1)
			{
				x = 3;
			}
			break;
		case ARROW_DOWN:
			x++;
			if (x == 4)
			{
				x = 0;
			}
			break;
		case ENTER:
			return x;
		case ESC:
			return ESC;
		default:
			break;
		}
	}
}

void Set(int *row, int *col, int *mine)
{
	switch (SetPage())
	{
	case 0:
		*row = 9;
		*col = 9;
		*mine = 10;
		break;
	case 1:
		*row = 16;
		*col = 16;
		*mine = 40;
		break;
	case 2:
		*row = 16;
		*col = 24;
		*mine = 99;
		break;
	case 3:
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
	int flag = 0;
	int maxmine = 0;

	while (1)
	{
		define[flag](row, col, mine);
		maxmine = *row * *col * 9 / 10;
		switch (GetKeyBoard())
		{
		case ARROW_UP:
			flag--;
			if (flag == -1)
			{
				flag = 2;
			}
			break;
		case ARROW_DOWN:
			flag++;
			if (flag == 3)
			{
				flag = 0;
			}
			break;
		case ARROW_LEFT:
			if (flag == 2)
			{
				(*mine)--;
				break;
			}
			flag ? (*col)-- : (*row)--;
			break;
		case ARROW_RIGHT:
			if (flag == 2)
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
		else if (*mine > maxmine)
		{
			*mine = maxmine;
		}
	}
}

void GameControl()
{
	int row = 16, col = 16, mine = 40;
	int o_row = 16, o_col = 16, o_mine = 0;

	while (1)
	{
		switch (WelcomePage())
		{
		case GAMECONTINUE:
			o_mine = Game(o_row, o_col, o_mine, NOTFIRST);
			break;
		case NEWGAME:
			o_row = row;
			o_col = col;
			o_mine = Game(row, col, mine, FIRST);
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
