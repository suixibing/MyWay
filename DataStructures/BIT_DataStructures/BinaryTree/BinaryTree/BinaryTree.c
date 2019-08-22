#include"BinaryTree.h"

// 二叉树的建立
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
// 二叉树的销毁
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
// 二叉树的结点数
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
// 二叉树的叶子结点数
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

	return count;
}
// 二叉树在指定层的结点数
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
// 查找指定数据
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

// 递归遍历 
// 先序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		BTREE_PRINT(root->_data);
		BinaryTreePrevOrder(root->_pLeft);
		BinaryTreePrevOrder(root->_pRight);
	}
}
// 中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_pLeft);
		BTREE_PRINT(root->_data);
		BinaryTreeInOrder(root->_pRight);
	}
}
// 后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_pLeft);
		BinaryTreePostOrder(root->_pRight);
		BTREE_PRINT(root->_data);
	}
}

// 层序遍历 
void BinaryTreeLevelOrder(BTNode* root) 
{
	assert(root);

	BTNode *queue[100];
	int head = 0, tail = 0;

	queue[tail++] = root;
	while (head != tail)
	{
		BTREE_PRINT(queue[head]->_data);
		if (queue[head]->_pLeft)
		{
			queue[tail++] = queue[head]->_pLeft;
		}
		if (queue[head]->_pRight)
		{
			queue[tail++] = queue[head]->_pRight;
		}
		head++;
	}
}
// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root)
{
	assert(root);

	BTNode *queue[100];
	int head = 0, tail = 0;

	queue[tail++] = root;
	while (head != tail)
	{
		if (!queue[head])
		{
			break;
		}
		queue[tail++] = queue[head]->_pLeft;
		queue[tail++] = queue[head]->_pRight;
		head++;
	}
	while (head != tail)
	{
		if (queue[head])
		{
			return 0;
		}
		head++;
	}

	return 1;
}

// 非递归遍历 
// 先序遍历
void BinaryTreePrevOrderNonR(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur;
	int top = -1;

	stack[++top] = root;
	while (top >= 0)
	{
		cur = stack[top--];
		if (cur)
		{
			BTREE_PRINT(cur->_data);
			stack[++top] = cur->_pRight;
			stack[++top] = cur->_pLeft;
		}
	}
}
// 中序遍历
void BinaryTreeInOrderNonR(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root;
	int top = -1;

	while (top >= 0 || cur)
	{
		if (cur)
		{
			stack[++top] = cur;
			cur = cur->_pLeft;
		}
		else
		{
			cur = stack[top--];
			BTREE_PRINT(cur->_data);
			cur = cur->_pRight;
		}
	}
}
// 后序遍历
void BinaryTreePostOrderNonR(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root, *last = root;
	int top = -1;

	stack[++top] = cur;
	cur = cur->_pLeft;
	while (top >= 0)
	{
		while (cur && cur->_pLeft != last && cur->_pRight != last)
		{
			stack[++top] = cur;
			cur = cur->_pLeft;
		}
		cur = stack[top--];
		if (!cur->_pRight || cur->_pRight == last)
		{
			last = cur;
			BTREE_PRINT(cur->_data);
			if (top >= 0)
			{
				cur = stack[top];
			}
		}
		else
		{
			stack[++top] = cur;
			cur = cur->_pRight;
		}
	}
}

