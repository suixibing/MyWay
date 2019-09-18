#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _DEQUEUE_H_
#define _DEQUEUE_H

typedef int DeQUDataType;
#define QUEUENUM 5
#define PRINT(data) printf("%d 、 ", (data))

typedef struct DeQueue
{
	DeQUDataType *data;
	int _head, _tail;
	int _capacity;
}DeQueue;

void DeQueueInit(DeQueue* pq); // 队列初始化
void DeQueueDestory(DeQueue* pq); // 队列销毁

void DeQueuePush(DeQueue* pq, DeQUDataType x); // 尾部入队
void DeQueuePop(DeQueue* pq); // 首元素出队
DeQUDataType DeQueueFront(DeQueue* pq); // 返回首元素
DeQUDataType DeQueueBack(DeQueue* pq); // 返回尾元素(不出队)
int DeQueueEmpty(DeQueue* pq); // 判断是否空队列
int DeQueueSize(DeQueue* pq); // 返回队列中元素个数

void DeQueuePrint(DeQueue *pq); // 打印队列中的元素
void DeQueueState(DeQueue *pq); // 输出队列的状态
void TestDeQueue();

#endif //_DEQUEUE_H_
