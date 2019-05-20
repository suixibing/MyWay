#include"Sort.h"

void BubbleSort(int *base, int num)
{
	int i, j, tmp;

	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (base[j] > base[j + 1])
			{
				tmp = base[j];
				base[j] = base[j + 1];
				base[j + 1] = tmp;
			}
		}
	}
}