#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i, sum = 0, tmp = 0;

	scanf("%d", &n);
	for (i = 0; i < 5; i++)
	{
		tmp = tmp * 10 + n;
		sum += tmp;
	}

	printf("%d\n", sum);
	system("pause");
	return 0;
}