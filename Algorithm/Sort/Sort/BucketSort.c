#include"Sort.h"

void BucketSort(int *base, int num)
{
	int i, j, max = base[0];
	int *p = NULL;

	for (i = 1; i < num; i++)
	{
		if(base[i] > max)
		{
			max = base[i];
		}
	}
	p = (int*)calloc(max + 1, sizeof(int));
	if (p != NULL)
	{
		for (i = 0; i < num; i++)
		{
			p[base[i]]++;
		}
		for (i = 0, j = 0; j < num - 1; )
		{
			if (p[i] != 0)
			{
				base[j++] = i;
				--p[i];
			}
			else
			{
				i++;
			}
		}
		base[j] = max;
		free(p);
	}
}
