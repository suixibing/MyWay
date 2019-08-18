#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Control.h"
#include"Show.h"

void (*welcome[3])() = { WelcomeStart, WelcomeSet, WelcomeExit };

void WelcomeStart()
{
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n");
	strcat(page, "█                                █\n");
	strcat(page, "█                                █\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█                                █\n");
	strcat(page, "█                                █\n");
	strcat(page, "█                                █\n");
	strcat(page, "█　　　　◆ Game Start 　　　　　█\n");
	strcat(page, "█　　　　　  Game Set　　　　　　█\n");
	strcat(page, "█　　　　　　  Exit　　　　　　　█\n");
	strcat(page, "█                                █\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　　　　 开始游戏\n");

	system("cls");
	puts(page);
}

void WelcomeSet()
{
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n");
	strcat(page, "█                                █\n");
	strcat(page, "█                                █\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█                                █\n");
	strcat(page, "█                                █\n");
	strcat(page, "█                                █\n");
	strcat(page, "█　　　　   Game Start 　　　　　█\n");
	strcat(page, "█　　　　◆  Game Set　　　　　　█\n");
	strcat(page, "█　　　　  　  Exit　　　　　　　█\n");
	strcat(page, "█                                █\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　　 　设置地图大小\n");

	system("cls");
	puts(page);
}

void WelcomeExit()
{
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n");
	strcat(page, "█                                █\n");
	strcat(page, "█                                █\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█                                █\n");
	strcat(page, "█                                █\n");
	strcat(page, "█                                █\n");
	strcat(page, "█　　　　   Game Start 　　　　　█\n");
	strcat(page, "█　　　      Game Set　　　　　　█\n");
	strcat(page, "█　　　　◆　  Exit　　　　　　　█\n");
	strcat(page, "█                                █\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　　　　 退出游戏\n");

	system("cls");
	puts(page);
}

void SetPrimary()
{
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　◆　初　　级　　　　　　█\n");
	strcat(page, "█　　　　　　中　　级　　　　　　█\n");
	strcat(page, "█　　　　　  高　　级　　　　　　█\n");
	strcat(page, "█　　　　　　自 定 义　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　　　　 退出游戏\n");

	system("cls");
	puts(page);
}

void SetIntermediate()
{
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　  　初　　级　　　　　　█\n");
	strcat(page, "█　　　　◆　中　　级　　　　　　█\n");
	strcat(page, "█　　　　　  高　　级　　　　　　█\n");
	strcat(page, "█　　　　　　自 定 义　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　　　　 退出游戏\n");

	system("cls");
	puts(page);
}

void SetExpert()
{
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　  初　　级　　　　　　█\n");
	strcat(page, "█　　　　　　中　　级　　　　　　█\n");
	strcat(page, "█　　　　◆  高　　级　　　　　　█\n");
	strcat(page, "█　　　　　　自 定 义　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　　　　 退出游戏\n");

	system("cls");
	puts(page);
}

void SetFree()
{
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　  初　　级　　　　　　█\n");
	strcat(page, "█　　　　　　中　　级　　　　　　█\n");
	strcat(page, "█　　　　    高　　级　　　　　　█\n");
	strcat(page, "█　　　　◆　自 定 义　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　　　　 退出游戏\n");

	system("cls");
	puts(page);
}

void DefineHeight(int *row, int *col, int *mine)
{
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　◆高  度：%3d 　　　　　█\n");
	strcat(page, "█　　　　　宽  度：%3d　　 　　　█\n");
	strcat(page, "█　　　    雷  数：%3d     　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　  设置高度（范围9-24）\n");

	system("cls");
	printf(page, *row, *col, *mine);
}

void DefineWidth(int *row, int *col, int *mine)
{
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　  高  度：%3d 　　　　　█\n");
	strcat(page, "█　　　　◆宽  度：%3d　　 　　　█\n");
	strcat(page, "█　　　    雷  数：%3d     　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　  设置宽度（范围9-30）\n");

	system("cls");
	printf(page, *row, *col, *mine);
}

void DefineMine(int *row, int *col, int *mine)
{
	char page[1024] = { 0 };

	strcat(page, "██████████████████\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "█　　　　  高  度：%3d 　　　　　█\n");
	strcat(page, "█　　　　  宽  度：%3d　　 　　　█\n");
	strcat(page, "█　　　  ◆雷  数：%3d     　　　█\n");
	strcat(page, "█　　　　　　　　　　　　　　　　█\n");
	strcat(page, "██████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　  设置雷数（范围10-%3d）\n");

	system("cls");
	printf(page, *row, *col, *mine, *row * *col * 9 / 10);
}

int WelcomePage()
{
	int x = 0;

	while (1)
	{
		welcome[x]();
		switch (GetKeyBoard())
		{
		case ARROW_UP:
			x--;
			if (x == -1)
			{
				x = 2;
			}
			break;
		case ARROW_DOWN:
			x++;
			if (x == 3)
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
//
//int DefinePage(int *row, int *col, int *mine)
//{
//	int x = 0;
//
//	while (1)
//	{
//		define[x](row, col, mine);
//		switch (GetKeyBoard())
//		{
//		case ARROW_UP:
//			x--;
//			if (x == -1)
//			{
//				x = 2;
//			}
//			break;
//		case ARROW_DOWN:
//			x++;
//			if (x == 3)
//			{
//				x = 0;
//			}
//			break;
//		case ENTER:
//			return x;
//		default:
//			break;
//		}
//	}
//}

