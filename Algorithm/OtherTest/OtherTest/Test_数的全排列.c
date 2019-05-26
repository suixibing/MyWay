#include"Test.h"

void FullPermutation_1()
{
	int i, j, k;

	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			for (k = 1; k <= 3; k++)
			{
				if (i != j && j != k && i != k)
				{
					printf("%d%d%d ", i, j, k);
				}
			}
		}
	}
}

void FullPermutation_DFS(int *base, int step, int *book, int num)
{
	int i;

	if (step == num)
	{
		for (i = 0; i < step; i++)
		{
			printf("%d", base[i]);
		}
		putchar('\n');
		return;
	}
	for (i = 0; i < num; i++)
	{
		if (book[i] == 0)
		{
			book[i] = 1;
			base[step] = i + 1;
			FullPermutation_DFS(base, step + 1, book, num);
			book[i] = 0;
		}
	}
}