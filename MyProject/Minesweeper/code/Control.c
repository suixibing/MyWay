#include"Control.h"

extern int g_coveredBlank;
extern char g_map[MAXROW + BOUNDARY_NUM][MAXCOL + BOUNDARY_NUM];
extern char g_tag[MAXROW + BOUNDARY_NUM][MAXCOL + BOUNDARY_NUM];

int g_gameLevel = LEVEL2;
int g_nowGameLevel = 0;

int GetKeyBoard()
{
	int flag = _getch();

	if ((signed char)flag < 0)
	{
		flag = (flag << 8) | _getch();
	}

	return flag;
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 1, 0 };

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hOut, pos);
}
void SetConsoleSize(int cols, int lines)
{
	HWND hWnd = GetConsoleWindow();
	char consoleSize[32];

	sprintf(consoleSize, "mode con cols=%d lines=%d", cols, lines);
	system(consoleSize);
	SetWindowLongPtr(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX);
}

int GetMouse(int *row, int *col)
{
	HWND hwn;
	POINT cursor;
	RECT rectWindow;

	hwn = GetConsoleWindow();
	while (1)
	{
		GetCursorPos(&cursor);
		GetWindowRect(hwn, &rectWindow);
		if(KEY_DOWN(VK_LBUTTON) && 
			cursor.x >= rectWindow.left && cursor.x <= rectWindow.right && 
			cursor.y >= rectWindow.top && cursor.y <= rectWindow.bottom)
		{
			*row = (cursor.y - rectWindow.top - 30) / 20;
			*col = (cursor.x - rectWindow.left - 8) / 20;
			return LEFTCLICK;
		}
		else if(KEY_DOWN(VK_RBUTTON) &&
			cursor.x >= rectWindow.left && cursor.x <= rectWindow.right &&
			cursor.y >= rectWindow.top && cursor.y <= rectWindow.bottom)
		{
			*row = (cursor.y - rectWindow.top - 30) / 20;
			*col = (cursor.x - rectWindow.left - 8) / 20;
			return RIGHTCLICK;
		}
		else if (_kbhit())
		{
			return GetKeyBoard();
		}
		Sleep(100);
	}
}

