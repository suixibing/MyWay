#pragma once
#include<iostream>

template <class Type>
class StackTP
{
private:
	enum { SIZE = 10 };
	Type *m_items;
	int m_capacity;
	int m_top;
public:
	explicit StackTP(int capacity = SIZE);
	StackTP(const StackTP& s);
	~StackTP() { delete[] m_items; }
	bool IsEmpty() { return m_top == 0; }
	bool IsFull() { return m_top == m_capacity; }
	bool Push(const Type& item);
	bool Pop(Type& item);
	const StackTP& operator=(const StackTP& s);
};

template <class Type>
StackTP<Type>::StackTP(int capacity) : m_capacity(capacity), m_top(0)
{
	m_items = new Type[m_capacity];
}

template <class Type>
StackTP<Type>::StackTP(const StackTP<Type>& s)
{
	m_capacity = s.m_capacity;
	m_top = s.m_top;
	m_items = new Type[m_capacity];
	for (int i = 0; i < m_top; i++)
	{
		m_items[i] = s.m_items[i];
	}
}

template <class Type>
bool StackTP<Type>::Push(const Type& item)
{
	if (IsFull())
	{
		return false;
	}
	m_items[m_top++] = item;
	return true;
}

template <class Type>
bool StackTP<Type>::Pop(Type& item)
{
	if (IsEmpty())
	{
		return false;
	}
	item = m_items[--m_top];
	return true;
}

template <class Type>
const StackTP<Type>& StackTP<Type>::operator=(const StackTP<Type>& s)
{
	if (*this == &s)
	{
		return s;
	}
	delete[] m_items;
	m_capacity = s.m_capacity;
	m_top = s.m_top;
	m_items = new Type[m_capacity];
	for (int i = 0; i < m_top; i++)
	{
		m_items[i] = s.m_items[i];
	}
	return *this;
}