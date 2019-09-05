#pragma once

typedef unsigned int Item;

class Stack
{
private:
	enum { MAX = 10 };
	Item items[MAX];
	int top;
public:
	Stack() : top(0) {}
	bool IsEmpty() { return top == 0; }
	bool IsFull() { return top == MAX; }
	bool Push(const Item& item);
	bool Pop(Item& item);
};