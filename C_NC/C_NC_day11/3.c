#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int PutBits(int value)
{
	int i, j, k, num, tmp;

	for (i = 0, j = 1, k = 1, num = 0; i < 8 * sizeof(value); i += 1, j *= 2, k *= 10)
	{
		tmp = ((1 << i) & value);
		num = num + k * tmp / j;
	}

	return num;
}

int main3()
{
	int n, ret;

	scanf("%d", &n);
	ret = PutBits(n);
	printf("%d\n", ret);
	
	system("pause");
	return 0;
}
