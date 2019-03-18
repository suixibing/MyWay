#include<stdio.h>
#include<stdlib.h>
//输出乘法口诀表
int main2()
{
	int i, j;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < i + 1; j++)
		{
			printf("%d * %d = %2d ", j, i, i*j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}