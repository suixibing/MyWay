#include"DeQueue.h"

void DeQueueInit(DeQueue* pq)
{
	assert(pq);

	pq->_capacity = QUEUENUM;
	pq->data = (DeQUDataType*)malloc(QUEUENUM * sizeof(DeQUDataType) + 1);
	pq->_head = 0;
	pq->_tail = 0;
}
void DeQueueDestory(DeQueue* pq)
{
	assert(pq);

	pq->_capacity = 0;
	pq->_head = 0;
	pq->_tail = 0;
	free(pq->data);
}

void DeQueuePush(DeQueue* pq, DeQUDataType val)
{
	assert(pq);

	int i;
	DeQUDataType *cur;

	if ((pq->_tail + 1) % (pq->_capacity + 1) != pq->_head)
	{
		pq->data[pq->_tail] = val;
		pq->_tail = (pq->_tail + 1) % (pq->_capacity + 1);
	}
	else
	{
		cur = (DeQUDataType*)malloc(2 * pq->_capacity * sizeof(DeQUDataType) + 1);
		for (i = 0; i < pq->_capacity; i++)
		{
			cur[i] = pq->data[(pq->_head + i) % (pq->_capacity + 1)];
		}
		cur[i++] = val;
		//free(pq->data);   // --------------------------------------不知道为什么不能释放！！！！
		pq->data = cur;
		pq->_capacity *= 2;
		pq->_head = 0;
		pq->_tail = i;
	}
}
void DeQueuePop(DeQueue* pq)
{
	assert(pq);

	if (pq->_tail != pq->_head)
	{
		pq->_head = (pq->_head + 1) % (pq->_capacity + 1);
	}
}
DeQUDataType DeQueueFront(DeQueue* pq)
{
	assert(pq);

	return pq->data[pq->_head];
}
DeQUDataType DeQueueBack(DeQueue* pq)
{
	assert(pq);

	return pq->data[(pq->_tail - 1) % (pq->_capacity + 1)];
}
int DeQueueEmpty(DeQueue* pq)
{
	assert(pq);

	if (pq->_head == pq->_tail)
	{
		return 1;
	}

	return 0;
}
int DeQueueSize(DeQueue* pq)
{
	assert(pq);

	int i = 0;

	while ((pq->_head + i) % (pq->_capacity + 1) != pq->_tail)
	{
		i++;
	}

	return i;
}

// 打印队列中的元素
void DeQueuePrint(DeQueue *pq)
{
	assert(pq);

	int i = 0;

	if (pq->_head == pq->_tail)
	{
		printf("Empty!");
	}

	while ((pq->_head + i) % (pq->_capacity + 1) != pq->_tail)
	{
		PRINT(pq->data[(pq->_head + i) % (pq->_capacity + 1)]);
		i++;
	}
	putchar('\n');
}
// 输出队列的状态
void DeQueueState(DeQueue *pq)
{
	printf("队列中的元素:> ");
	DeQueuePrint(pq);

	printf("DeQueueSize(pq) = %d\n", DeQueueSize(pq));
	if (DeQueueEmpty(pq))
	{
		printf("Empty DeQueue!\n");
		return;
	}
	printf("DeQueueFront(pq) = %d\n", DeQueueFront(pq));
	printf("DeQueueBack(pq) = %d\n", DeQueueBack(pq));
}
void TestDeQueue()
{
	DeQueue Q, *pq = &Q;

	DeQueueInit(pq);

	DeQueuePush(pq, 18);
	DeQueuePush(pq, 52);
	DeQueuePush(pq, 92);
	DeQueuePop(pq);
	DeQueuePush(pq, 124);
	DeQueuePush(pq, 145);
	DeQueuePush(pq, -3);
	DeQueuePrint(pq);
	DeQueuePush(pq, -25);
	
	DeQueuePush(pq, 163);

	DeQueueState(pq);
	while (!DeQueueEmpty(pq))
	{
		DeQueuePop(pq);
		DeQueueState(pq);
	}

	DeQueueDestory(pq);
}