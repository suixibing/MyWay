#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _QUEUE_H_
#define _QUEUE_H

typedef int QUDataType;

typedef struct QueueNode 
{ 
	struct QueueNode* _next;
	QUDataType _data; 
}QueueNode; //队结点

typedef struct Queue 
{
	QueueNode* _front; // 队头(指向队首)
	QueueNode* _rear;  // 队尾(指向下一次入队的结点，队尾是上一个元素)
}Queue;

void QueueInit(Queue* pq); //队列初始化
void QueueDestory(Queue* pq); //队列销毁

QueueNode* BuyQueueNode(QUDataType x); //将数据放入队结点并返回(暂时没有使用)
void QueuePush(Queue* pq, QUDataType x); //尾部入队
void QueuePop(Queue* pq); //首元素出队
QUDataType QueueFront(Queue* pq); //返回首元素
QUDataType QueueBack(Queue* pq); //返回尾元素(不出队)
int QueueEmpty(Queue* pq); //判断是否空队列
int QueueSize(Queue* pq); //返回队列中元素个数

void QueuePrint(Queue *pq); //打印队列中的元素
void QueueState(Queue *pq); //输出队列的状态
void TestQueue(); //测试函数

#endif //_QUEUE_H_