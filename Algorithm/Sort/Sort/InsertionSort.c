#include"Sort.h"

void InsertionSort(int *base, int num)
{
	int i, j, key;

	for (i = 1; i < num; i++)
	{
		key = base[i];
		for (j = i - 1; j >= 0 && base[j] > key; j--)
		{
			base[j + 1] = base[j];
		}
		base[j + 1] = key;
	}
}