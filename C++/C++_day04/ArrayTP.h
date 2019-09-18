#pragma once

#include<iostream>

template <class Type, int Size = 5>
class ArrayTP
{
private:
	Type m_arr[Size];
public:
	ArrayTP() {}
	ArrayTP(const ArrayTP& arr);
	Type& operator[](int n);
	Type operator[](int n)const;
};

template <class Type, int Size>
ArrayTP<Type, Size>::ArrayTP(const ArrayTP<Type, Size>& arr)
{
	for (int i = 0; i < arr[Size]; i++)
	{
		m_arr[i] = arr.m_arr[i];
	}
}

template <class Type, int Size>
Type& ArrayTP<Type, Size>::operator[](int n)
{
	if (n < 0 || n >= Size)
	{
		std::cout << "下标错误，请输入合法的下标（0-" << Size << ")\n";
		std::exit(EXIT_FAILURE);
	}
	return m_arr[n];
}

template <class Type, int Size>
Type ArrayTP<Type, Size>::operator[](int n)const
{
	if (n < 0 || n >= Size)
	{
		std::cout << "下标错误，请输入合法的下标（0-" << Size << ")\n";
		std::exit(EXIT_FAILURE);
	}
	return m_arr[n];
}
