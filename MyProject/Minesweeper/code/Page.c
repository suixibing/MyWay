#include"Page.h"

char g_nullList[LISTLINES][SAVECOLS - BOUNDARY_SIZE_CHAR + 1];
extern char g_saveList[MAXSAVENUM][SAVECOLS - BOUNDARY_SIZE_CHAR + 1];
int lastFlag = 0;

void WelcomePage(int flag)
{
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

	system("cls");
	printf(page);
}

void SetPage(int flag)
{
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
	strcat(page, "　　　 　　Esc-返回首页\n");

	system("cls");
	printf(page);
}

void DefinePage(int row, int col, int mine, int flag)
{
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
	strcat(page, "　　　     自定义游戏设置\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	system("cls");
	printf(page, row, col, mine);
}

void SavePage(int flag)
{
	char page[PAGESIZE_COMMOM] = { 0 };

	if (flag / LISTLINES + 1 == lastFlag && lastFlag != -99 && lastFlag != -101)
	{
		Gotoxy(3, 1 + flag % LISTLINES);
		printf("◆");
		return;
	}
	SetConsoleSize(SAVECOLS, SAVELINES);

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
	strcat(page, "　　　　　     Esc返回首页");
	
	system("cls");
	if (flag >= FIRSTSAVE || flag == TMP)
	{
		printf(page, flag / LISTLINES + 1);
		lastFlag = flag / LISTLINES + 1;
	}
	else
	{
		printf(page, flag / LISTLINES);
		lastFlag = flag / LISTLINES;
	}
	Gotoxy(3, 1 + flag % LISTLINES);
	printf("◆");
}