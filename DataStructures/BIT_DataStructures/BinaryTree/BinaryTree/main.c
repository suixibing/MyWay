#include"BinaryTree.h"

int main()
{
	BTNode *root, *tmp;
	BTDataType a[100] = "ABD##E#H##CF##G##";
	int pi = 0, n = strlen(a), ret;

	root = BinaryTreeCreate(a, n, &pi, NULL);
	ret = BinaryTreeSize(root);
	printf("BinaryTreeSize = %d\n", ret);
	ret = BinaryTreeLeafSize(root);
	printf("BinaryTreeLeafSize = %d\n", ret);
	ret = BinaryTreeLevelKSize(root, 5);
	printf("BinaryTreeLevelKSize = %d\n", ret);
	tmp = BinaryTreeFind(root, 'C');
	BinaryTreePrint(tmp);
	putchar('\n');
	BinaryTreePrint(root);
	putchar('\n');
	BinaryTreeDestory(&root);

	system("pause");
	return 0;
}