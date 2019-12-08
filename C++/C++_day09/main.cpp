#include "RBTree.h"
#include <iostream>

using namespace std;

int main()
{
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int arr1[] = { 7, -2, 1, 5, -4, -11, 8, 14, -15 };
	lb::RBTree<int> rbt;

	for (auto i : arr)
	{
		rbt.insert(i);
		rbt.show();
		cout << endl;
	}

	//for (int i = 1; i < 11; ++i)
	//{
	//	rbt.insert(i);
	//	rbt.show();
	//	cout << endl;
	//}

	return 0;
}