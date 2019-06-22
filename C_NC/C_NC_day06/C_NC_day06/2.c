#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void Swap(int *px, int *py)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}

int main2()
{
	int a, b;

	scanf("%d%d", &a, &b);
	printf("a =  %d,b = %d\n", a, b);
	Swap(&a, &b);
	printf("a =  %d,b = %d\n", a, b);

	system("pause");
	return 0;
}