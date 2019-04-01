#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void PrintfMul(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %2d ", j, i, i*j);
		}
		putchar('\n');
	}
}

int main1()
{
	int input;

	scanf("%d", &input);
	PrintfMul(input);

	system("pause");
	return 0;
}