#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _DEQUEUE_H_
#define _DEQUEUE_H

typedef int DeQUDataType;

typedef struct DeQueueNode
{
	struct DeQueueNode* _next;
	DeQUDataType _data;
}DeQueueNode;

typedef struct DeQueue
{
	DeQueueNode* _front; // ∂”Õ∑    
	DeQueueNode* _rear;  // ∂”Œ≤
}DeQueue;

void DeQueueInit(DeQueue* pq);
void DeQueueDestory(DeQueue* pq);

DeQueueNode* BuyDeQueueNode(DeQUDataType x);
void DeQueuePush(DeQueue* pq, DeQUDataType x);
void DeQueuePop(DeQueue* pq);
DeQUDataType DeQueueFront(DeQueue* pq);
DeQUDataType DeQueueBack(DeQueue* pq);
int DeQueueEmpty(DeQueue* pq);
int DeQueueSize(DeQueue* pq);

void TestDeQueue();

#endif //_DEQUEUE_H_