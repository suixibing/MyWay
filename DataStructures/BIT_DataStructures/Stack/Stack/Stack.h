#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _STACK_H_
#define _STACK_H_

#define N 10
typedef int STDataType; 

typedef struct Stack 
{
	STDataType* _a;    
	int _top;       // 栈顶    
	int _capacity;  // 容量 
}Stack;

void StackInit(Stack* ps); //栈初始化
void StackDestory(Stack* ps); //栈销毁

void StackPush(Stack* ps, STDataType x); //数据入栈
void StackPop(Stack* ps); //数据出栈
STDataType StackTop(Stack* ps); //得到栈顶数据(不出栈)
int StackEmpty(Stack* ps); //判断栈是否为空栈
int StackSize(Stack* ps); //当栈已满时，扩充容量为二倍。返回栈内元素的个数。
void StackPrint(Stack* ps); //打印当前栈内元素

void TestStack(); //测试以上所有的函数

#endif //_STACK_H_