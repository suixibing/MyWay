#include"Sort.h"

void Merge(int *base, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *arr1 = (int*)malloc(n1 * sizeof(int));
	int *arr2 = (int*)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
	{
		arr1[i] = base[left + i];
	}
	for (j = 0; j < n2; j++)
	{
		arr2[j] = base[mid + j + 1];
	}
	for (i = 0, j  = 0, k = left; i < n1 && j < n2; k++)
	{
		if (arr1[i] < arr2[j])
		{
			base[k] = arr1[i++];
		}
		else
		{
			base[k] = arr2[j++];
		}
	}
	while (i < n1)
	{
		base[k++] = arr1[i++];
	}
	while (j < n2)
	{
		base[k++] = arr2[j++];
	}
}

void MergeSort(int *base, int left, int right)
{
	int mid;

	if (left >= right)
	{
		return;
	}
	/*for (int i = 0; i < 7; i++)
	{
		printf("%d ", base[i]);
	}
	putchar('\n');*/
	mid = left + (right - left) / 2;
	MergeSort(base, left, mid);
	MergeSort(base, mid + 1, right);
	Merge(base, left, mid, right);
}