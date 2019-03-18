#include<stdio.h>
#include<stdlib.h>
#define N 3

int main4()
{
	int i, j, tmp;
	int num[N] = { 87, 65, 75 };
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (num[i] < num[j])
			{
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		printf("%d ", num[i]);
	}
	system("pause");
	return 0;
}