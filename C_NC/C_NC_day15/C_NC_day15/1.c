#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main1()
{
	int i, num = 0, arr[9] = { 1, 2, 3, 4, 8, 4, 3, 2, 1 };

	for (i = 0; i < 9; i++)
	{
		num ^= arr[i];
	}
	printf("%d\n", num);

	system("pause");
	return 0;
}
