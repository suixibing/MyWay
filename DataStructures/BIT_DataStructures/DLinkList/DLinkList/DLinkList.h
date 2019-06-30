#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

// 2、带头双向循环链表增删查改实现 

typedef int LTDataType; //带头双向循环链表的数据

typedef struct DListNode
{
	LTDataType _data;
	struct DListNode* _next;
	struct DListNode* _prev;
}DListNode; //带头双向循环链表的结点

typedef struct List
{
	DListNode* _head;
}DList; //带头双向循环链表的头结点

void DListInit(DList* plist); //链表初始化
void DListDestory(DList* plist); //链表销毁

void DListPushStart(DList* plist, LTDataType x); //头插法插入数据
void DListPopStart(DList* plist); //头插法删除数据
void DListPushTail(DList* plist, LTDataType x); //尾插法插入数据
void DListPopTail(DList* plist); //尾插法删除数据

DListNode* DListFind(DList* plist, LTDataType x); //在链表中查找数据

void DListInsertBefore(DListNode* pos, LTDataType x); //在pos的前面进行插入
void DListInsertAfter(DListNode* pos, LTDataType x); //在pos的后面进行插入
void DListErase(DListNode* pos); //删除pos位置的节点
void DListRemove(DList* plist, LTDataType x); //删除所有数据为x的节点

void DListPrint(DList* plist); //打印链表

#endif //_DLINKLIST_H_