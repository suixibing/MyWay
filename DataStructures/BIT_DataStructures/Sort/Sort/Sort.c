#include"Sort.h"

void DataExchange(SORTDATA* a, SORTDATA* b)
{
	SORTDATA t;

	t = *a;
	*a = *b;
	*b = t;
}

// ÷±Ω”≤Â»Î≈≈–Ú
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

// œ£∂˚≈≈–Ú(Àı–°‘ˆ¡ø≈≈–Ú)
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

// —°‘Ò≈≈–Ú
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

// Ω®¡¢¥Û∂—
void HeapCreate(SORTDATA arr[], int size)
{
	int i, num;

	for (num = size; num > 0; num--)
	{
		i = num;
		while (i > 0)
		{
			if (arr[i] > arr[i / 2])
			{
				DataExchange(&arr[i], &arr[i / 2]);
			}
			i /= 2;
		}
	}
}
// ∂—≈≈–Ú
void HeapSort(SORTDATA arr[], int size)
{
	int num = size;

	while (num--)
	{
		HeapCreate(arr, num);
		DataExchange(&arr[0], &arr[num]);
	}
}

// √∞≈›≈≈–Ú
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

// øÏÀŸ≈≈–Ú
void QuickSort(SORTDATA arr[], int left, int right)
{
	int i = left + 1, j = right;
	SORTDATA key = arr[left];

	if (i > j)
	{
		return;
	}
	while (i < j)
	{
		while (i < j && key < arr[j])
		{
			j--;
		}
		while (i < j && key > arr[i])
		{
			i++;
		}
		if (i < j)
		{
			DataExchange(&arr[i], &arr[j]);
		}
	}
	if (arr[left] > arr[i])
	{
		arr[left] = arr[i];
		arr[i] = key;
	}
	QuickSort(arr, left, i - 1);
	QuickSort(arr, i, right);
}

// πÈ≤¢◊”∫Ø ˝
void Merge(SORTDATA arr[], int left, int mid, int right)
{
	int i = 0, l = left, m = mid, size = right - left + 1;
	SORTDATA *cur = (SORTDATA*)malloc(size * sizeof(SORTDATA));

	while (i < size)
	{
		if (l < mid && arr[l] < arr[m] || m > right)
		{
			cur[i] = arr[l++];
		}
		else if (m <= right)
		{
			cur[i] = arr[m++];
		}
		i++;
	}
}
// πÈ≤¢≈≈–Ú
void MergeSort(SORTDATA arr[], int left, int right)
{
	int mid = left + (right - left) / 2;

	if (left < right)
	{
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid + 1, right);
	}
}

// Õ∞≈≈–Ú
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

// ¥Ú”° ˝æ›
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