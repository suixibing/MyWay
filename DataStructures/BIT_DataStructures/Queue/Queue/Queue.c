#include"Queue.h"

// 队列初始化
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->_front = (QueueNode*)malloc(sizeof(QueueNode));
	pq->_rear = pq->_front;
	pq->_rear->_next = pq->_front;
}
// 队列销毁
void QueueDestory(Queue* pq)
{
	assert(pq);

	QueueNode *cur;

	while (pq->_front != pq->_rear)
	{
		cur = pq->_front;
		pq->_front = cur->_next;
		free(cur);
	}
	free(pq->_rear);
	pq->_front = NULL;
	pq->_rear = NULL;
}
// 将数据放入队结点并返回(暂时没有使用)
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode *p = (QueueNode*)malloc(sizeof(QueueNode));

	assert(p);

	p->_data = x;
	p->_next = NULL;

	return p;
}
// 尾部入队
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);

	QueueNode *cur = (QueueNode*)malloc(sizeof(QueueNode));

	assert(cur);

	pq->_rear->_data = x;
	cur->_next = pq->_front;
	pq->_rear->_next = cur;
	pq->_rear = cur;
}
// 首元素出队
void QueuePop(Queue* pq)
{
	assert(pq);

	QueueNode *cur;

	if (pq->_front != pq->_rear);
	{
		cur = pq->_front;
		pq->_front = cur->_next;
		pq->_rear->_next = pq->_front;
	}
}
// 返回首元素
QUDataType QueueFront(Queue* pq)
{
	assert(pq);

	return pq->_front->_data;
}
// 返回尾元素(不出队)
QUDataType QueueBack(Queue* pq)
{
	assert(pq);

	QueueNode *t = pq->_front;

	while (t->_next != pq->_rear)
	{
		t = t->_next;
	}

	return t->_data;
}
// 判断是否空队列
int QueueEmpty(Queue* pq)
{
	assert(pq);

	if (pq->_front != pq->_rear)
	{
		return 0;
	}

	return 1;
}
// 返回队列中元素个数
int QueueSize(Queue* pq)
{
	assert(pq);

	int num = 0;
	QueueNode *cur = pq->_front;

	while (cur != pq->_rear)
	{
		num++;
		cur = cur->_next;
	}

	return num;
}
// 打印队列中的元素
void QueuePrint(Queue *pq)
{
	assert(pq);

	if (pq->_front == pq->_rear)
	{
		printf("Empty!");
	}

	QueueNode *cur = pq->_front;

	while (cur != pq->_rear)
	{
		PRINT(cur->_data);
		cur = cur->_next;
	}
	putchar('\n');
}
// 输出队列的状态(所有元素依次输出、首元素、尾元素、队列元素个数、是否空队列)
void QueueState(Queue *pq)
{
	printf("队列中的元素:> ");
	QueuePrint(pq);
	
	printf("QueueSize(pq) = %d\n", QueueSize(pq));
	if (QueueEmpty(pq))
	{
		printf("Empty Queue!\n");
		return;
	}
	printf("QueueFront(pq) = %d\n", QueueFront(pq));
	printf("QueueBack(pq) = %d\n", QueueBack(pq));
}

// 测试函数
void TestQueue()
{
	Queue Q, *pq = &Q;

	QueueInit(pq);

	QueuePush(pq, 18);
	QueuePush(pq, 52);
	QueuePush(pq, 92);
	QueuePush(pq, 124);
	QueuePush(pq, 145);
	QueuePush(pq, 163);

	QueueState(pq);
	while (!QueueEmpty(pq))
	{
		QueuePop(pq);
		QueueState(pq);
	}

	QueueDestory(pq);
}