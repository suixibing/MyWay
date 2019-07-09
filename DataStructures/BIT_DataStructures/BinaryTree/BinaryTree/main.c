#include"BinaryTree.h"

int main()
{
	BTNode *root;
	BTDataType a[100] = "ABD##E#H##CF##G##";
	int pi = 0, n = strlen(a);

	root = BinaryTreeCreate(a, n, &pi, NULL);
	BinaryTreePrint(root);

	system("pause");
	return 0;
}