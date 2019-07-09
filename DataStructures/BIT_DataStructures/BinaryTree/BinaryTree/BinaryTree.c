#include"BinaryTree.h"

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi, BTNode* parent)
{
	assert(a);
	assert(pi);

	BTNode *root = (BTNode*)malloc(sizeof(BTNode));

	if (*pi < n && a[*pi] != BTREE_END)
	{
		root->_data = a[*pi];
		(*pi)++;
		root->_pLeft = BinaryTreeCreate(a, n, pi, root);
		(*pi)++;
		root->_pRight = BinaryTreeCreate(a, n, pi, root);
		(*pi)++;
		root->_pParent = parent;
	}
	else
	{
		free(root);
		root = NULL;
	}

	return root;
}
void BinaryTreeDestory(BTNode** root)
{

}

int BinaryTreeSize(BTNode* root)
{

}
int BinaryTreeLeafSize(BTNode* root)
{

}
int BinaryTreeLevelKSize(BTNode* root, int k)
{

}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{

}

// 遍历 
void BinaryTreePrevOrder(BTNode* root)
{

}
void BinaryTreeInOrder(BTNode* root)
{

}
void BinaryTreePostOrder(BTNode* root)
{

}

// 非递归遍历 // 层序遍历 
void BinaryTreeLevelOrder(BTNode* root) 
{

}
// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root)
{

}

void BinaryTreePrevOrderNonR(BTNode* root)
{

}
void BinaryTreeInOrderNonR(BTNode* root)
{

}
void BinaryTreePostOrderNonR(BTNode* root)
{

}

void BinaryTreePrint(BTNode* root)
{
	if (root)
	{
		BTREE_PRINT(root->_data);
		BinaryTreePrint(root->_pLeft);
		BinaryTreePrint(root->_pRight);
	}
}

void TestBinaryTree()
{

}