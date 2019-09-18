#include<stdio.h>
#include<stdlib.h>

#ifndef _HEAP_H_

#define _HEAP_H_

typedef int HPDataType;

typedef struct Heap
{
	HPDataType *data;
	int capacity;
	int size;
}Heap;

void HeapInit(Heap* hp, HPDataType* arr, int size); // （最大）堆的建立
void HeapDestory(Heap* hp); // 堆的销毁
void HeapPush(Heap* hp, HPDataType x); // 堆的插入
void HeapPop(Heap* hp); // 堆的删除
HPDataType HeapTop(Heap* hp); // 获取堆顶元素
int HeapSize(Heap* hp);  // 获取堆的大小
int HeapEmpty(Heap* hp); // 判断是否为空堆
void HeapSort(Heap* hp); // 堆排序
void AdjustDown(Heap* hp, int n); // 堆的向下调整
void AdjustUp(Heap* hp, int n); // 堆的向上调整
void HeapPrint(Heap* hp); // 堆打印，类似树的打印堆
void HeapPrintS(Heap* hp); // 正常打印，用于查看排序是否完成

#endif // _HEAP_H_
