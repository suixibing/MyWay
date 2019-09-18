#include"func.h"

int Menu()
{
	int input;

	putchar('\n');
	printf("\t\t\t0、退出\n");
	printf("\t\t\t1、增加信息\n");
	printf("\t\t\t2、删除信息\n");
	printf("\t\t\t3、查找信息\n");
	printf("\t\t\t4、修改信息\n");
	printf("\t\t\t5、显示当前所有的信息\n");
	while (!scanf("%d", &input))
	{
		getchar();
	}

	return input;
}

void PrintTitle()
{
	printf("编号   姓名   性别    年龄   联系方式    住址\n");
}
void PrintMSG(int id)
{
	printf(" %d   %-8s %3s    %3d  %11s  %-10s\n", id + 1, g_mail.man[id].name, g_mail.man[id].sex, g_mail.man[id].age, g_mail.man[id].tele, g_mail.man[id].addr);
}

void InputMSG(MailMSG **p)
{
	printf("请输入姓名:>");
	scanf("%50s", (*p)->name);
	printf("请输入性别:>");
	scanf("%3s", (*p)->sex);
	printf("请输入年龄:>");
	scanf("%d", &(*p)->age);
	printf("请输入联系方式:>");
	scanf("%11s", (*p)->tele);
	printf("请输入住址:>");
	scanf("%50s", (*p)->addr);
}

void InsertMail()
{
	int i;
	MailMSG input, *p = &input;

	InputMSG(&p);
	if (g_mail.num % MANNUM == 0)
	{
		g_mail.man = (MailMSG*)realloc(g_mail.man, (g_mail.num / MANNUM + 1) * MANNUM * sizeof(MailMSG));
	}
	for (i = g_mail.num; i - 1 >= 0 && strcmp(g_mail.man[i - 1].name, input.name) > 0; i--)
	{
		g_mail.man[i] = g_mail.man[i - 1];
	}
	g_mail.man[i] = input;
	g_mail.num++;
}

int DeleteMail(int id)
{
	int i = id;

	if (id >= g_mail.num)
	{
		return ERROR;
	}
	while (i < g_mail.num)
	{
		if (i + 1 < MANNUM)
		{
			g_mail.man[i] = g_mail.man[i + 1];
		}
		i++;
	}
	g_mail.num--;
	if (g_mail.num % MANNUM == 0)
	{
		g_mail.man = (MailMSG*)realloc(g_mail.man, (g_mail.num / MANNUM + 1) * MANNUM * sizeof(MailMSG));
	}

	return TRUE;
}

int SearchMail(char *p)
{
	int i, flag, count = 0;
	char *t, age[5] = { 0 };

	for (i = 0; i < g_mail.num; i++)
	{
		do
		{
			flag = 1;
			t = strstr(g_mail.man[i].name, p);//在姓名中查找
			if (t)
			{
				break;
			}
			t = strstr(g_mail.man[i].addr, p);//在地址中查找
			if (t)
			{
				break;
			}
			t = strstr(g_mail.man[i].sex, p);//在性别中查找
			if (t)
			{
				break;
			}
			t = strstr(g_mail.man[i].tele, p);//在联系方式中查找
			if (t)
			{
				break;
			}
			sprintf(age, "%d", g_mail.man[i].age);
			t = strstr(age, p);//在年龄中查找
			if (t)
			{
				break;
			}
			flag = 0;
		} while (0);
		if (flag)
		{
			PrintMSG(i);
			count++;
		}
	}

	return count;
}

int ChangeMail(int id)
{
	char input[50] = { 0 };
	if (id >= g_mail.num)
	{
		return ERROR;
	}
	printf("姓名是否要修改？(y/n)");
	scanf("%s", input);
	if (!strcmp(input, "y") || !strcmp(input, "Y"))
	{
		printf("请输入新的姓名:>");
		scanf("%50s", g_mail.man[id].name);
	}
	printf("性别是否要修改？(y/n)");
	scanf("%s", input);
	if (!strcmp(input, "y") || !strcmp(input, "Y"))
	{
		printf("请输入新的性别:>");
		scanf("%3s", g_mail.man[id].sex);
	}
	printf("年龄是否要修改？(y/n)");
	scanf("%s", input);
	if (!strcmp(input, "y") || !strcmp(input, "Y"))
	{
		printf("请输入新的年龄:>");
		scanf("%d", &g_mail.man[id].age);
	}
	printf("联系方式是否要修改？(y/n)");
	scanf("%s", input);
	if (!strcmp(input, "y") || !strcmp(input, "Y"))
	{
		printf("请输入新的联系方式:>");
		scanf("%11s", g_mail.man[id].tele);
	}
	printf("住址是否要修改？(y/n)");
	scanf("%s", input);
	if (!strcmp(input, "y") || !strcmp(input, "Y"))
	{
		printf("请输入新的住址:>");
		scanf("%50s", g_mail.man[id].addr);
	}

	return TRUE;
}

void OutputMail()
{
	int i;

	PrintTitle();
	for (i = 0; i < g_mail.num; i++)
	{
		PrintMSG(i);
	}
}

void LoadMail()
{
	FILE *infile = fopen("..\\C_NC_day19\\mail.txt", "rb");

	fread(&g_mail.num, sizeof(int), 1, infile);
	if (g_mail.num > MANNUM)
	{
		g_mail.man = (MailMSG*)realloc(g_mail.man, (g_mail.num / MANNUM + 1) * MANNUM * sizeof(MailMSG));
	}
	fread(g_mail.man, sizeof(MailMSG), g_mail.num, infile);
	fclose(infile);
}

void SaveMail()
{
	FILE *outfile = fopen("..\\C_NC_day19\\mail.txt", "wb");

	fwrite(&g_mail.num, sizeof(int), 1, outfile);
	fwrite(g_mail.man, sizeof(MailMSG), g_mail.num, outfile);
	free(g_mail.man);
	fclose(outfile);
}