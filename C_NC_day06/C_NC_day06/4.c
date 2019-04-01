#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void Print(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%2d ", arr[i]);
	}
	putchar('\n');
}

void Init(int arr[], int size)
{
	int i;
	printf("初始化:>\n");
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void Empty(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

void Reverse(int arr[], int size)
{
	int i, tmp;
	for (i = 0; i < size / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = tmp;
	}
}

int main4()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("起始:>\n");
	Print(arr, size);
	Init(arr, size);
	printf("初始化后:>\n");
	Print(arr, size);
	Reverse(arr, size);
	printf("倒置后:>\n");
	Print(arr, size);
	Empty(arr, size);
	printf("清空后:>\n");
	Print(arr, size);

	system("pause");
	return 0;
}