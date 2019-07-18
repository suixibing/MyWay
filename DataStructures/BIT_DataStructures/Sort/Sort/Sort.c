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
// 建立大堆
void HeapCreate(SORTDATA arr[], int size)
{
	int i, num;
	SORTDATA tmp;

	for (num = size; num > 0; num--)
	{
		i = num;
		while (i > 0)
		{
			if (arr[i] > arr[i / 2])
			{
				tmp = arr[i];
				arr[i] = arr[i / 2];
				arr[i / 2] = tmp;
			}
			i /= 2;
		}
	}
}
// 堆排序
void HeapSort(SORTDATA arr[], int size)
{
	int num = size;
	SORTDATA tmp;

	while (num--)
	{
		HeapCreate(arr, num);
		tmp = arr[num];
		arr[num] = arr[0];
		arr[0] = tmp;
	}
}
// 冒泡排序
void BubbleSort(SORTDATA arr[], int size)
{
	int i, j;
	SORTDATA tmp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
// 归并子函数
void Merge(SORTDATA arr[], int left, int mid, int right)
{
	int i = 0, l = left, m = mid + 1, size = right - left + 1;
	SORTDATA *cur = (SORTDATA*)malloc(size * sizeof(SORTDATA));

	while (i < size)
	{
		if (l <= mid && arr[l] < arr[m])
		{
			cur[i] = arr[l++];
		}
		else if (m <= right)
		{
			cur[i] = arr[m++];
		}
		i++;
	}
	for (i = 0; i < size; i++)
	{
		printf("%2d ", cur[i]);
		arr[left + i] = cur[i];
	}
	putchar('\n');
}
// 归并排序
void MergeSort(SORTDATA arr[], int left, int right)
{
	int mid = left + (right - left) / 2;

	if (left >= right)
	{
		return;
	}
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	Merge(arr, left, mid, right);
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