#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int GetEven(int value)
{
	int i, j, k, num, tmp;

	for (i = 1, j = 2, k = 1, num = 0; i < 8 * sizeof(value); i += 2, j *= 4, k *= 10)
	{
		tmp = ((1 << i) & value);
		num = num + k * tmp / j;
	}

	return num;
}

int GetOdd(int value)
{
	int i, j, k, num, tmp;

	for (i = 0, j = 1, k = 1, num = 0; i < 8 * sizeof(value); i += 2, j *= 4, k *= 10)
	{
		tmp = ((1 << i) & value);
		num = num + k * tmp / j;
	}

	return num;
}

int main2()
{
	int n, ret1, ret2;

	scanf("%d", &n);
	ret1 = GetEven(n);
	ret2 = GetOdd(n);
	printf("偶数位：%d 奇数位：%d\n", ret1, ret2);
	
	system("pause");
	return 0;
}
