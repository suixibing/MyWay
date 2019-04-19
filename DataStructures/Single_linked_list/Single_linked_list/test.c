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
	else if (L->next == NULL)
	{
		printf("表为空表\n");
		return ERROR;
	}
	while (current->next != NULL)
	{
		current = current->next;
		printf("%4d ", current->data);
		if (current->next != NULL)
		{
			printf("-->");
		}
	}
	if (L->next != NULL)
	{
		putchar('\n');
	}

	return TRUE;
}

int DeleteList(LinkList L)
{
	Node *tmp;

	if (L == NULL)
	{
		printf("表未初始化\n");
		return ERROR;
	}
	while (L->next != NULL)
	{
		tmp = L->next;
		L->next = tmp->next;
		free(tmp);
	}
	printf("表已置为空表\n");
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

int ChangeToNoDecreasingList(LinkList L)
{
	Node *pre, *cur = NULL;
	ElemType tmp;

	if (L == NULL)
	{
		printf("表未初始化\n");
		return ERROR;
	}
	for (pre = L->next; pre->next != NULL; pre = pre->next)
	{
		for (cur = pre->next; cur != NULL; cur = cur->next)
		{
			if (cur->data < pre->data)
			{
				tmp = cur->data;
				cur->data = pre->data;
				pre->data = tmp;
			}
		}
	}

	return TRUE;
}

int DeleteFromNoDecreasingList(LinkList L, ElemType element)
{
	Node *node, *tmp;

	if (L == NULL)
	{
		printf("表未初始化\n");
		return ERROR;
	}
	node = L->next;
	tmp = L;
	while (node != NULL && node->data != element)
	{
		tmp = node;
		node = node->next;
	}
	if (node == NULL)
	{
		printf("%d不存在于表中\n", element);
		return ERROR;
	}
	while (node != NULL && node->data == element)
	{
		tmp->next = node->next;
		free(node);
		node = tmp->next;
	}

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

int MergeList(LinkList La, LinkList Lb)
{
	Node *pa, *pb, *current;

	if (La == NULL || Lb == NULL)
	{
		printf("存在表还未初始化\n");
		return ERROR;
	}
	pa = La->next;
	pb = Lb->next;
	current = La;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data < pb->data)
		{
			current->next = pa;
			current = current->next;
			pa = pa->next;
		}
		else
		{
			current->next = pb;
			current = current->next;
			pb = pb->next;
		}
	}
	if (pa == NULL)
	{
		current->next = pb;
	}
	else
	{
		current->next = pa;
	}
	Lb->next = NULL;

	return TRUE;
}

void Menu()
{
	printf("\n\n\n");
	printf("***************************************************************************************************\n");
	printf("*******              1、键盘输入一组元素，建立一个带头结点的单链表（无序）                  *******\n");
	printf("*******              2、遍历单链表                                                          *******\n");
	printf("*******              3、把单向链表中元素逆置                                                *******\n");
	printf("*******              4、建立一个非递减有序单链表                                            *******\n");
	printf("*******              5、建立两个非递减有序单链表然后合并成一个非递减链表（结束后置空）      *******\n");
	printf("*******              6、在非递减有序单链表中插入一个元素使链表仍然有序                      *******\n");
	printf("*******              7、在非递减有序链表中删除值为x的结点                                   *******\n");
	printf("*******              8、删除当前链表                                                        *******\n");
	printf("*******              9、输出当前链表中的元素个数                                            *******\n");
	printf("*******             10、将当前链表排序为非递减有序链表                                        *******\n");
	printf("***************************************************************************************************\n");
	printf("\n\n\n");
}

int main()
{
	int choice = -1;
	ElemType elem;
	LinkList L = NULL;
	LinkList La = NULL, Lb = NULL;

	InitList(&L);
	InitList(&La);
	InitList(&Lb);

	printf("在开始测试前请先创建一个初始表:>");
	CreateListFromHead(L);
	printf("当前表中元素有：");
	PrintList(L);

	while (choice)
	{
		Menu();
		printf("请输入您要测试的功能:>");
		if (!scanf("%d", &choice))
		{
			choice = -1;
			getchar();
		}
		switch (choice)
		{
		case 1:
			DeleteList(L);
			CreateListFromHead(L);
			printf("当前链表中元素为：");
			PrintList(L);
			break;
		case 2:
			PrintList(L);
			break;
		case 3:
			printf("逆置前链表中元素为：");
			PrintList(L);
			ReverseList(&L);
			printf("逆置后链表中元素为：");
			PrintList(L);
			break;
		case 4:
			DeleteList(L);
			NoDecreasingList(L);
			printf("当前链表中元素为：");
			PrintList(L);
			break;
		case 5:
			printf("请输入第一个非递减有序单链表的元素：");
			NoDecreasingList(La);
			printf("第一个非递减有序单链表的元素为：");
			PrintList(La);
			printf("请输入第二个非递减有序单链表的元素：");
			NoDecreasingList(Lb);
			printf("第二个非递减有序单链表的元素为：");
			PrintList(Lb);
			MergeList(La, Lb);
			printf("合并成的非递减链表的元素为：");
			PrintList(La);
			DeleteList(La);
			break;
		case 6:
			ChangeToNoDecreasingList(L);
			printf("非递减有序单链表后的元素为：");
			PrintList(L);
			printf("请输入您要插入的值:>\n");
			scanf("%d", &elem);
			InsNoDecreasing(L, elem);
			printf("插入元素后的表为：");
			PrintList(L);
			break;
		case 7:
			ChangeToNoDecreasingList(L);
			printf("非递减有序单链表后的元素为：");
			PrintList(L);
			printf("请输入您要删除的值:>\n");
			scanf("%d", &elem);
			DeleteFromNoDecreasingList(L, elem);
			printf("删除元素后的表为：");
			PrintList(L);
			break;
		case 8:
			DeleteList(L);
			break;
		case 9:
			printf("%d\n", SizeOfList(L));
			break;
		case 10:
			printf("排序前链表中元素为：");
			PrintList(L);
			ChangeToNoDecreasingList(L);
			printf("排序后链表中元素为：");
			PrintList(L);
			break;
		case 88:
			printf("链表L中元素为：");
			PrintList(L);
			break;
		case 99:
			system("cls");
			break;
		default:
			system("cls");
			printf("您的输入有误！\n");
			break;
		}
	}
	
	system("pause");
	return 0;
}
