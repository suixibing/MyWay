#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main2()
{
	int a, b;
	scanf("%d%d", &a, &b);
	/*a = a ^ b;
	b = a ^ b;
	a = a ^ b;*/
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}
