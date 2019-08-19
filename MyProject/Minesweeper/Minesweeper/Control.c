#include <conio.h>
#include<stdio.h>
#include"Map.h"
#include"Show.h"
#include"Control.h"

void(*set[4])() = { SetPrimary, SetIntermediate, SetExpert, SetFree };
void (*define[3])(int *, int *, int *) = { DefineHeight , DefineWidth, DefineMine };

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

void Game(int row, int col, int mine)
{
	Point point = { row / 2, col / 2 };
	int input, flag = 1;
	int coveredBlank = row * col - mine;
	int mineLeast = mine;

	MapInit(row, col, mine, point);
	MapPrint(row, col, mine, point, flag);
	while (1)
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
		case ENTER:
			if (tag[point.row][point.col] == COVERED)
			{
				MapOpen(row, col, point.row, point.col);
			}
			else if (map[point.row][point.col] != MINE)
			{
				OpenAround(row, col, point);
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
		default:
			break;
		}
		MapPrint(row, col, mineLeast, point, flag);
		flag = !flag;
	}
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
	default:
		break;
	}

	printf("row = %d, col = %d, mine = %d\n", *row, *col, *mine);
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
				if (*mine < MINMINE)
				{
					(*mine)++;
				}
				break;
			}
			flag ? (*col)-- : (*row)--;
			(*col) < MINCOL ? (*col)++ : *col;
			(*row) < MINROW ? (*row)++ : *row;
			break;
		case ARROW_RIGHT:
			if (flag == 2)
			{
				(*mine)++;
				if (*mine > maxmine)
				{
					(*mine)--;
				}
				break;
			}
			flag ? (*col)++ : (*row)++;
			(*col) > MAXCOL ? (*col)-- : *col;
			(*row) > MAXROW ? (*row)-- : *row;
			break;
		case ENTER:
			return;
		default:
			break;
		}
	}
}

void GameControl()
{
	int row = 16, col = 16, mine = 40;;

	switch (WelcomePage())
	{
	case START:
		Game(row, col, mine);
		break;
	case SET:
		Set(&row, &col, &mine);
		break;
	case EXIT:
		break;
	}
}
