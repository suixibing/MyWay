#include"LinkList.h"
//链表初始化
void SListInit(SList* plist)
{
	assert(plist);

	plist->_head = NULL;
}
//链表销毁
void SListDestory(SList* plist)
{
	assert(plist);

	SListNode *tmp;

	while (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
	plist->_head = NULL;
}

//将数据放入一个结点
SListNode* BuySListNode(SLTDataType x)
{
	SListNode *cur = (SListNode*)malloc(sizeof(SListNode));

	assert(cur);

	cur->_data = x;
	cur->_next = NULL;

	return cur;
}
// 头插法插入数据
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode *cur = (SListNode*)malloc(sizeof(SListNode));

	assert(cur);

	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}
//头删法删除数据
void SListPopFront(SList* plist)
{
	assert(plist);

	SListNode *tmp = plist->_head;

	if (plist->_head)
	{
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
//在链表中查找数据
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode *cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}

	return NULL;
}
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);

	SListNode *tmp = (SListNode*)malloc(sizeof(SListNode));

	assert(tmp);

	tmp->_data = x;
	tmp->_next = pos->_next;
	pos->_next = tmp;
}
// 在pos的前面进行插入 
void SListInsertFront(SList* plist, SListNode* pos, SLTDataType x)
{
	assert(plist);

	SListNode *tmp = (SListNode*)malloc(sizeof(SListNode));
	SListNode *cur;

	assert(tmp);

	tmp->_data = x;
	if (plist->_head == pos)
	{
		tmp->_next = plist->_head;
		plist->_head = tmp;
		return;
	}
	for (cur = plist->_head; cur->_next; cur = cur->_next)
	{
		if (cur->_next == pos)
		{
			tmp->_next = cur->_next;
			cur->_next = tmp;
			return;
		}
	}
}
//删除pos下一个位置的数据
void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	SListNode *tmp = pos->_next;

	if (pos->_next)
	{
		pos->_next = pos->_next->_next;
		free(tmp);
	}
}
//删除最先出现的指定数据
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode *cur, *tmp;

	for (cur = plist->_head; cur->_next; cur = cur->_next)
	{
		if (cur->_next->_data == x)
		{
			tmp = cur->_next;
			cur->_next = cur->_next->_next;
			free(tmp);
			return;
		}
	}
}

//打印链表
void SListPrint(SList* plist)
{
	assert(plist);

	SListNode *cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}
void TestSList()
{

}
//链表反转
void SListReverse(SList* plist)
{
	assert(plist);

#if 0

	SListNode *tmp, *cur = plist->_head;

	while (cur->_next)
	{
		tmp = cur->_next;
		cur->_next = tmp->_next;
		tmp->_next = plist->_head;
		plist->_head = tmp;
	}

#elif 1

	SListNode *cur = plist->_head;
	SListNode *tmp;

	if (cur)
	{
		tmp = cur->_next;
		cur->_next = NULL;
		while (tmp)
		{
			plist->_head = tmp;
			tmp = tmp->_next;
			plist->_head->_next = cur;
			cur = plist->_head;
		}
	}

#else

	SList *newhead = (SList*)malloc(sizeof(SList));
	SListNode *cur;

	SListInit(newhead);
	
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		SListPushFront(newhead, cur->_data);
	}
	SListDestory(plist);
	plist->_head = newhead->_head;

	free(newhead);

#endif
}
//判断两链表是否相交
SListNode* GetIntersectionNode(SList* listA, SList* listB)
{
	assert(listA);
	assert(listB);

	int lenA = 0, lenB = 0, i, gap;
	SListNode *cur, *headlong = listA->_head, *headshort = listB->_head;

	for (cur = listA->_head; cur; cur = cur->_next)
	{
		lenA++;
	}
	for (cur = listB->_head; cur; cur = cur->_next)
	{
		lenB++;
	}
	gap = lenA - lenB;
	if (gap < 0)
	{
		gap *= -1;
		headshort = listA->_head;
		headlong = listB->_head;
	}
	for (i = 0; i < gap; i++)
	{
		headlong = headlong->_next;
	}
	for (; headlong; headlong = headlong->_next, headshort = headshort->_next)
	{
		if (headlong == headshort)
		{
			return headlong;
		}
	}

	return NULL;
}
//判断链表是否成环
int SListHasCycle(SList* plist)
{
	assert(plist);

	SListNode *slow = plist->_head, *fast = plist->_head->_next;

	while (slow && fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast)
		{
			return 1;
		}
	}

	return -1;
}
//找到入环结点
SListNode* SListDetectCycle(SList* plist)
{
	assert(plist);

	SListNode *cur = plist->_head;
	SListNode *slow = plist->_head, *fast = plist->_head->_next;

	while (slow && fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast)
		{
			slow = slow->_next;
			while (cur != slow)
			{
				cur = cur->_next;
				slow = slow->_next;
			}
			return cur;
		}
	}

	return NULL;
}