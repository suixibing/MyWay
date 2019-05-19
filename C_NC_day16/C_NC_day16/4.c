#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

extern int Add(int, int);
extern int Sub(int, int);
extern int Mul(int, int);
extern int Div(int, int);

int main4()
{
	int i;
	int(*p[5])(int, int) = { Add, Sub, Mul, Div };
	int(*(*pa)[5])(int, int) = &p;

	for (i = 0; i < 4; i++)
	{
		printf("%d ", (*pa)[i](1, 2));
	}
	putchar('\n');

	system("pause");
	return 0;
}
