#include"Sort.h"

void DataExchange(SORTDATA* a, SORTDATA* b)
{
	SORTDATA t;

	t = *a;
	*a = *b;
	*b = t;
}

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
// 数组越有序直接插入排序越快
void ShellSort(SORTDATA arr[], int size)
{
	int gap = size / 3;
	int start, now;
	SORTDATA key;

	while (gap > 0)
	{
		//printf("gap = %d\n", gap);
		for (start = gap; start < size; start++)
		{
			key = arr[start];
			for (now = start - gap;  now >= 0 && arr[now] >= key; now -= gap)
			{
				arr[now + gap] = arr[now];
			}
			arr[now + gap] = key;
		}
		gap /= 3;
	}
}

// 选择排序
void SeclectionSort(SORTDATA arr[], int size)
{
	int i, now, min;

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
		DataExchange(&arr[min], &arr[now]);
	}
}

// 建立大堆
void HeapCreate(SORTDATA arr[], int size)
{
	int num = size, tmp;
	
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		if (2 * i + 2 >= size)
		{
			tmp = 2 * i + 1;
		}
		else
		{
			tmp = arr[2 * i + 1] > arr[2 * i + 2] ? 2 * i + 1 : 2 * i + 2;
		}
		if (arr[tmp] > arr[i])
		{
			DataExchange(&arr[tmp], &arr[i]);
		}
	}
}
// 堆排序
void HeapSort(SORTDATA arr[], int size)
{
	int num = size;

	while (num)
	{
		HeapCreate(arr, num--);
		DataExchange(&arr[0], &arr[num]);
	}
}

// 冒泡排序
void BubbleSort(SORTDATA arr[], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				DataExchange(&arr[j], &arr[j + 1]);
			}
		}
	}
}

// 快速排序
void QuickSort(SORTDATA arr[], int left, int right)
{
	int i = left, j = right;
	SORTDATA key = arr[left];

	if (left >= right)
	{
		return;
	}
	while (i < j)
	{
		while (i < j && key <= arr[j])
		{
			j--;
		}
		while (i < j && key >= arr[i])
		{
			i++;
		}
		if (i < j)
		{
			DataExchange(&arr[i], &arr[j]);
		}
	}
	arr[left] = arr[i];
	arr[i] = key;
	QuickSort(arr, left, i - 1);
	QuickSort(arr, i + 1, right);
}

// 归并子函数
void Merge(SORTDATA arr[], int left, int mid, int right)
{
	int i = 0, l = left, m = mid, size = right - left + 1;
	SORTDATA *cur = (SORTDATA*)malloc(size * sizeof(SORTDATA));

	while (i < size)
	{
		if (l < mid && arr[l] < arr[m] || m > right)
		{
			cur[i] = arr[l];
			l++;
		}
		else
		{
			cur[i] = arr[m];
			m++;
		}
		i++;
	}
	for (i = 0; i < size; i++)
	{
		arr[left + i] = cur[i];
	}
}
// 归并排序实现
void DealMergeSort(SORTDATA arr[], int left, int right)
{
	int mid = left + (right - left) / 2;

	if (left < right)
	{
		DealMergeSort(arr, left, mid);
		DealMergeSort(arr, mid + 1, right);
		Merge(arr, left, mid + 1, right);
	}
}
// 归并函数接口
void MergeSort(SORTDATA arr[], int size)
{
	DealMergeSort(arr, 0, size - 1);
}

// 桶排序
void BucketSort(SORTDATA arr[], int size)
{
	int i, j, num;
	int min = arr[0], max = arr[0];
	SORTDATA *book;

	for (i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		else if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	num = max - min + 1;
	book = (SORTDATA*)calloc(num, sizeof(SORTDATA));
	for (i = 0; i < size; i++)
	{
		book[arr[i] - min]++;
	}
	for (i = 0, j = 0; i < size; )
	{
		if (book[j]-- > 0)
		{
			arr[i++] = min + j;
		}
		else
		{
			j++;
		}
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


int Judge(SORTDATA arr[], int size)
{
	int i;

	for (i = 1; i < size; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			printf("ERROR!\n");
			return 0;
		}
	}

	return 1;
}