#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#define MAX 100


int main()
{
	int i, j, n, a[MAX] = { 0 };
	a[0] = 1;

	scanf("%d", &n);

	for (j = 1; j <= n; j++)
	{
		for (i = j - 1; i > 0; i--)
		{
			a[i] = a[i] + a[i - 1];
		}
		for (i = 0; i < j; i++)
		{
			printf("%3d ", a[i]);
		}
		putchar('\n');
		
	}

	system("pause");
	return 0;
}
