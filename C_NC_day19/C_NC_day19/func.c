#include"func.h"

int Menu()
{
	int input;

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
	printf("   姓名   性别    年龄   联系方式    住址\n");
}
void PrintMSG(int id)
{
	printf("  %-8s %3s    %3d  %11s  %-10s\n", g_mail.man[id].name, g_mail.man[id].sex, g_mail.man[id].age, g_mail.man[id].tele, g_mail.man[id].addr);
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
	for (i = g_mail.num; i > 0 && strcmp(g_mail.man[i - 1].name, input.name) > 0; i++)
	{
		if (i < MANNUM)
		{
			g_mail.man[i] = g_mail.man[i - 1];
		}
	}
	g_mail.man[i] = input;
	g_mail.num++;
}

void DeleteMail()
{
	printf("DeleteMail()\n");
}

void SearchMail()
{
	printf("SearchMail()\n");
}

void ChangeMail()
{
	printf("ChangeMail()\n");
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