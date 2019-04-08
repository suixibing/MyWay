#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#define MAX 100


int main3()
{
	int i, j, n, tmp[MAX] = { 0 }, a[MAX] = { 0 };
	a[1] = 1;

	scanf("%d", &n);
	printf("%2d\n", a[1]);
	for (i = 1; i < n; i++)
	{
		for (j = 1; a[j] + a[j - 1] != 0 && j < MAX; j++)
		{
			tmp[j] = a[j] + a[j - 1];
		}
		for (j = 0; j <= i; j++)
		{
			printf("%2d ", tmp[j + 1]);
			
		}
		for (j = 0; j < MAX; j++)
		{
			a[j] = tmp[j];
		}
		putchar('\n');
	}

	system("pause");
	return 0;
}
