#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define	ERROR 0
#define TRUE 1
#define END -999
#define ElemType int

typedef struct NODE
{
	ElemType data;
	struct NODE *next;
} *LinkList, Node;

int InitList(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	return TRUE;
}

int PrintList(LinkList L)
{
	Node *current;
	current = L;
	if (L == NULL)
	{
		printf("表未初始化\n");
		return ERROR;
	}
	while (current->next != NULL)
	{
		current = current->next;
		printf("%d ", current->data);
	}
	if (L->next != NULL)
	{
		putchar('\n');
	}

	return TRUE;
}

//头插法建表
int CreateListFromHead(LinkList L)
{
	Node *node;
	ElemType element;

	if (L == NULL)
	{
		printf("表未初始化\n");
		return ERROR;
	}
	while (1)
	{
		scanf("%d", &element);
		if (element == END)
		{
			break;
		}
		node = (Node *)malloc(sizeof(Node));
		node->data = element;
		node->next = L->next;
		L->next = node;
	}

	return TRUE;
}

int SizeOfList(LinkList L)
{
	int num = 0;
	Node *node;

	if (L == NULL)
	{
		printf("表未初始化\n");
		return ERROR;
	}
	node = L;
	while (node->next != NULL)
	{
		num++;
		node = node->next;
	}

	return num;
}

int ReverseList(LinkList *L)
{
	Node *tmp, *head;
	LinkList pl;

	if (*L == NULL)
	{
		printf("表未初始化\n");
		return ERROR;
	}
	InitList(&pl);
	head = (*L);
	while ( head->next != NULL)
	{
		tmp = head->next;
		head->next = tmp->next;
		tmp->next = pl->next;
		pl->next = tmp;
	}
	(*L)->next = pl->next;
	free(pl);

	return TRUE;
}

int InsNoDecreasing(LinkList L, ElemType element)
{
	Node *node, *tmp;

	if (L == NULL)
	{
		printf("表未初始化\n");
		return ERROR;
	}
	node = L;
	while (node->next != NULL && (node->next)->data < element)
	{
		node = node->next;
	}
	tmp = (Node *)malloc(sizeof(Node));
	tmp->data = element;
	tmp->next = node->next;
	node->next = tmp;

	return TRUE;
}

int NoDecreasingList(LinkList L)
{
	ElemType element;

	if (L == NULL)
	{
		printf("表未初始化\n");
		return ERROR;
	}
	while (1)
	{
		scanf("%d", &element);
		if (element == END)
		{
			break;
		}
		InsNoDecreasing(L, element);
	}

	return TRUE;
}

int main()
{
	LinkList L = NULL;

	InitList(&L);
	//CreateListFromHead(L);
	NoDecreasingList(L);
	printf("%d\n", SizeOfList(L));
	PrintList(L);
	ReverseList(&L);
	PrintList(L);
	
	system("pause");
	return 0;
}
