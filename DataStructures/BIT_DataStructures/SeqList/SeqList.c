#include"SeqList.h"
//顺序表初始化
void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);

	psl->array = (SLDataType*)calloc(capacity, sizeof(SLDataType));

	assert(psl->array);

	psl->capacity = capacity;
	psl->size = 0;
}
//顺序表销毁
void SeqListDestory(SeqList* psl)
{
	assert(psl);

	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->capacity = 0;
		psl->size = 0;
	}
}
//顺序表已满时，将顺序表扩充为两倍
void CheckCapacity(SeqList* psl)
{
	assert(psl);

	if (psl->capacity == psl->size)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType*)realloc(psl->array, psl->capacity * sizeof(SLDataType));
	}

	assert(psl->array);
}
//从表尾增加数据
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);

	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}
//从表尾删除数据
void SeqListPopBack(SeqList* psl)
{
	assert(psl || psl->size);

	psl->size--;
}
//从表头增加数据
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);

	int i;

	CheckCapacity(psl);

	for (i = psl->size; i > 0; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[i] = x;
	psl->size++;
}
//从表头删除数据
void SeqListPopFront(SeqList* psl)
{
	assert(psl);

	unsigned int i;

	psl->size--;
	for (i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}

}

//在顺序表中查找数据
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	unsigned int i;

	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}

	return -1;
}
//在pos位置插入数据
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos <= psl->size);

	unsigned int i;

	CheckCapacity(psl);

	for (i = psl->size; i > pos; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	psl->size++;
}
//删除pos位置的数据
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl || pos < psl->size);

	unsigned int i;

	psl->size--;
	for (i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}
//删除最先出现的指定数据
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);

	int pos = SeqListFind(psl, x);

	if (pos >= 0)
	{
		SeqListErase(psl, pos);
	}
}
//修改pos位置的数据为指定数据
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos < psl->size);

	psl->array[pos] = x;
}
//打印顺序表
void SeqListPrint(SeqList* psl)
{
	assert(psl);

	unsigned int i;

	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}

// 扩展面试题实现

//冒泡排序
void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);

	size_t i, j;
	SLDataType tmp;

	for (i = 0; i < psl->size - 1; i++)
	{
		for (j = 0; j < psl->size - i - 1; j++)
		{
			if (psl->array[j] > psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}
//二分查找
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int left = 0;
	int right = psl->size - 1;
	int mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (psl->array[mid] == x)
		{
			return mid;
		}
		else if (psl->array[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return -1;
}
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 

//删除重复的指定数据
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	assert(psl);

	size_t i;
	int ret, num = 0;

	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			num++;
		}
	}
	while (num > 1)
	{
		ret = SeqListBinaryFind(psl, x);
		SeqListErase(psl, ret);
		num--;
	}
}