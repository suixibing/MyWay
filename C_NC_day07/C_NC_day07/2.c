#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int Pow(int n, int k)
{
	int i, tmp = 1;
	if (k >= 1)
	{
		tmp = n * Pow(n, k - 1);
	}
	return tmp;
}

int main2()
{
	int n, k, ret;
	scanf("%d%d", &n, &k);
	ret = Pow(n, k);

	printf("%d\n", ret);
	system("pause");
	return 0;
}
