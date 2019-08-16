#include"Heap.h"

// 堆的向下调整
void AdjustDown(Heap* hp, int n)
{
	int cur = n;
	int tmp, max;
	
	while (cur * 2 + 1 < hp->size)
	{
		if (cur * 2 + 2 >= hp->size) // 找到最大的孩子结点
		{
			max = cur * 2 + 1;
		}
		else
		{
			max = hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2] ? cur * 2 + 1 : cur * 2 + 2;
		}
		if (hp->data[cur] < hp->data[max]) // 判断是否需要下移
		{
			tmp = hp->data[cur];
			hp->data[cur] = hp->data[max];
			hp->data[max] = tmp;

			cur = max;
		}
		else
		{
			break;
		}
	}
}
// 堆的向上调整
void AdjustUp(Heap* hp, int n)
{
	int cur = n;

	while (hp->data[cur] > hp->data[(cur - 1) / 2]) // 判断是否需要上移
	{
		int tmp = hp->data[cur];
		hp->data[cur] = hp->data[(cur - 1) / 2];
		hp->data[(cur - 1) / 2] = tmp;

		cur = (cur - 1) / 2;
	}
}
// （最大）堆的建立
void HeapInit(Heap* hp, HPDataType* arr, int size)
{
	hp->size = size;
	hp->capacity = 2 * size;
	hp->data = (HPDataType*)calloc(hp->capacity, sizeof(HPDataType));

	for (int i = 0; i < size; i++) // 复制数组到堆中
	{
		hp->data[i] = arr[i];
	}
	for (int i = size / 2 - 1; i >= 0; i--) // 通过下移建立（最大）堆
	{
		AdjustDown(hp, i);
	}
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	if(hp->data)
	{
		free(hp->data);
	}
	hp->data = NULL;
	hp->capacity = 0;
	hp->size = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->capacity == hp->size)
	{
		hp->capacity *= 2;
		hp->data = (HPDataType*)realloc(hp->data, hp->capacity * sizeof(HPDataType));
	}

	int cur = hp->size;
	hp->data[hp->size++] = x;
	
	AdjustUp(hp, cur);
}
// 堆的删除
void HeapPop(Heap* hp)
{
	if (hp->size == 0)
	{
		return;
	}
	hp->size--;

	int tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size];
	hp->data[hp->size] = tmp;

	AdjustDown(hp, 0);
}
// 获取堆顶元素
HPDataType HeapTop(Heap* hp)
{
	if (hp->size == 0)
	{
		return (HPDataType)0;
	}
	return hp->data[0];
}
// 获取堆的大小
int HeapSize(Heap* hp)
{
	return hp->size;
}
// 判断是否为空堆
int HeapEmpty(Heap* hp)
{
	return hp->size == 0;
}

// 堆排序 
void HeapSort(Heap* hp)
{
	int tmp = hp->size;

	while (hp->size > 1)
	{
		HeapPop(hp);
	}
	hp->size = tmp;
}
// 堆打印，类似树的打印堆
void HeapPrint(Heap* hp)
{
	int i,rn = 0, bin = 2;

	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
		if (i == rn)
		{
			putchar('\n');
			rn += bin;
			bin *= 2;
		}
	}
	putchar('\n');
}
// 正常打印，用于查看排序是否完成
void HeapPrintS(Heap* hp)
{
	int i;

	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
	}
	putchar('\n');
}