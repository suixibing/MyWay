#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"Sort.h"

int main()
{
	int a[] = { 27, 53, 19, 5, 73, 92, 39 };
	int n = sizeof(a) / sizeof(a[0]);

	QuickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	system("pause");
	return 0;
}