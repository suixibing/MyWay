#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#ifndef _SORT_H_

#define _SORT_H_

#define SIZE 20000
#define DATAPRINT(data) printf("%5d ", data)
typedef int SORTDATA;

void InsertSort(SORTDATA arr[], int size); // ÷±Ω”≤Â»Î≈≈–Ú
void ShellSort(SORTDATA arr[], int size); // œ£∂˚≈≈–Ú(Àı–°‘ˆ¡ø≈≈–Ú)
void SeclectionSort(SORTDATA arr[], int size); // —°‘Ò≈≈–Ú
void HeapSort(SORTDATA arr[], int size); // ∂—≈≈–Ú
void BubbleSort(SORTDATA arr[], int size); // √∞≈›≈≈–Ú
void QuickSort(SORTDATA arr[], int left, int right); // øÏÀŸ≈≈–Ú
void MergeSort(SORTDATA arr[], int size); // πÈ≤¢≈≈–Ú
void BucketSort(SORTDATA arr[], int size); // Õ∞≈≈–Ú

void Print(SORTDATA arr[], int size); // ¥Ú”° ˝æ›
int Judge(SORTDATA arr[], int size);

#endif // _SORT_H_