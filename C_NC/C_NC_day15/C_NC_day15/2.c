#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main2()
{
	int i, n, empty, count;

	scanf("%d", &n);
	for (i = 0, empty = 0, count = 0; n != 0 || empty != 1; i++)
	{
		count += n;
		empty += n;
		n = empty / 2;
		empty %= 2;
		//printf("count = %d, empty = %d, n = %d\n", count, empty, n);
	}
	printf("%d\n", count);

	system("pause");
	return 0;
}
