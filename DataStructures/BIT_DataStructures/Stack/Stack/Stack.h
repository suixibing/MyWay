#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

#ifndef _STACK_H_
#define _STACK_H_

#define N 10

#define INT 1
#define CHAR 2
#define STACKDATATYPE CHAR

#if STACKDATATYPE == INT

typedef int STDataType; 
#define PRINT(data) printf("%2d || ", (data))
#define PLUS 0

#elif STACKDATATYPE == CHAR

typedef char STDataType;
#define PRINTSTACK(data) printf("|| %c ", (data))
#define PRINTQUEUE(data) printf("%c || ", (data))
#define PLUS '0'

#endif

typedef struct Stack 
{
	STDataType* _data;    
	int _top;       // 栈顶    
	int _capacity;  // 容量 
}Stack;

typedef struct QueueByStack
{
	Stack *queue;
	Stack *tmp;
}QueueByStack;

void StackInit(Stack* ps); // 栈初始化
void StackDestory(Stack* ps); // 栈销毁

void StackPush(Stack* ps, STDataType val); // 数据入栈
STDataType StackPop(Stack* ps); // 数据出栈
STDataType StackTop(Stack* ps); // 得到栈顶数据(不出栈)
int StackEmpty(Stack* ps); // 判断栈是否为空栈
int StackSize(Stack* ps); // 当栈已满时，扩充容量为二倍。返回栈内元素的个数。
void StackPrint(Stack* ps); // 打印当前栈内元素

int IsValid(char *str); // 判断括号是否匹配

void TestStack(); // 测试以上所有关于栈的函数


// 栈实现的队列


void QueueInit(QueueByStack* ps); // 队列初始化
void QueueDestory(QueueByStack* ps); // 队列销毁
void QueuePush(QueueByStack* pq, STDataType val); // 数据入队
STDataType QueuePop(QueueByStack* pq); // 数据出队
STDataType QueueTop(QueueByStack* pq); // 得到队首数据(不出队)
int QueueEmpty(QueueByStack* pq); // 判断队列是否为空队
void QueuePrint(QueueByStack* pq); // 打印当前队列内元素

void TestQueueByStack(); // 测试以上所有关于由栈实现的队列的函数

#endif // _STACK_H_