#include <conio.h>
#include"Control.h"

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

}

void Set(int *row, int *col, int *mine)
{

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