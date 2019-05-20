#include"Sort.h"

void QuickSort(int *base, int left, int right)
{
	int tmp;
	int i = left + 1;
	int j = right;
	int key = base[left];

	if (i > j)
	{
		return;
	}
	while (i < j)
	{
		while (base[j] > key && i < j)
		{
			j--;
		}
		while (base[i] < key && i < j)
		{
			i++;
		}
		if (i < j)
		{
			tmp = base[i];
			base[i] = base[j];
			base[j] = tmp;
		}
	}
	base[left] = base[i];
	base[i] = key;
	QuickSort(base, left,i - 1);
	QuickSort(base, i + 1, right);
}