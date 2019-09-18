#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int Fact1(int n)
{
	int i = 1;
	int aim = 1;
	while (i <= n)
	{
		aim *= i;
		i++;
	}
	return aim;
}

int Fact2(int n)
{
	if (n > 1)
	{
		return Fact2(n - 1) * n;
	}
	return n;
}

int main6()
{
	int input, ret;
	scanf("%d", &input);

	ret = Fact2(input);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
