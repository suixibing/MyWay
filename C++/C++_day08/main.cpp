#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
	vector<int> v;
	AVLTree<int> avl;

	avl.insert(30);
	avl.insert(20);
	avl.insert(10);
	avl.insert(60);
	avl.insert(25);
	avl.insert(22);
	avl.insert(35);

	v = avl.InOrder();
	for (auto i : v)
	{
		cout << i << " ";
	}
	avl.~AVLTree();
	return 0;
}