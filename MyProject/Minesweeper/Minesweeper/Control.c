#include <conio.h>
#include<stdio.h>
#include"Show.h"
#include"Control.h"

void(*set[4])() = { SetPrimary, SetIntermediate, SetExpert, SetFree };
void (*define[3])(int *, int *, int *) = { DefineHeight , DefineWidth, DefineMine };

int GetKeyBoard()
{
	int flag = _getch();

	if ((signed char)flag < 0)
	{
		flag = (flag << 8) | _getch();
	}

	return flag;
}

//void Game(int row, int col, int mine)
//{
//
//}



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
				if (*mine < 10)
				{
					(*mine)++;
				}
				break;
			}
			flag ? (*col)-- : (*row)--;
			(*col) < 9 ? (*col)++ : *col;
			(*row) < 9 ? (*row)++ : *row;
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
			(*col) > 30 ? (*col)-- : *col;
			(*row) > 24 ? (*row)-- : *row;
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
		//Game(row, col, mine);
		break;
	case SET:
		Set(&row, &col, &mine);
		break;
	case EXIT:
		break;
	}
}
