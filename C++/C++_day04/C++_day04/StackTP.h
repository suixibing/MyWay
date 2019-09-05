#pragma once
#include<iostream>

template <class Type>
class StackTP
{
private:
	enum { MAX = 10 };
	Type items[MAX];
	int top;
public:
	StackTP() : top(0) {}
	bool IsEmpty() { return top == 0; }
	bool IsFull() { return top == MAX; }
	bool Push(const Type& item);
	bool Pop(Type& item);
};

template <class Type>
bool StackTP<Type>::Push(const Type& item)
{
	if (IsFull())
	{
		return false;
	}
	items[top++] = item;
	return true;
}

template <class Type>
bool StackTP<Type>::Pop(Type& item)
{
	if (IsEmpty())
	{
		return false;
	}
	item = items[--top];
	return true;
}