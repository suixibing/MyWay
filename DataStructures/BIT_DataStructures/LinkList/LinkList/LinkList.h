#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _LINKLIST_H_
#define _LINKLIST_H_

// 1、无头单向非循环链表增删查改实现 

typedef int SLTDataType; //无头单向非循环链表的数据

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;//无头单向非循环链表的结点

typedef struct SList
{
	SListNode* _head;
}SList; // 无头单向非循环链表的头结点

void SListInit(SList* plist); // 链表初始化
void SListDestory(SList* plist); // 链表销毁

SListNode* BuySListNode(SLTDataType val); // 将数据放入一个结点
void SListPushFront(SList* plist, SLTDataType val); // 头插法插入数据
void SListPopFront(SList* plist); // 头删法删除数据
SListNode* SListFind(SList* plist, SLTDataType val); // 在链表中查找数据

void SListInsertAfter(SListNode* pos, SLTDataType val); // 在pos的后面进行插入 
void SListInsertFront(SList* plist, SListNode* pos, SLTDataType val); // 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos); // 删除pos下一个位置的数据
void SListRemove(SList* plist, SLTDataType val); // 删除最先出现的指定数据

void SListReverse(SList* plist); // 链表反转
SListNode* GetIntersectionNode(SList* listA, SList* listB); // 判断两链表是否相交
int SListHasCycle(SList* plist); // 判断链表是否成环
SListNode* SListDetectCycle(SList* plist); // 找到入环结点

int RemoveElements(SList* head, int val); // 删除所有指定元素
SListNode* MiddleNode(SList* head); // 返回中间结点

void SListPrint(SList* plist); // 打印链表
void TestSList(); // 测试函数

#endif //_LINKLIST_H_