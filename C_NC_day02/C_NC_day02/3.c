#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main3()
{
	int i = 0, max = 0;
	int num[10] = { 0 };
	while (i < 10)
	{
		scanf("%d", &num[i]);
		if (i == 0)
		{
			max = num[i];
		}
		else if (num[i] > max)
		{
			max = num[i];
		}
		i++;
	}
	printf("%d\n", max);
	system("pause");
	return 0;
}