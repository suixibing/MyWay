#define _CRT_SECURE_NO_WARNINGS 1

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int data[100];
	int top;
}List;

typedef struct Tree
{
	char data;
	struct Tree *left;
	struct Tree *right;
}Tree;

int Insert(List **p)
{
	int i, input;

	scanf("%d", &input);
	if ((*p)->top + 1 == 100)
	{
		printf("OVER ERROR!\n");
		return 0;
	}
	for (i = (*p)->top; i >= 0; i--)
	{
		if (input > (*p)->data[i])
		{
			break;
		}
		(*p)->data[i + 1] = (*p)->data[i];
	}
	(*p)->data[i + 1] = input;

	return 1;
}

void InsertCreat(List **p)
{
	int i, num;

	(*p)->top = -1;
	printf("输入数字的个数(<=100):>");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		if (Insert(p))
		{
			(*p)->top++;
		}
		else
		{
			return;
		}
	}
}

int BSearch(List *p, int k)
{
	int left = 0;
	int right = p->top;
	int mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (p->data[mid] > k)
		{
			right = mid - 1;
		}
		else if (p->data[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

void InputTree(Tree **tree, char input)
{
	Tree *p = *tree;

	while ((p->data >= '0' && p->data <= '9') || (p->data >= 'a' && p->data <= 'z') || (p->data >= 'A' && p->data <= 'Z'))
	{
		if (p->data < input)
		{
			if (p->right == NULL)
			{
				p->right = (Tree*)calloc(1, sizeof(Tree));
				p->right->data = input;
				p->right->right = NULL;
				p->right->left = NULL;
				break;
			}
			p = p->right;
		}
		else
		{
			if (p->left == NULL)
			{
				p->left = (Tree*)calloc(1, sizeof(Tree));
				p->left->data = input;
				p->left->right = NULL;
				p->left->left = NULL;
				break;
			}
			p = p->left;
		}
	}
}

void CandomCreate(Tree **tree)
{
	char tmp[100] = { 0 };
	int i, num, flag;

	srand((unsigned int)time(NULL));
	printf("请输入随机关键字的长度(<=100):>");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		flag = rand() % 3;
		if (flag == 1)
		{
			tmp[i] = rand() % 10 + '0';
		}
		else if(flag == 2)
		{
			tmp[i] = rand() % 26 + 'a';
		}
		else
		{
			tmp[i] = rand() % 26 + 'A';
		}
	}
	printf("随机关键字为:%s\n", tmp);
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	(*tree)->data = tmp[0];
	for (i = 1; i < num; i++)
	{
		InputTree(tree, tmp[i]);
	}
}

void PrintTree(Tree *p)
{
	if (p == NULL)
	{
		return;
	}
	PrintTree(p->left);
	putchar(p->data);
	PrintTree(p->right);
}

void NodeDeleteTree(Tree **last, Tree *p)
{
	if (p->left == NULL)
	{
		(*last)->right = p->right;
	}
	else if (p->right == NULL)
	{
		(*last)->right = p->left;
	}
	else
	{
		p = p->right;
		while (p->left != NULL)
		{
			p = p->left;
		}
		p->left = (*last)->right->left;
		(*last)->right = (*last)->right->right;
	}
}

void DeleteTreeNode(Tree **t, char k)
{
	int flag = 0;
	Tree *last = *t, *p = *t;

	while (p != NULL && k != p->data)
	{
		last = p;
		if (k > p->data)
		{
			flag = 0;
			p = p->right;
		}
		else
		{
			flag = 1;
			p = p->left;
		}
	}
	NodeDeleteTree(&p, p);
	//if (p)
	//{
	//	if (flag)
	//	{
	//		if (p->left == NULL)
	//		{
	//			last->left = p->right;
	//		}
	//		else if (p->right == NULL)
	//		{
	//			last->left = p->left;
	//		}
	//		else
	//		{
	//			p = p->right;
	//			while (p->left != NULL)
	//			{
	//				p = p->left;
	//			}
	//			p->left = last->left->left;
	//			last->left = last->left->right;
	//		}
	//	}
	//	else
	//	{
	//		if (p->left == NULL)
	//		{
	//			last->right = p->right;
	//		}
	//		else if (p->right == NULL)
	//		{
	//			last->right = p->left;
	//		}
	//		else
	//		{
	//			p = p->right;
	//			while (p->left != NULL)
	//			{
	//				p = p->left;
	//			}
	//			p->left = last->right->left;
	//			last->right = last->right->right;
	//		}
	//	}
	//	printf("删除成功!\n");
	//}
	//else
	//{
	//	printf("不存在!\n");
	//}
}

void Menu()
{
	putchar('\n');
	printf("1、建立有序表,采用折半查找实现某一已知的关键字的查找(采用顺序表存储结构)\n");
	printf("2、随机产生一组关键字, 利用二叉排序树的插入算法建立二叉排序树\n");
	printf("3、在以上二叉排序树中删除某一指定关键字元素\n");
	putchar('\n');
	printf("请输入您的选择:>");
}

int main()
{
	char ch;
	int k, ret, choice = 1;
	List list, *pl = &list;
	Tree tree, *pt = &tree, *t = NULL;
	
	while (choice)
	{
		Menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			InsertCreat(&pl);
			printf("要查找的数:>");
			scanf("%d", &k);
			ret = BSearch(pl, k);
			if (ret != -1)
			{
				printf("找到了!在第%d个\n", ret + 1);
			}
			else
			{
				printf("没找到!\n");
			}
			break;
		case 2:
			CandomCreate(&pt);
			printf("中序遍历生成的二叉排序树:>");
			PrintTree(pt);
			putchar('\n');
			break;
		case 3:
			printf("请输入您要删除的字符:>");
			getchar();
			ch = getchar();
			DeleteTreeNode(pt, ch);
			printf("删除字符后的二叉排序树:>");
			PrintTree(pt);
			putchar('\n');
			break;
		default:
			printf("ERROR!\n");
			break;
		}
	}

	system("pause");
	return 0;
}