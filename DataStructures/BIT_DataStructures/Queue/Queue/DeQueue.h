#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _DEQUEUE_H_
#define _DEQUEUE_H

typedef int DeQUDataType;
#define QUEUENUM 5

typedef struct DeQueue
{
	DeQUDataType data[QUEUENUM];
	DeQUDataType* _head; // ∂”Õ∑    
	DeQUDataType* _tail;  // ∂”Œ≤
}DeQueue;

void DeQueueInit(DeQueue* pq);

void DeQueuePush(DeQueue* pq, DeQUDataType x);
void DeQueuePop(DeQueue* pq);
DeQUDataType DeQueueFront(DeQueue* pq);
DeQUDataType DeQueueBack(DeQueue* pq);
int DeQueueEmpty(DeQueue* pq);
int DeQueueSize(DeQueue* pq);

void TestDeQueue();

#endif //_DEQUEUE_H_