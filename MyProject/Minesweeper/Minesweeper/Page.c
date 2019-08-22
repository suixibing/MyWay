#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Control.h"
#include"Page.h"
#include"Map.h"

extern char saveList[100][37];

void WelcomePage(int flag)
{
	int set = 41 * 6 + 12;
	char page[1024] = { 0 };

	strcat(page, "████████████████████\n"); // 一行 41 个字符（包含换行符）
	strcat(page, "█　　　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　扫　　　　雷　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　继续　　　　　　　　█\n");
	strcat(page, "█　　　　　　　 新游戏 　　　　　　　█\n");
	strcat(page, "█　　　　　　　游戏设置　　　　　　　█\n");
	strcat(page, "█　　　　　　　　退出　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　　　█\n");
	strcat(page, "████████████████████\n");
	strcat(page, "　　　   方向键选择　回车键确认\n");

	switch (flag)
	{
	case WELCOMECONTINUE:
		strcat(page, "　　　　　　　　继续游戏\n\n");
		break;
	case WELCOMENEWGAME:
		set += 41;
		strcat(page, "　　　　　　　　开始游戏\n\n");
		break;
	case WELCOMESET:
		set += 41 * 2;
		strcat(page, "　　　　　　　设置游戏难度\n\n");
		break;
	case WELCOMEEXIT:
		set += 41 * 3;
		strcat(page, "　　　　　　　　退出游戏\n\n");
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
	int set = 37 * 6 + 10;
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n");  // 一行 37 个字符（包含换行符）
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　初　　级　　　　　　█\n");
	strcat(page, "█　　　　　　中　　级　　　　　　█\n");
	strcat(page, "█　　　　　  高　　级　　　　　　█\n");
	strcat(page, "█　　　　　　自 定 义　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　　　　 Esc-首页\n\n");

	switch (flag)
	{
	case LEVEL1:
		break;
	case LEVEL2:
		set += 37;
		break;
	case LEVEL3:
		set += 37 * 2;
		break;
	case FREE:
		set += 37 * 3;
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
	int set = 37 * 7 + 10;
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n"); // 一行 37 个字符（包含换行符）
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　高  度：%3d 　　　　　█\n");
	strcat(page, "█　　　　　宽  度：%3d　　 　　　█\n");
	strcat(page, "█　　　  　雷  数：%3d     　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	switch (flag)
	{
	case DEFINEHEIGHT:
		strcat(page, "　　　  设置高度（范围9-24）\n\n");
		break;
	case DEFINEWIDTH:
		set += 37;
		strcat(page, "　　　  设置宽度（范围9-30）\n\n");
		break;
	case DEFINEMINE:
		set += 37 * 2;
		strcat(page, "　　　  设置雷数（范围10-%d）\n\n");
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
	char page[1024] = { 0 };

	if (flag != TMP)
	{
		saveList[flag][1] = 0xa1;
		saveList[flag][2] = 0xf4;
	}
	else
	{
		flag++;
	}
	strcat(page, "████████████████████\n");
	//strcat(page, "█ ◆ 自定义 Tue Aug 20 15:42:11 2019 █\n"); // 保存样例
	//strcat(page, "█    未存档 NNN NNN NN NN:NN:NN NNNN █\n"); // 保存样例
	for (int i = flag / 10 * 10; i < flag / 10 * 10 + 10; i++)
	{
		strcat(page, "█");
		strcat(page, saveList[i]);
		strcat(page, "█\n");
	}
	strcat(page, "█████████████████第%2d页\n");
	strcat(page, "　　　   方向键选择　回车键确认\n");
	strcat(page, "　　　　　  C-继续上次游戏\n\n");
	saveList[flag][1] = ' ';
	saveList[flag][2] = ' ';

	system("cls");
	printf(page, flag / 10 + 1);
}