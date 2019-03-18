#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b;
	int tmp = 0;
	scanf("%d%d", &a, &b);
	tmp = a;
	a = b;
	b = tmp;
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}