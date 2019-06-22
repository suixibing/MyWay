#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define QueueElementType int
#define StackElementType int
#define FALSE 0
#define TRUE 1
#define MAX 100

//循环队列
typedef struct
{
	QueueElementType data[MAX];
	int front;
	int rear;
	int flag;
}SeqQueue;

int SeqQueueInit(SeqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	Q->flag = -1;

	return TRUE;
}

int SeqQueueEnter(SeqQueue *Q, QueueElementType elem)
{
	if (Q->rear == Q->front && Q->flag == 1)
	{
		return FALSE;
	}
	Q->data[Q->rear] = elem;
	Q->rear = (Q->rear + 1) % MAX;
	Q->flag = 1;

	return TRUE;
}

int SeqQueueDelete(SeqQueue *Q, QueueElementType *elem)
{
	if (Q->front == Q->rear && Q->flag == -1)
	{
		return FALSE;
	}
	*elem = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAX;
	Q->flag = -1;

	return TRUE;
}

//链队列
typedef struct QUEUE
{
	QueueElementType data;
	struct QUEUE *next;
}*LinkQueueNode, QueueNode;

typedef struct
{
	QueueNode *front;
	QueueNode *rear;
}LinkQueue;

int LQInit(LinkQueue *Q)
{
	LinkQueueNode pq = (LinkQueueNode)malloc(sizeof(QueueNode));
	if (pq == NULL)
	{
		return FALSE;
	}
	pq->next = NULL;
	Q->front = pq;
	Q->rear = pq;

	return TRUE;
}

int LQEnter(LinkQueue *Q, QueueElementType elem)
{
	QueueNode *p = (QueueNode*)malloc(sizeof(QueueNode));
	if (p == NULL)
	{
		return FALSE;
	}
	p->data = elem;
	p->next = Q->rear->next;
	Q->rear->next = p;
	Q->rear = p;

	return TRUE;
}

int LQDelete(LinkQueue *Q, QueueElementType *elem)
{
	QueueNode *tmp;

	if (Q->rear == Q->front)
	{
		return FALSE;
	}
	tmp = Q->front->next;
	Q->front->next = tmp->next;
	*elem = tmp->data;
	free(tmp);

	return TRUE;
}

//顺序栈
typedef struct SEPSTACK
{
	StackElementType data[MAX];
	int top;
}SeqStack;

int SeqStackInit(SeqStack S)
{
	S.top = -1;
	return TRUE;
}

int SeqStackPush(SeqStack *S, StackElementType elem)
{
	if (S->top + 1 == MAX)
	{
		return FALSE;
	}
	S->top++;
	S->data[S->top] = elem;

	return TRUE;
}

int SeqStackPop(SeqStack *S, StackElementType *elem)
{
	if (S->top == -1)
	{
		return FALSE;
	}
	*elem = S->data[S->top];
	S->top--;

	return TRUE;
}

//链栈
typedef struct STACK
{
	StackElementType data;
	struct STACK *next;
}*LinkStack, Stack;

int LSInit(LinkStack *top)
{
	*top = (LinkStack)malloc(sizeof(Stack));
	if (*top == NULL)
	{
		return FALSE;
	}
	(*top)->next = NULL;

	return TRUE;
}

int LSPush(LinkStack top, StackElementType elem)
{
	Stack *ps;

	ps = (Stack*)malloc(sizeof(Stack));
	if (ps == NULL)
	{
		return FALSE;
	}
	ps->data = elem;
	ps->next = top->next;
	top->next = ps;

	return TRUE;
}

int LSPop(LinkStack top, StackElementType *elem)
{
	Stack *ps;

	if (top->next == NULL)
	{
		return FALSE;
	}
	ps = top->next;
	top->next = ps->next;
	*elem = ps->data;
	free(ps);

	return TRUE;
}

void Menu()
{
	printf("\n\n");
	printf("0、退出\n");
	printf("1、采用链式存储实现栈的初始化、入栈、出栈操作\n");
	printf("2、采用顺序存储实现栈的初始化、入栈、出栈操作\n");
	printf("3、采用链式存储实现队列的初始化、入队、出队操作\n");
	printf("4、采用顺序存储实现队列的初始化、入队、出队操作\n");
	printf("\n\n\n");
}

int main()
{
	int i, n, choice = -1;
	LinkStack LS;
	SeqStack SS = { 0 };
	LinkQueue LQ;
	SeqQueue SQ;
	StackElementType s_elem;
	QueueElementType q_elem;

	LSInit(&LS);
	SeqStackInit(SS);
	LQInit(&LQ);
	SeqQueueInit(&SQ);

	while (choice)
	{
		Menu();
		if (!scanf("%d", &choice))
		{
			choice = -1;
			getchar();
		}
		switch (choice)
		{
		case 1:
			printf("要进(链)栈的元素个数:>");
			scanf("%d", &n);
			printf("进栈:>");
			for (i = 0; i < n; i++)
			{
				scanf("%d", &s_elem);
				LSPush(LS, s_elem);
			}
			printf("\n出栈:>");
			for (i = 0; i < n; i++)
			{
				LSPop(LS, &s_elem);
				printf("%d ", s_elem);
			}
			break;
		case 2:
			printf("要进(顺序)栈的元素个数:>");
			scanf("%d", &n);
			printf("进栈:>");
			for (i = 0; i < n; i++)
			{
				scanf("%d", &s_elem);
				SeqStackPush(&SS, s_elem);
			}
			printf("\n出栈:>");
			for (i = 0; i < n; i++)
			{
				SeqStackPop(&SS, &s_elem);
				printf("%d ", s_elem);
			}
			break;
		case 3:
			printf("要进(链)队列的元素个数:>");
			scanf("%d", &n);
			printf("进队列:>");
			for (i = 0; i < n; i++)
			{
				scanf("%d", &q_elem);
				LQEnter(&LQ, q_elem);
			}
			printf("\n出队列:>");
			for (i = 0; i < n; i++)
			{
				LQDelete(&LQ, &q_elem);
				printf("%d ", q_elem);
			}
			break;
		case 4:
			printf("要进(顺序)队列的元素个数:>");
			scanf("%d", &n);
			printf("进队列:>");
			for (i = 0; i < n; i++)
			{
				scanf("%d", &q_elem);
				SeqQueueEnter(&SQ, q_elem);
			}
			printf("\n出队列:>");
			for (i = 0; i < n; i++)
			{
				SeqQueueDelete(&SQ, &q_elem);
				printf("%d ", q_elem);
			}
			break;
		default:
			break;
		}
		putchar('\n');
	}
	
	system("pause");
	return 0;
}
