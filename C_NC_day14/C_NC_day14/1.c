#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int Move(char *str)
{
	char tmp;

	tmp = *str++;
	while (*str != '\0')
	{
		*(str - 1) = *str;
		++str;
	}
	*(str - 1) = tmp;

	return 1;
}

int main1()
{
	int k;
	char str[] = "ABCD";

	scanf("%d", &k);
	while (k > 0)
	{
		Move(str);
		--k;
	}
	printf("%s\n", str);

	system("pause");
	return 0;
}
