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
}SList; // 无头单向非循环链表的头指针

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
SListNode* GetIntersectionNode(SList* listA, SList* listB); // 判断两链表是否相交，返回相交结点
int SListHasCycle(SList* plist); // 判断链表是否成环
SListNode* SListDetectCycle(SList* plist); // 找到入环结点

int RemoveElements(SList* head, int val); // 删除所有指定数据，返回删除数据的个数
SListNode* MiddleNode(SList* head); // 返回中间结点(偶数个结点时为偏右结点)
void SListQuickSort(SListNode *head); // 快速排序
SListNode* MergeTwoLists(SList* plist1, SList* plist2); // 有序链表合并
SListNode* SListClone(SList* plist); // 链表复制
SListNode* SListPartition(SList* plist, int val); // 以给定值 val 为基准保留原来的数据顺序将链表分割成两部分
SListNode* DeleteDuplication(SList* plist); // 有序链表中删除重复结点
int CheckPalindrome(SList* plist); // 回文链表判断
SListNode* AddTwoNumbers(SList* plist1, SList* plist2); // 两数相加， 链表数据按照数字的每一位的倒序来存储

void SListPrint(SList* plist); // 打印链表
void TestSList(); // 测试函数

#endif //_LINKLIST_H_