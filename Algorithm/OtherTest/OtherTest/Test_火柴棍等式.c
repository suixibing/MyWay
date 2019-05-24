#include"Test.h"

int StickCount(int num)
{
	int sum = 0;
	int n[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

	while (num / 10 != 0)
	{
		sum += n[num % 10];
		num /= 10;
	}
	sum += n[num];

	return sum;
}

void StickEquation()
{
	int i, j, num;

	scanf("%d", &num);
	for (i = 0; StickCount(i) < num; i++)
	{
		for (j = 0; StickCount(j) < num; j++)
		{
			if (StickCount(i) + StickCount(j) + StickCount(i + j) == num - 4)
			{
				printf("%d+%d=%d\n", i, j, i + j);
			}
		}
	}
}