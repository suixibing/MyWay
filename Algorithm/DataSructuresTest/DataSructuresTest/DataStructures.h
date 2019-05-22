#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define END -999

//∂”¡–
typedef struct
{
	int arr[1000];
	int head;
	int tail;
}QUEUE;


//’ª
typedef struct
{
	char arr[1000];
	int top;
}STACK;


typedef struct Node
{
	int data;
	struct Node *next;
}NODE, *LIST;

typedef struct SimulateNode
{
	int data;
	int next;
}S_NODE;
