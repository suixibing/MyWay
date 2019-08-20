#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include"Control.h"
#include"Extern.h"
#include"Show.h"
#include"Map.h"

extern int gameLevel;
extern int coveredBlank;
extern char map[26][32];
extern char tag[26][32];
char save[10][45];

void SaveList(int flag)
{
	time_t saveTime;
	char tmp[40] = "    ";
	FILE *pf = fopen("Save\\saveList.txt", "w");

	time(&saveTime); // 获取当前时间
	switch (gameLevel)
	{
	case LEVEL1:
		strcat(tmp, " 初级  ");
		break;
	case LEVEL2:
		strcat(tmp, " 中级  ");
		break;
	case LEVEL3:
		strcat(tmp, " 高级  ");
		break;
	case FREE:
		strcat(tmp, "自定义 ");
		break;
	default:
		break;
	}
	strncat(tmp, ctime(&saveTime), 24); // ctime(&saveTime); 转换为当地时间
	strcat(tmp, " ");
	strcpy(save[flag], tmp);
	for (int i = 0; i < 10; i++)
	{
		fputs(save[i], pf);
		fputc('\n', pf);
	}
	fclose(pf);
}

void LoadList()
{
	char ch;
	FILE *pf = fopen("Save\\saveList.txt", "r");

	for (int i = 0; i < 10; i++)
	{
		fgets(save[i], 37, pf);
		ch = fgetc(pf);
	}
	fclose(pf);
}

void SaveData(int row, int col, int mineLeast, int flag)
{
	char filename[20] = "Save\\save";
	char num[10][2] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
	FILE *pf;

	strcat(filename, num[flag]);
	strcat(filename, ".data");
	pf = fopen(filename, "wb");
	fwrite(&row, sizeof(int), 1, pf);
	fwrite(&col, sizeof(int), 1, pf);
	fwrite(&mineLeast, sizeof(int), 1, pf);
	fwrite(&coveredBlank, sizeof(int), 1, pf);
	for (int i = 1; i <= row; i++)
	{
		fwrite(&map[i][1], sizeof(char), col, pf);
		fwrite(&tag[i][1], sizeof(char), col, pf);
	}
	fclose(pf);
}

int LoadData(int *row, int *col, int *mineLeast, int flag)
{
	char filename[20] = "Save\\save";
	char num[][3] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
	FILE *pf;

	strcat(filename, num[flag]);
	strcat(filename, ".data");
	pf = fopen(filename, "rb");

	SavePage(flag);
	if (!pf)
	{
		printf("　　　　　　  读档失败!\n");
		//getchar();
		GetKeyBoard();
		return ERROR;
	}
	fread(row, sizeof(int), 1, pf);
	fread(col, sizeof(int), 1, pf);
	fread(mineLeast, sizeof(int), 1, pf);
	fread(&coveredBlank, sizeof(int), 1, pf);
	for (int i = 1; i <= *row; i++)
	{
		fread(&map[i][1], sizeof(char), (unsigned)*col, pf);
		fread(&tag[i][1], sizeof(char), (unsigned)*col, pf);
	}
	fclose(pf);
	printf("　　　　　　  读档成功!\n");
	return SUCCESS;
}

void Save(int row, int col, int mineLeast)
{
	int flag = 0, state = CONTINUE;
	
	while (!state)
	{
		SavePage(flag);
		switch (GetKeyBoard())
		{
		case UP:
		case ARROW_UP:
			flag--;
			if (flag == -1)
			{
				flag = 9;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			flag++;
			if (flag == 10)
			{
				flag = 0;
			}
			break;
		case ENTER:
			state = OVER;
			break;
		case ESC:
			return;
		default:
			break;
		}
	}
	SaveList(flag);
	SaveData(row, col, mineLeast, flag);
	SavePage(flag);
	printf("　　　　　　  保存成功!\n");
	getchar();
}

void Load(int *row, int *col, int *mineLeast)
{
	int flag = 0, state = CONTINUE;

	SavePage(flag);
	while (!state)
	{
		switch (GetKeyBoard())
		{
		case UP:
		case ARROW_UP:
			flag--;
			if (flag == -1)
			{
				flag = 9;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			flag++;
			if (flag == 10)
			{
				flag = 0;
			}
			break;
		case ENTER:
			state = OVER;
			break;
		case ESC:
			return;
		default:
			break;
		}
		SavePage(flag);
	}
	if (LoadData(row, col, mineLeast, flag))
	{
		Game(*row, *col, *mineLeast, NOTFIRST);
	}
}

void SavePage(int flag)
{
	char page[1024] = { 0 };

	save[flag][1] = 0xa1;
	save[flag][2] = 0xf4;
	strcat(page, "████████████████████\n");
	//strcat(page, "█ ◆ 自定义 Tue Aug 20 15:42:11 2019 █\n"); // 保存样例
	//strcat(page, "█    未存档 NNN NNN NN NN:NN:NN NNNN █\n"); // 保存样例
	for (int i = 0; i < 10; i++)
	{
		strcat(page, "█");
		strcat(page, save[i]);
		strcat(page, "█\n");
	}
	strcat(page, "████████████████████\n");
	strcat(page, "　　　 方向键选择　回车键确认\n");
	strcat(page, "　　　　　　 c-继续游戏\n");
	save[flag][1] = ' ';
	save[flag][2] = ' ';

	system("cls");
	puts(page);
}