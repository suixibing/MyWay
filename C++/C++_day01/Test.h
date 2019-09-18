#pragma once

#include<iostream>

using namespace std;


class Time
{
private:
	int m_day;
	int m_hour;
	int m_minite;
	int m_second;
public:
	Time();
	void TimeAdjust();
	int Seconds();
	friend ostream& operator<<(ostream& os, Time& t);
};

enum
{
	INSERTIONSORT,
	BUBBLESORT,
	QUICKSORT,
};

template <class T>
void Change(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T>
bool CompareMax(T a, T b)
{
	return a >= b;
}

template <class T>
bool CompareMin(T a, T b)
{
	return a <= b;
}

template <class T>
void InsertionSort(T arr[], int n, bool(*Compare)(T x, T y))
{
	int i, j;

	for (i = 1; i < n; i++)
	{
		T tmp = arr[i];
		for (j = i - 1; j >= 0 && Compare(arr[j], tmp); j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
	}
}

template <class T>
void BubbleSort(T arr[], int n, bool(*Compare)(T x, T y))
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (Compare(arr[j], arr[j + 1]))
			{
				Change(arr[j], arr[j + 1]);
			}
		}
	}
}

template <class T>
void QuickSort(T arr[], int left, int right, bool(*Compare)(T x, T y))
{
	T key = arr[left];
	int i = left, j = right;

	if (i >= j)
	{
		return;
	}
	while (i < j)
	{
		while (i < j && Compare(arr[j], key))
		{
			j--;
		}
		while (i < j && Compare(key, arr[i]))
		{
			i++;
		}
		if (i < j)
		{
			Change(arr[i], arr[j]);
		}
	}
	arr[left] = arr[i];
	arr[i] = key;
	QuickSort(arr, left, i - 1, Compare);
	QuickSort(arr, i + 1, right, Compare);
}

template <class T>
void Sort(T arr[], int n, bool (*Compare)(T x, T y) = CompareMax, int flag = INSERTIONSORT)
{
	switch (flag)
	{
	case INSERTIONSORT:
		InsertionSort(arr, n, Compare);
		break;
	case BUBBLESORT:
		BubbleSort(arr, n, Compare);
		break;
	case QUICKSORT:
		QuickSort(arr, 0, n - 1, Compare);
		break;
	}
}
