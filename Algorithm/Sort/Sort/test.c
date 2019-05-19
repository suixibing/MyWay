#include<stdio.h>
#include<stdlib.h>
#include"Sort.h"

int main()
{
	int a[] = { 234,324,435,562,34,5,253,56,2,4,6,67,23,3,45,343,734,70 };
	int n = sizeof(a) / sizeof(a[0]);

	BucketSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	system("pause");
	return 0;
}