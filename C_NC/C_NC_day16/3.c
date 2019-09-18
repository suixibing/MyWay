#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int Mul(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return a / b;
}

int main3()
{
	int i;
	int(*p[5])(int, int) = { Add, Sub, Mul, Div };

	for (i = 0; i < 4; i++)
	{
		printf("%d ", (*p[i])(1, 2));
	}
	putchar('\n');

	system("pause");
	return 0;
}
