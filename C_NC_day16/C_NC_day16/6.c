#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

extern int CompareInt(const void* a, const void* b);

void MySort(void *base, int num, int size, int(*Compare)(const void* a, const void* b))
{
	int i, j, k;
	char tmp;

	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (Compare((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
			{
				for (k = 0; k < size; k++)
				{
					tmp = *((char*)base + j * size + k);
					*((char*)base + j * size + k) = *((char*)base + (j + 1) * size + k);
					*((char*)base + (j + 1) * size + k) = tmp;
				}
			}
		}
	}
}

int main()
{
	int i, n;
	int arr[] = { 23, 43, 65, 2, 54, 52, 22, 66 };

	n = sizeof(arr) / sizeof(arr[0]);
	MySort(arr, n, sizeof(int), CompareInt);
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');

	system("pause");
	return 0;
}