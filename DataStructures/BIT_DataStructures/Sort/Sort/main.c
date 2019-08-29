#include"Sort.h"

void CreateArr(SORTDATA arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (SIZE * size) + 1;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	SORTDATA a[SIZE];
	int size = SIZE;
	clock_t c, c2;
	
	for (int i = 0; i < 10; i++)
	{
		//Print(a, size);
		CreateArr(a, size);
		c = clock();
		HeapSort(a, size);
		c2 = clock();
		printf("HeapSort(a, size) time : %d\n", c2 - c);
		Judge(a, size);
	}
	for (int i = 0; i < 10; i++)
	{
		CreateArr(a, size);
		c = clock();
		SeclectionSort(a, size);
		c2 = clock();
		printf("SeclectionSort(a, size) time : %d\n", c2 - c);
		Judge(a, size);
	}
	for (int i = 0; i < 10; i++)
	{
		CreateArr(a, size);
		c = clock();
		ShellSort(a, size);
		c2 = clock();
		printf("ShellSort(a, size) time : %d\n", c2 - c);
		Judge(a, size);
	}
	for (int i = 0; i < 10; i++)
	{
		CreateArr(a, size);
		c = clock();
		InsertSort(a, size);
		c2 = clock();
		printf("InsertSort(a, size) time : %d\n", c2 - c);
		Judge(a, size);
	}
	for (int i = 0; i < 10; i++)
	{
		CreateArr(a, size);
		c = clock();
		BubbleSort(a, size);
		c2 = clock();
		printf("BubbleSort(a, size) time : %d\n", c2 - c);
		Judge(a, size);
	}
	for (int i = 0; i < 10; i++)
	{
		CreateArr(a, size);
		c = clock();
		QuickSort(a, 0, size - 1);
		c2 = clock();
		printf("QuickSort(a, 0, size - 1) time : %d\n", c2 - c);
		Judge(a, size);
	}
	for (int i = 0; i < 10; i++)
	{
		CreateArr(a, size);
		c = clock();
		MergeSort(a, size);
		c2 = clock();
		printf("MergeSort(a, size) time : %d\n", c2 - c);
		Judge(a, size);
	}
	for (int i = 0; i < 10; i++)
	{
		CreateArr(a, size);
		c = clock();
		BucketSort(a, size);
		c2 = clock();
		printf("BucketSort(a, size) time : %d\n", c2 - c);
		Judge(a, size);
		//Print(a, size);
	}

	system("pause");
	return 0;
}