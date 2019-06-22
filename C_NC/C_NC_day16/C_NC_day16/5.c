#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int CompareInt(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main5()
{
	int i, n;
	int arr[] = { 7, 8, 5, 1, 2, 1, 0, 3, 4, 9 };

	n = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, n, sizeof(int), CompareInt);
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');

	system("pause");
	return 0;
}
