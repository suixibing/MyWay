#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#ifndef _SORT_H_

#define _SORT_H_

#define DATAPRINT(data) printf("%2d ", data)
typedef int SORTDATA;

void InsertSort(SORTDATA arr[], int size); // ÷±Ω”≤Â»Î≈≈–Ú
void ShellSort(SORTDATA arr[], int size); // œ£∂˚≈≈–Ú(Àı–°‘ˆ¡ø≈≈–Ú)
void SeclectionSort(SORTDATA arr[], int size); // —°‘Ò≈≈–Ú
void HeapSort(SORTDATA arr[], int size); // ∂—≈≈–Ú
void BubbleSort(SORTDATA arr[], int size); // √∞≈›≈≈–Ú
void MergeSort(SORTDATA arr[], int left, int right); // πÈ≤¢≈≈–Ú

void Print(SORTDATA arr[], int size); // ¥Ú”° ˝æ›

#endif // _SORT_H_