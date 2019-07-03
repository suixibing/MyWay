#include"Stack.h"
//栈初始化
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (STDataType*)malloc(N * sizeof(STDataType));
	ps->_capacity = N;
	ps->_top = 0;
}
//栈销毁
void StackDestory(Stack* ps)
{
	assert(ps);

	ps->_top = 0;
	free(ps->_a);
}
//数据入栈
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);

	StackSize(ps);

	ps->_a[ps->_top] = x;
	ps->_top++;
}
//数据出栈
void StackPop(Stack* ps)
{
	assert(ps);

	ps->_top--;
}
//得到栈顶数据(不出栈)
STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->_a[ps->_top - 1];
}
//判断栈是否为空栈
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top;
}
//当栈已满时，扩充容量为二倍。返回栈内元素的个数。
int StackSize(Stack* ps)
{
	assert(ps);

	if (ps->_top == ps->_capacity)
	{
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * 2 * sizeof(STDataType));
		ps->_capacity *= 2;
	}

	return ps->_top;
}
//打印当前栈内元素
void StackPrint(Stack* ps)
{
	assert(ps);

	int i;

	for (i = ps->_top - 1; i >= 0; i--)
	{
		printf("%2d || ", ps->_a[i]);
	}
	putchar('\n');
}
//测试以上所有的函数
void TestStack()
{
	int i, j;
	Stack S, *ps = &S;

	StackInit(ps);

	for (i = 0; i < 10; i += 4)
	{
		for (j = 1; j < 10; j += 3)
		{
			StackPush(ps, i + j);
		}
	}
	while (StackEmpty(ps)) //类似于打印栈，但在这里是一边打印一边出栈
	{
		StackPrint(ps);
		StackPop(ps);
	}
	putchar('\n');

	StackDestory(ps);
}