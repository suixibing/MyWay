#include<stdio.h>
#include<stdlib.h>
#define N 5

void PrintArr(int a[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("a[%d] = %d ", i, a[i]);
	}
	printf("\n");
}

int main()
{
	int i, tmp;
	int a[N] = { 1, 2, 3, 4, 5 };
	int b[N] = { 6, 7, 8, 9, 10 };

	printf("交换前：\n");
	PrintArr(a, N);
	PrintArr(b, N);

	for( i = 0; i < N ; i++ )
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
	
	printf("交换后：\n");
	PrintArr(a, N);
	PrintArr(b, N);

	system("pause");
	return 0;
}
