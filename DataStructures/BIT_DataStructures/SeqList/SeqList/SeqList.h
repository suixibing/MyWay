#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _SEQLIST_H_
#define _SEQLIST_H_
// 顺序表的动态存储 

#define SLDataType int //顺序表的数据

typedef struct SeqList
{
	SLDataType* array;  // 指向动态开辟的数组     
	size_t size;       // 有效数据个数     
	size_t capacity;   // 容量空间的大小 
}SeqList;

// 基本增删查改接口 
void SeqListInit(SeqList* psl, size_t capacity); //顺序表初始化
void SeqListDestory(SeqList* psl); //顺序表销毁

void CheckCapacity(SeqList* psl); //顺序表已满时，将顺序表扩充为两倍
void SeqListPushBack(SeqList* psl, SLDataType x); //从表尾增加数据
void SeqListPopBack(SeqList* psl); //从表尾删除数据
void SeqListPushFront(SeqList* psl, SLDataType x); //从表头增加数据
void SeqListPopFront(SeqList* psl); //从表头删除数据

int SeqListFind(SeqList* psl, SLDataType x); //在顺序表中查找数据
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x); //在pos位置插入数据
void SeqListErase(SeqList* psl, size_t pos); //删除pos位置的数据
void SeqListRemove(SeqList* psl, SLDataType x); //删除最先出现的指定数据
void SeqListModify(SeqList* psl, size_t pos, SLDataType x); //修改pos位置的数据为指定数据
void SeqListPrint(SeqList* psl); //打印顺序表

// 扩展面试题实现
void SeqListBubbleSort(SeqList* psl); //冒泡排序
int SeqListBinaryFind(SeqList* psl, SLDataType x); //二分查找

// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 

void SeqListRemoveAll(SeqList* psl, SLDataType x); //删除重复的指定数据
#endif // !_SEQLIST_H_
