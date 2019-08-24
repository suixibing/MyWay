#include"Page.h"

char g_nullList[LISTLINES][SAVECOLS - BOUNDARY_SIZE_CHAR + 1];
extern char g_saveList[MAXSAVENUM][SAVECOLS - BOUNDARY_SIZE_CHAR + 1];

void WelcomePage(int flag)
{
	int set = WELCOMECOLS * 6 + 12;
	char page[PAGESIZE_COMMOM] = { 0 };

	SetConsoleSize(WELCOMECOLS, WELCOMELINES);
	strcat(page, "████████████████████"); // 一行 40 个字符
	strcat(page, "█　　　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　　扫　　　　雷　　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　　　　继续　　　　　　　　█");
	strcat(page, "█　　　　　　　 新游戏 　　　　　　　█");
	strcat(page, "█　　　　　　　游戏设置　　　　　　　█");
	strcat(page, "█　　　　　　　　退出　　　　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　　　█");
	strcat(page, "████████████████████");
	strcat(page, "　　　   方向键选择　回车键确认\n");

	switch (flag)
	{
	case WELCOMECONTINUE:
		strcat(page, "　　　　　　　　继续游戏");
		break;
	case WELCOMENEWGAME:
		set += WELCOMECOLS;
		strcat(page, "　　　　　　　　开始游戏");
		break;
	case WELCOMESET:
		set += WELCOMECOLS * 2;
		strcat(page, "　　　　　　　设置游戏难度");
		break;
	case WELCOMEEXIT:
		set += WELCOMECOLS * 3;
		strcat(page, "　　　　　　　　退出游戏");
		break;
	default:
		break;
	}
	page[set] = 0xa1;
	page[set + 1] = 0xf4;
	system("cls");
	printf(page);
	page[set] = ' ';
	page[set + 1] = ' ';
}

void SetPage(int flag)
{
	int set = SETCOLS * 6 + 10;
	char page[PAGESIZE_COMMOM] = { 0 };

	SetConsoleSize(SETCOLS, SETLINES);
	strcat(page, "██████████████████");  // 一行 36 个字符
	strcat(page, "█　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　 扫      雷 　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　　初　　级　　　　　　█");
	strcat(page, "█　　　　　　中　　级　　　　　　█");
	strcat(page, "█　　　　　  高　　级　　　　　　█");
	strcat(page, "█　　　　　　自 定 义　　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　█");
	strcat(page, "██████████████████");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　　　　  Esc-首页");

	switch (flag)
	{
	case LEVEL1:
		break;
	case LEVEL2:
		set += SETCOLS;
		break;
	case LEVEL3:
		set += SETCOLS * 2;
		break;
	case FREE:
		set += SETCOLS * 3;
	default:
		break;
	}
	page[set] = 0xa1;
	page[set + 1] = 0xf4;
	system("cls");
	printf(page);
	page[set] = ' ';
	page[set + 1] = ' ';
}

void DefinePage(int row, int col, int mine, int flag)
{
	int set = SETCOLS * 7 + 8;
	char page[PAGESIZE_COMMOM] = { 0 };

	SetConsoleSize(SETCOLS, SETLINES);
	strcat(page, "██████████████████"); // 一行 37 个字符（包含换行符）
	strcat(page, "█　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　 扫      雷 　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　█");
	strcat(page, "█　　　　　高  度：%3d 　　　　　█");
	strcat(page, "█　　　　　宽  度：%3d　　 　　　█");
	strcat(page, "█　　　  　雷  数：%3d     　　　█");
	strcat(page, "█　　　　　　　　　　　　　　　　█");
	strcat(page, "██████████████████");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	switch (flag)
	{
	case DEFINEHEIGHT:
		strcat(page, "　　　  设置高度（范围9-24）");
		break;
	case DEFINEWIDTH:
		set += SETCOLS;
		strcat(page, "　　　  设置宽度（范围9-30）");
		break;
	case DEFINEMINE:
		set += SETCOLS * 2;
		strcat(page, "　　　  设置雷数（范围10-%d）");
		break;
	default:
		break;
	}
	page[set] = 0xa1;
	page[set + 1] = 0xf4;
	system("cls");
	if (flag != DEFINEMINE)
	{
		printf(page, row, col, mine);
	}
	else
	{
		printf(page, row, col, mine, MAXMINE(row, col));
	}
	page[set] = ' ';
	page[set + 1] = ' ';
}

void SavePage(int flag)
{
	char page[PAGESIZE_COMMOM] = { 0 };

	SetConsoleSize(SAVECOLS, SAVELINES);
	if (flag >= FIRSTSAVE && flag <= LASTSAVE)
	{
		g_saveList[flag][1] = 0xa1;
		g_saveList[flag][2] = 0xf4;
	}
	strcat(page, "████████████████████");
	//strcat(page, "█ ◆ 自定义 Tue Aug 20 15:42:11 2019 █"); // 保存样例
	//strcat(page, "█    未存档 NNN NNN NN NN:NN:NN NNNN █"); // 保存样例
	for (int i = flag / LISTLINES * LISTLINES; i < flag / LISTLINES * LISTLINES + LISTLINES; i++)
	{
		strcat(page, "█");
		if (flag >= FIRSTSAVE && flag <= LASTSAVE || flag == TMP)
		{
			strcat(page, g_saveList[i]);
		}
		else
		{
			strcat(page, g_nullList[abs(i % 10)]);
		}
		strcat(page, "█");
	}
	strcat(page, "█████████████████第%2d页");
	strcat(page, "　　　　　      Esc-退出");
	if (flag >= FIRSTSAVE && flag <= LASTSAVE)
	{
		g_saveList[flag][1] = ' ';
		g_saveList[flag][2] = ' ';
	}

	system("cls");
	if (flag >= FIRSTSAVE || flag == TMP)
	{
		printf(page, flag / LISTLINES + 1);
	}
	else
	{
		printf(page, flag / LISTLINES);
	}
}