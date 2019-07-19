#include"Sort.h"

int main()
{
	SORTDATA a[] = { 13, 32, 34, 42, 23, 42, 63, 60, 98, 9, 67, 89, 78, 72, 2, 57, 77 };
	int size = sizeof(a) / sizeof(a[0]);

	Print(a, size);
	//InsertSort(a, size);
	//ShellSort(a, size);
	//SeclectionSort(a, size);
	//HeapSort(a, size);
	//BubbleSort(a, size);
	QuickSort(a, 0, size - 1);
	//MergeSort(a, 0, size - 1);
	//BucketSort(a, size);
	Print(a, size);

	system("pause");
	return 0;
}