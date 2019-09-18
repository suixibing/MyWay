#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main3()
{
	int i;
	char input[20];

	for (i = 3; i > 0; i--)
	{
		printf("请输入密码:>");
		scanf("%s", input);
		if (strcmp(input, "123456") == 0)
		{
			printf("密码正确！\n");
			break;
		}
		else
		{
			printf("密码错误！请重新输入！(还有%d次)\n", i-1);
		}
	}
	if (i == 0)
	{
		printf("密码全部错误，退出系统！！\n");
	}

	system("pause");
	return 0;
}