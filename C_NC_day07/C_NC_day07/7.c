#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d", n % 10);
}

int main()
{
	int input;

	scanf("%d", &input);
	Print(input);
	putchar('\n');

	system("pause");
	return 0;
}
