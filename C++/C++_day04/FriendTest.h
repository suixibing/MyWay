#pragma once
#include<iostream>
#include<typeinfo>

template <class Type>
class FriendType1
{
private:
	Type m_item;
	static int m_count;
public:
	FriendType1(Type t) : m_item(t) { m_count++; };
	~FriendType1() { m_count--; }
	friend void Counts();
	friend void Report(FriendType1<Type>& f);
};

template <class Type>
int FriendType1<Type>::m_count = 0;

void Counts()
{
	std::cout << "FriendType1<int> counts: " << FriendType1<int>::m_count << ";";
	std::cout << "FriendType1<double> counts: " << FriendType1<double>::m_count << std::endl;
}

void Report(FriendType1<int>& f)
{
	std::cout << "FriendType1<int>:" << f.m_item << std::endl;
}

void Report(FriendType1<double>& f)
{
	std::cout << "FriendType1<double>:" << f.m_item << std::endl;
}


template <class T> void Counts2();
template <class T> void Report2(T&);

template <class T>
class FriendType2
{
private:
	T m_item;
	static int m_count;
public:
	FriendType2(T t) : m_item(t) { m_count++; }
	~FriendType2() { m_count--; }
	friend void Counts2<T>();
	friend void Report2<>(FriendType2<T>& f);
};

template <class T>
int FriendType2<T>::m_count = 0;

template <class T>
void Counts2()
{
	std::cout << "FriendType2 counts: " << FriendType2<T>::m_count << std::endl;
}

template <class T>
void Report2(T& f)
{
	std::cout << "FriendType2 item: " << f.m_item << std::endl;
}


template <class TT>
class FriendType3
{
private:
	TT m_item;
public:
	FriendType3(const TT& item) : m_item(item) {}
	template<class T1, class T2> friend void Show(T1& ,T2&);
};

template<class T1, class T2> 
void Show(T1& a, T2& b)
{
	std::cout << a.m_item << ", " << b.m_item << std::endl;
}