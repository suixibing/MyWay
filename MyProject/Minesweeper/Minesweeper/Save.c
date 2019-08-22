#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include"Control.h"
#include"Save.h"
#include"Page.h"
#include"Map.h"

extern int gameLevel;
extern int coveredBlank;
extern char map[26][32];
extern char tag[26][32];
char saveList[100][37];

void SaveList(int flag)
{
	time_t saveTime;
	char tmp[40] = "    ";
	FILE *pf = fopen("..\\Save\\saveList.txt", "w");

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
	strcpy(saveList[flag], tmp);
	for (int i = 0; i <= LASTSAVE; i++)
	{
		fputs(saveList[i], pf);
		fputc('\n', pf);
	}
	fclose(pf);
}

void LoadList(int flag)
{
	int num = 0;
	FILE *pf = fopen("..\\Save\\saveList.txt", "r");

	while (!feof(pf))
	{
		fgets(saveList[num++], 37, pf);
		fgetc(pf);
	}
	fclose(pf);
}

void SaveData(int row, int col, int mineLeast, int flag)
{
	char filename[100] = "..\\Save\\save";
	char num[5];
	FILE *pf;

	_itoa(flag + 1, num, 10);
	if (flag == TMP)
	{
		pf = fopen("..\\Save\\tmp.data", "wb");
	}
	else
	{
		strcat(filename, num);
		strcat(filename, ".data");
		pf = fopen(filename, "wb");
	}

	fwrite(&row, sizeof(int), 1, pf);
	fwrite(&col, sizeof(int), 1, pf);
	fwrite(&mineLeast, sizeof(int), 1, pf);
	fwrite(&gameLevel, sizeof(int), 1, pf);
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
	char filename[100] = "..\\Save\\save";
	char num[5];
	FILE *pf;

	_itoa(flag + 1, num, 10);
	if (flag == TMP)
	{
		pf = fopen("..\\Save\\tmp.data", "rb");
	}
	else
	{
		strcat(filename, num);
		strcat(filename, ".data");
		pf = fopen(filename, "rb");
	}

	SavePage(flag);
	if (!pf)
	{
		printf("　　　　　　  读档失败!\n");
		GetKeyBoard();
		return ERROR;
	}
	fread(row, sizeof(int), 1, pf);
	fread(col, sizeof(int), 1, pf);
	fread(mineLeast, sizeof(int), 1, pf);
	fread(&gameLevel, sizeof(int), 1, pf);
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
	int jump;
	static int flag = 0;
	int state = CONTINUE;
	
	while (!state)
	{
		SavePage(flag);
		switch (GetKeyBoard())
		{
		case UP:
		case ARROW_UP:
			flag--;
			if (flag == FIRSTSAVE - 1)
			{
				flag = LASTSAVE;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			flag++;
			if (flag == LASTSAVE + 1)
			{
				flag = FIRSTSAVE;
			}
			break;
		case LEFT:
		case ARROW_LEFT:
			flag -= 10;
			if (flag < FIRSTSAVE)
			{
				flag += LASTSAVE - FIRSTSAVE + 1;
			}
			break;
		case RIGHT:
		case ARROW_RIGHT:
			flag += 10;
			if (flag > LASTSAVE)
			{
				flag -= LASTSAVE - FIRSTSAVE + 1;
			}
			break;
		case JUMP:
			printf("请输入您要跳转的页码：> ");
			while (!scanf("%d", &jump));
			flag = (jump - 1) * 10 + flag % 10;
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
	int jump;
	static int flag = 0;
	int state = CONTINUE;

	SavePage(flag);
	while (!state)
	{
		switch (GetKeyBoard())
		{
		case UP:
		case ARROW_UP:
			flag--;
			if (flag < FIRSTSAVE)
			{
				flag = LASTSAVE;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			flag++;
			if (flag > LASTSAVE)
			{
				flag = FIRSTSAVE;
			}
			break;
		case LEFT:
		case ARROW_LEFT:
			flag -= 10;
			if (flag < FIRSTSAVE)
			{
				flag += LASTSAVE - FIRSTSAVE + 1;
			}
			break;
		case RIGHT:
		case ARROW_RIGHT:
			flag += 10;
			if (flag > LASTSAVE)
			{
				flag -= LASTSAVE - FIRSTSAVE + 1;
			}
			break;
		case JUMP:
			printf("请输入您要跳转的页码：> ");
			while (!scanf("%d", &jump));
			flag = (jump - 1) * 10 + flag % 10;
			break;
		case 'C':
			flag = TMP; // 临时存档
		case ENTER:
			state = OVER;
			break;
		case ESC:
			return;
		default:
			break;
		}
		if (flag > 99)
		{
			flag = 0;
		}
		SavePage(flag);
	}
	if (LoadData(row, col, mineLeast, flag))
	{
		Game(*row, *col, *mineLeast, FALSE);
	}
}