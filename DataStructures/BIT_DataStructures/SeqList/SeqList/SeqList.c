#include"SeqList.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);

	psl->array = (SLDataType*)calloc(capacity, sizeof(SLDataType));
	assert(psl->array);

	psl->capacity = capacity;
	psl->size = 0;
}
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

void CheckCapacity(SeqList* psl)
{
	assert(psl);

	if (psl->capacity == psl->size)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType*)realloc(psl->array, psl->capacity * sizeof(SLDataType));
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);

	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)
{
	assert(psl || psl->size);

	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	int i;

	assert(psl);

	CheckCapacity(psl);

	for (i = psl->size; i > 0; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[i] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)
{
	unsigned int i;

	assert(psl);

	psl->size--;
	for (i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	unsigned int i;

	assert(psl);

	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}

	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	unsigned int i;

	assert(psl || pos <= psl->size);

	CheckCapacity(psl);

	for (i = psl->size; i > pos; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)
{
	unsigned int i;

	assert(psl || pos < psl->size);
	
	psl->size--;
	for (i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}
void SeqListRemove(SeqList* psl, SLDataType x)
{
	int pos = SeqListFind(psl, x);

	assert(psl);

	if (pos >= 0)
	{
		SeqListErase(psl, pos);
	}
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos < psl->size);

	psl->array[pos] = x;
}
void SeqListPrint(SeqList* psl) 
{
	unsigned int i;

	assert(psl);

	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}

// 扩展面试题实现
void SeqListBubbleSort(SeqList* psl)
{

}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	return 0;
}
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{

}