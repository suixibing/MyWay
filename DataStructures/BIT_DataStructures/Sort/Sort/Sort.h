#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#ifndef _SORT_H_

#define _SORT_H_

#define DATAPRINT(data) printf("%d ", data)
typedef int SORTDATA;

void InsertSort(SORTDATA arr[], int size); // 直接插入排序
void ShellSort(SORTDATA arr[], int size); // 希尔排序(缩小增量排序)
void SeclectionSort(SORTDATA arr[], int size); // 选择排序

void Print(SORTDATA arr[], int size); // 打印数据

#endif // _SORT_H_