void Game(int row, int col, int mine, int isFirst)
{
	Point point = { (row + 1) / 2, (col + 1) / 2 }, tmp = { 0, 0 };
	int showPoint = TRUE, state = CONTINUE;
	int mineLeast = mine, input;
	
	MapPrint(row, col, mine, point, showPoint, isFirst);
	while (!state)
	{
		MapPoint(point, showPoint);
		input = GetMouse(&tmp.row, &tmp.col);
		MapPoint(point, FALSE);
		if ((input == LEFTCLICK || input == RIGHTCLICK) && tmp.col >= 1 && tmp.col <= col && tmp.row >= 1 && tmp.row <= row)
		{
			point = tmp;
		}
		switch (input)
		{
		case UP:
		case ARROW_UP:
			point.row--;
			showPoint = TRUE;
			if (point.row < 1)
			{
				point.row = row;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			point.row++;
			showPoint = TRUE;
			if (point.row > row)
			{
				point.row = 1;
			}
			break;
		case LEFT:
		case ARROW_LEFT:
			point.col--;
			showPoint = TRUE;
			if (point.col < 1)
			{
				point.col = col;
			}
			break;
		case RIGHT:
		case ARROW_RIGHT:
			point.col++;
			showPoint = TRUE;
			if (point.col > col)
			{
				point.col = 1;
			}
			break;
		case MINECHECK:
			if (!isFirst)
			{
				GameState(row, col, mineLeast, MINECHECK);
				while (GetKeyBoard() != ESC);
				MapPrint(row, col, mineLeast, point, showPoint, isFirst);
			}
			break;
		case JUMP:
			MapJump(row, col, mineLeast, point, showPoint, isFirst);
			printf("坐标跳转(row, col)：> ");
			while (!scanf("%d%d", &point.row, &point.col));
			showPoint = TRUE;
			MapPrint(row, col, mineLeast, point, showPoint, isFirst);
			break;
		case LEFTCLICK:
			showPoint = FALSE;
		case ENTER:
			if (isFirst == TRUE)
			{
				MapInit(row, col, mine, point);
				isFirst = FALSE;
			}
			if (g_map[point.row][point.col] == MINE && g_tag[point.row][point.col] != MARKED)
			{
				state = OVER;
			}
			else if (g_tag[point.row][point.col] == COVERED)
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
		case RIGHTCLICK:
			showPoint = FALSE;
		case MINEMARK:
			if (g_tag[point.row][point.col] != OPENED)
			{
				Gotoxy(point.col * 2, point.row);
				if (g_tag[point.row][point.col] == COVERED)
				{
					printf("△");
					g_tag[point.row][point.col] = MARKED;
					mineLeast--;
				}
				else
				{
					printf("■");
					g_tag[point.row][point.col] = COVERED;
					mineLeast++;
				}
				Sleep(20);
			}
			break;
		case SAVE:
			SaveOrLoad(&row, &col, &mineLeast, GAMESAVE);
			break;
		case ESC:
			SaveData(row, col, mineLeast, TMP);
			return;
		default:
			break;
		}
		if (!g_coveredBlank && !isFirst)
		{
			state = WIN;
		}
		point.row = BOUNDJUDGE(point.row, 1, row);
		point.col = BOUNDJUDGE(point.col, 1, col);
	}
	MapPrint(row, col, mineLeast, point, showPoint, isFirst);
	GameState(row, col, mineLeast, state);
	GetMouse(&point.row, &point.col);
}

void Set(int *row, int *col, int *mine)
{
	int state = CONTINUE;
	int input, tmp1, tmp2;
	
	SetPage(g_gameLevel);
	Gotoxy(6, 13);
	printf(" 方向键选择　回车键确认");
	while (!state)
	{
		Gotoxy(10, 6 + g_gameLevel);
		printf("◆");
		input = GetMouse(&tmp1, &tmp2);
		Gotoxy(10, 6 + g_gameLevel);
		printf("  ");
		if ((input == LEFTCLICK || input == RIGHTCLICK) && tmp1 >= 6 && tmp1 <= 9)
		{
			g_gameLevel = tmp1 - 6;
		}
		switch (input)
		{
		case UP:
		case ARROW_UP:
			g_gameLevel--;
			if (g_gameLevel < LEVEL1)
			{
				g_gameLevel = FREE;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			g_gameLevel++;
			if (g_gameLevel > FREE)
			{
				g_gameLevel = LEVEL1;
			}
			break;
		case RIGHTCLICK:
			break;
		case LEFTCLICK:
		case ENTER:
			state = OVER;
			break;
		case ESC:
			return;
		default:
			break;
		}
	}
	switch (g_gameLevel)
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
	default:
		break;
	}
}

void FreeDefine(int *row, int *col, int *mine)
{
	static int flag = DEFINEHEIGHT;
	int tmp1, tmp2;
	int input, *(p[3]) = { row, col, mine }, maxMine = MAXMINE(*row, *col);

	DefinePage(*row, *col, *mine, flag);
	while (1)
	{
		Gotoxy(8, 7 + flag);
		printf("◆");
		input = GetMouse(&tmp1, &tmp2);
		Gotoxy(8, 7 + flag);
		printf("  ");
		if ((input == LEFTCLICK || input == RIGHTCLICK) && tmp1 >= 7 && tmp1 <= 9)
		{
			flag = tmp1 - 7;
		}
		switch (input)
		{
		case UP:
		case ARROW_UP:
			flag--;
			if (flag < DEFINEHEIGHT)
			{
				flag = DEFINEMINE;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			flag++;
			if (flag > DEFINEMINE)
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
		case RIGHTCLICK:
			break;
		case LEFTCLICK:
		case ENTER:
			return;
		default:
			break;
		}
		*row = BOUNDJUDGE(*row, MINROW, MAXROW);
		*col = BOUNDJUDGE(*col, MINCOL, MAXCOL);
		maxMine = MAXMINE(*row, *col);
		*mine = BOUNDJUDGE(*mine, MINMINE, maxMine);
		
		Gotoxy(20, 7 + flag);
		printf("%3d", *(p[flag]));
		Gotoxy(7, 12);
		switch (flag)
		{
		case DEFINEHEIGHT:
			printf(" 设置高度 (范围9-24)  ");
			break;
		case DEFINEWIDTH:
			printf(" 设置宽度 (范围9-30)  ");
			break;
		case DEFINEMINE:
			printf(" 设置雷数 (范围10-%d) ", maxMine);
			break;
		default:
			break;
		}
	}
}

int Welcome()
{
	static int flag = WELCOMENEWGAME;
	int input, tmp1, tmp2;
	char *help[4] = { "     继续   ", "    新游戏  ", " 设置游戏难度 ", "   退出游戏 " };

	WelcomePage(flag);
	Gotoxy(13, 13);
	printf("%s", help[flag]);
	while (1)
	{
		Gotoxy(12, 6 + flag);
		printf("◆");
		input = GetMouse(&tmp1, &tmp2);
		Gotoxy(12, 6 + flag);
		printf("  ");
		if ((input == LEFTCLICK || input == RIGHTCLICK) && tmp1 >= 6 && tmp1 <= 9)
		{
			flag = tmp1 - 6;
		}
		switch (input)
		{
		case UP:
		case ARROW_UP:
			flag--;
			if (flag < WELCOMECONTINUE)
			{
				flag = WELCOMEEXIT;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			flag++;
			if (flag > WELCOMEEXIT)
			{
				flag = WELCOMECONTINUE;
			}
			break;
		case RIGHTCLICK:
			break;
		case LEFTCLICK:
		case ENTER:
			return flag;
		default:
			break;
		}
		Gotoxy(13, 13);
		printf("%s", help[flag]);
	}
}

void GameControl()
{
	int row = INITIALROWS, col = INITIALCOLS, mine = INITIALMINES;
	int o_row, o_col, o_mine;

	HideCursor();
	SetConsoleTitle("扫雷");
	InitNullList();
	LoadList();
	while (1)
	{
		switch (Welcome())
		{
		case GAMECONTINUE:
			SaveOrLoad(&o_row, &o_col, &o_mine, GAMELOAD);
			break;
		case NEWGAME:
			if (g_nowGameLevel != g_gameLevel)
			{
				g_nowGameLevel = g_gameLevel;
			}
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
