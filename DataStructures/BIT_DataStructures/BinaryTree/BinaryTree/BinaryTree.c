#include"BinaryTree.h"
//二叉树的建立
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
		root->_pParent = parent;
	}
	else
	{
		free(root);
		root = NULL;
	}

	return root;
}
//二叉树的销毁
void BinaryTreeDestory(BTNode** root)
{
	if ((*root)->_pLeft)
	{
		BinaryTreeDestory(&((*root)->_pLeft));
	}
	if ((*root)->_pRight)
	{
		BinaryTreeDestory(&((*root)->_pRight));
	}
	if (*root)
	{
		free(*root);
	}
}
//二叉树的结点数
int BinaryTreeSize(BTNode* root)
{
	assert(root);

	int count = 1;

	if (root->_pLeft)
	{
		count += BinaryTreeSize(root->_pLeft);
	}
	if (root->_pRight)
	{
		count += BinaryTreeSize(root->_pRight);
	}

	return count;
}
//二叉树的叶子结点数
int BinaryTreeLeafSize(BTNode* root)
{
	assert(root);

	int count = 0;

	if (!root->_pLeft && !root->_pRight)
	{
		return 1;
	}
	if (root->_pLeft)
	{
		count += BinaryTreeLeafSize(root->_pLeft);
	}
	if (root->_pRight)
	{
		count += BinaryTreeLeafSize(root->_pRight);
	}
}
//二叉树在指定层的结点数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(root);

	int count = 0;

	if (k == 1)
	{
		return 1;
	}
	if (root->_pLeft)
	{
		count += BinaryTreeLevelKSize(root->_pLeft, k - 1);
	}
	if (root->_pRight)
	{
		count += BinaryTreeLevelKSize(root->_pRight, k - 1);
	}

	return count;
}
//查找指定数据
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	assert(root);

	BTNode *cur = NULL;

	if (root->_data == x)
	{
		return root;
	}
	if (root->_pLeft)
	{
		cur = BinaryTreeFind(root->_pLeft, x);
	}
	if (!cur && root->_pRight)
	{
		cur = BinaryTreeFind(root->_pRight, x);
	}

	return cur;
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