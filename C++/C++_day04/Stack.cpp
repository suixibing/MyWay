#include"Stack.h"

bool Stack::Push(const Item& item)
{
	if (IsFull())
	{
		return false;
	}
	items[top++] = item;
	return true;
}

bool Stack::Pop(Item& item)
{
	if (IsEmpty())
	{
		return false;
	}
	item = items[--top];
	return true;
}