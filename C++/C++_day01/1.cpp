#include<iostream>
#include"Test.h"
#include<ctime>

using namespace std;

template<> bool CompareMax<Time>(Time a, Time b)
{
	return a.Seconds() >= b.Seconds();
}
template<> bool CompareMin<Time>(Time a, Time b)
{
	return a.Seconds() <= b.Seconds();
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[5] = { 13, 52, 1, 5, 32 };
	double arrd[10] = { 32.3, 32.1, 4.2, 53.2, 43, 42, 23, 52.23, 24, 52 };

	Sort(arr, 5, CompareMax);
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
	Sort(arrd, 10, CompareMax, 2);
	for (auto i : arrd)
	{
		cout << i << " ";
	}

	Time t[10];
	Sort(t, 10, CompareMin, 2);
	cout << "\nNewline:\n";
	for (auto i : t)
	{
		i.TimeAdjust();
		cout << i;
	}

	system("pause");
	return 0;
}