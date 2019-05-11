#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int JudgeMove(char *str1, char *str2)
{
	char tmp;
	int i, j, num = strlen(str1);

	j = num;
	while (num > 0)
	{
		tmp = str1[0];
		for (i = 0; i + 1 < j; i++)
		{
			str1[i] = str1[i + 1];
		}
		str1[i] = tmp;
		if (!strcmp(str1, str2))
		{
			return 1;
		}
		--num;
	}

	return 0;
}

int main()
{
	char str1[50] = { 0 }, str2[50] = { 0 };

	scanf("%s%s", str1, str2);
	printf("%d\n", JudgeMove(str1, str2));

	system("pause");
	return 0;
}
