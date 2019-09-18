#include"Stack.h"
// 栈初始化
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_data = (STDataType*)malloc(N * sizeof(STDataType));
	ps->_capacity = N;
	ps->_top = 0;
}
// 栈销毁
void StackDestory(Stack* ps)
{
	assert(ps);

	ps->_top = 0;
	ps->_capacity = 0;
	free(ps->_data);
}
// 数据入栈
void StackPush(Stack* ps, STDataType val)
{
	assert(ps);

	StackSize(ps);

	ps->_data[ps->_top++] = val;
}
// 数据出栈
STDataType StackPop(Stack* ps)
{
	assert(ps);

	return ps->_data[--ps->_top];
}
// 得到栈顶数据(不出栈)
STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->_data[ps->_top - 1];
}
// 判断栈是否为空栈
int StackEmpty(Stack* ps)
{
	assert(ps);

	return !ps->_top;
}
// 当栈已满时，扩充容量为二倍。返回栈内元素的个数。
int StackSize(Stack* ps)
{
	assert(ps);

	if (ps->_top == ps->_capacity)
	{
		ps->_data = (STDataType*)realloc(ps->_data, ps->_capacity * 2 * sizeof(STDataType));
		ps->_capacity *= 2;
	}

	return ps->_top;
}
// 打印当前栈内元素
void StackPrint(Stack* ps)
{
	assert(ps);

	int i;

	for (i = 0; i < ps->_top; i++)
	{
		PRINTSTACK(ps->_data[i]);
	}
	putchar('\n');
}

// 判断括号是否匹配
int IsValid(char *str)
{
	int ret = 1;
	Stack S, *ps = &S;
	STDataType val = (STDataType)0;

	StackInit(ps);
	while (*str != '\0')
	{
		val = StackTop(ps);
		switch (*str)
		{
		case '[':
		case '{':
		case '(':
			StackPush(ps, *str);
			break;
		case ']':
			if (val == '[')
			{
				StackPop(ps);
			}
			else
			{
				ret = 0;
			}
			break;
		case '}':
			if (val == '{')
			{
				StackPop(ps);
			}
			else
			{
				ret = 0;
			}
			break;
		case ')':
			if (val == '(')
			{
				StackPop(ps);
			}
			else
			{
				ret = 0;
			}
			break;
		default:
			break;
		}
		str++;
		//StackPrint(ps);
	}
	if (!StackEmpty(ps))
	{
		ret = 0;
	}
	StackDestory(ps);

	return ret;
}

// 队列初始化
void QueueInit(QueueByStack* pq)
{
	assert(pq);

	pq->queue = (Stack*)malloc(sizeof(Stack));
	pq->tmp = (Stack*)malloc(sizeof(Stack));
	StackInit(pq->queue);
}
// 队列销毁
void QueueDestory(QueueByStack* pq)
{
	assert(pq);

	StackDestory(pq->queue);
}
// 数据入队
void QueuePush(QueueByStack* pq, STDataType val)
{
	assert(pq);

	STDataType x;

	StackSize(pq->queue);
	StackInit(pq->tmp);

	while (!StackEmpty(pq->queue))
	{
		x = StackPop(pq->queue);
		StackPush(pq->tmp, x);
	}
	StackPush(pq->queue, val);
	while (!StackEmpty(pq->tmp))
	{
		x = StackPop(pq->tmp);
		StackPush(pq->queue, x);
	}

	StackDestory(pq->tmp);
}
// 数据出队
STDataType QueuePop(QueueByStack* pq)
{
	assert(pq);

	return StackPop(pq->queue);
}
// 得到队首数据(不出队)
STDataType QueueTop(QueueByStack* pq)
{
	assert(pq);

	return StackTop(pq->queue);
}
// 判断队列是否为空队
int QueueEmpty(QueueByStack* pq)
{
	assert(pq);

	return StackEmpty(pq->queue);
}
// 打印当前队列内元素
void QueuePrint(QueueByStack* pq)
{
	assert(pq);

	int i;

	for (i = pq->queue->_top - 1; i >= 0; i--)
	{
		PRINTQUEUE(pq->queue->_data[i]);
	}
	putchar('\n');
}

//测试以上所有的函数
void TestStack()
{
	int i;
	char *str = "{[{abcd}{ef}]{gh}}";
	char *str2 = "int main()\n{ \n	TestStack();\n	system(\"pause\");\n	return 0;\n}";
	Stack S, *ps = &S;
	STDataType val;

	StackInit(ps);

	srand((unsigned int)time(NULL));
	for (i = 0; i < 10; i++)
	{
		val = rand() % 10 + PLUS;
		StackPush(ps, val);
	}
	while (!StackEmpty(ps)) //类似于打印栈，但在这里是一边打印一边出栈
	{
		StackPrint(ps);
		val = StackPop(ps);
		if (val == 5 + PLUS)
		{
			val = rand() % 10 + PLUS;
			StackPush(ps, val);
			printf("\n出栈数据为5，此时入栈%d\n", val - PLUS);
		}
	}
	putchar('\n');
	printf("字符串\n\n%s\n\n是括号匹配的吗? ", str);
	if (IsValid(str))
	{
		printf("Yes!\n");
	}
	else
	{
		printf("No!\n");
	}

	StackDestory(ps);
}

void TestQueueByStack()
{
	int i;
	QueueByStack Q, *pq = &Q;
	STDataType val;

	QueueInit(pq);

	srand((unsigned int)time(NULL));
	for (i = 0; i < 10; i++)
	{
		val = rand() % 10 + PLUS;
		QueuePush(pq, val);
	}
	while (!QueueEmpty(pq)) //类似于打印队列，但在这里是一边打印一边出队
	{
		QueuePrint(pq);
		val = QueuePop(pq);
		if (val == 5 + PLUS)
		{
			val = rand() % 10 + PLUS;
			QueuePush(pq, val);
			printf("\n出队数据为5，此时入队%d\n", val - PLUS);
		}
	}
	putchar('\n');

	QueueDestory(pq);
}