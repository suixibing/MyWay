#include"Sort.h"

// 直接插入排序
void InsertSort(SORTDATA arr[], int size)
{
	int left, right;
	SORTDATA key;

	for (right = 1; right < size; right++)
	{
		key = arr[right];
		for (left = right - 1; left >= 0 && arr[left] > key; left--)
		{
			arr[left + 1] = arr[left];
		}
		arr[left + 1] = key;
	}
}

// 希尔排序(缩小增量排序)
void ShellSort(SORTDATA arr[], int size)
{
	int gap = size / 2;
	int start, now;
	SORTDATA key;

	while (gap > 0)
	{
		printf("gap = %d\n", gap);
		for (start = 0; start + gap < size; start++)
		{
			now = start;
			key = arr[now + gap];
			while (now >= 0 && arr[now] > key)
			{
				arr[now + gap] = arr[now];
				now -= gap;
			}
			arr[now + gap] = key;
		}
		gap /= 2;
	}
}
// 选择排序
void SeclectionSort(SORTDATA arr[], int size)
{
	int i, now, min;
	SORTDATA tmp;

	for (now = 0; now < size; now++)
	{
		min = now;
		for (i = now + 1; i < size; i++)
		{
			if (arr[min] > arr[i])
			{
				min = i;
			}
		}
		tmp = arr[min];
		arr[min] = arr[now];
		arr[now] = tmp;
	}
}

// 打印数据
void Print(SORTDATA arr[], int size)
{
	int i = 0;

	while (i < size)
	{
		DATAPRINT(arr[i]);
		i++;
	}
	putchar('\n');
}