// 非递归遍历 
// 先序遍历
void BinaryTreePrevOrderNonR2(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root;
	int top = -1;

	while (top > -2)
	{
		BTREE_PRINT(cur->_data); // 访问结点
		if (cur->_pRight) // 如果有右孩子，右孩子入栈
		{
			stack[++top] = cur->_pRight;
		}
		if (cur->_pLeft) // 如果有左孩子，先访问左孩子
		{
			cur = cur->_pLeft;
		}
		else // 没有左孩子，访问栈顶
		{
			cur = stack[top--];
		}
	}
}
// 中序遍历
void BinaryTreeInOrderNonR2(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root;
	int top = -1;

	while (top > -2)
	{
		while (cur && cur->_pLeft && cur != stack[top + 1])
		{
			stack[++top] = cur;
			cur = cur->_pLeft;
		}
		BTREE_PRINT(cur->_data);
		if (cur->_pRight)
		{
			cur = cur->_pRight;
		}
		else
		{
			cur = stack[top--];
		}
	}
}
// 后序遍历
void BinaryTreePostOrderNonR2(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root, *last = root;
	int top = -1;

	while (top > -2)
	{
		while (cur && cur->_pLeft && cur != stack[top + 1])
		{
			stack[++top] = cur;
			cur = cur->_pLeft;
		}
		if (cur->_pRight && cur->_pRight != stack[top + 2])
		{
			stack[++top] = cur;
			cur = cur->_pRight;
		}
		else
		{
			BTREE_PRINT(cur->_data);
			stack[top + 1] = cur;
			cur = stack[top--];
		}
	}
}
// 中序遍历
void BinaryTreeInOrderNonR3(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root;
	int top = -1;

	while (top >= 0 || cur)
	{
		for (; cur; cur = cur->_pLeft) // 将当前结点和所有左孩子入栈
		{
			stack[++top] = cur;
		}
		if (top >= 0)
		{
			cur = stack[top--]; // 访问栈顶（未访问结点中最左下方的结点）
			BTREE_PRINT(cur->_data); // 访问结点
			cur = cur->_pRight; 
		}
	}
}
// 后序遍历
void BinaryTreePostOrderNonR3(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root, *last = root;
	int tag[100] = { 0 };
	int top = -1;

	do
	{
		for (; cur; cur = cur->_pLeft) // 将当前结点和所有左孩子入栈并标记 0
		{
			stack[++top] = cur;
			tag[top] = 0;
		}
		while (top >= 0 && tag[top]) // 访问栈中所有右孩子已访问过的结点
		{
			cur = stack[top--];
			BTREE_PRINT(cur->_data);
		}
		if (top >= 0)
		{
			cur = stack[top];
			cur = cur->_pRight;
			tag[top] = 1; // 表示已经访问过右孩子结点
		}
	} while (top >= 0);
}

// 通过调用各种遍历来打印
void BinaryTreePrint(BTNode* root)
{
	assert(root);

	printf("\n先序遍历：");
	BinaryTreePrevOrder(root);
	printf("(遍历实现)\t");
	BinaryTreePrevOrderNonR(root);
	printf("(非遍历实现)\t");
	BinaryTreePrevOrderNonR2(root);
	printf("(非遍历实现2)\t");

	printf("\n中序遍历：");
	BinaryTreeInOrder(root);
	printf("(遍历实现)\t");
	BinaryTreeInOrderNonR(root);
	printf("(非遍历实现)\t");
	BinaryTreeInOrderNonR2(root);
	printf("(非遍历实现2)\t");
	BinaryTreeInOrderNonR3(root);
	printf("(非遍历实现3)\t");

	printf("\n后序遍历：");
	BinaryTreePostOrder(root);
	printf("(遍历实现)\t");
	BinaryTreePostOrderNonR(root);
	printf("(非遍历实现)\t");
	BinaryTreePostOrderNonR2(root);
	printf("(非遍历实现2)\t");
	BinaryTreePostOrderNonR3(root);
	printf("(非遍历实现3)\t");

	printf("\n层序遍历：");
	BinaryTreeLevelOrder(root);
	putchar('\n');
}

// 测试函数
void TestBinaryTree()
{
	BTNode *root, *tmp;
	BTDataType a[100] = "ABD##E#H##CF##G##";
	BTDataType a2[100] = "ABD##E##CF##G##";
	BTDataType a3[100] = "ABDK##N##E##CF##G##";
	int pi = 0, n = strlen(a), ret;

	root = BinaryTreeCreate(a, n, &pi, NULL);
	if (BinaryTreeComplete(root))
	{
		printf("是完全二叉树!\n");
	}
	else
	{
		printf("不是完全二叉树!\n");
	}
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
}