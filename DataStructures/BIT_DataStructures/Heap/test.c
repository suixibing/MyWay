#include"Heap.h"

int main()
{
	Heap hp;
	HPDataType a[] = { 29, 72, 48, 53, 45, 30, 18, 36, 15, 35 };
	int size = sizeof(a) / sizeof(a[0]);
	
	HeapInit(&hp, a, size);

	HeapPrint(&hp);
	HeapPush(&hp, 59);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapSort(&hp);
	HeapPrintS(&hp);

	HeapDestory(&hp);

	system("pause");
	return 0;
}