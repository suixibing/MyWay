#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main1()
{
	int i;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int(*p)[10] = &arr;

	for (i = 0; i < 10; i++)
	{
		printf("%d ", (*p)[i]);
	}
	putchar('\n');

	system("pause");
	return 0;
}
