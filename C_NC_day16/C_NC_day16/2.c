#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

extern int Add(int, int);

int main2()
{
	int(*p)(int, int) = Add;

	printf("%d\n", (*p)(1, 2));

	system("pause");
	return 0;
}
