#include"LinkList.h"
// 链表初始化
void SListInit(SList* plist)
{
	assert(plist);

	plist->_head = NULL;
}
// 链表销毁
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

// 将数据放入一个结点
SListNode* BuySListNode(SLTDataType val)
{
	SListNode *cur = (SListNode*)malloc(sizeof(SListNode));

	assert(cur);

	cur->_data = val;
	cur->_next = NULL;

	return cur;
}
// 头插法插入数据
void SListPushFront(SList* plist, SLTDataType val)
{
	assert(plist);

	SListNode *cur = (SListNode*)malloc(sizeof(SListNode));

	assert(cur);

	cur->_data = val;
	cur->_next = plist->_head;
	plist->_head = cur;
}
// 头删法删除数据
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
// 在链表中查找数据
SListNode* SListFind(SList* plist, SLTDataType val)
{
	assert(plist);

	SListNode *cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == val)
		{
			return cur;
		}
	}

	return NULL;
}
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType val)
{
	assert(pos);

	SListNode *tmp = (SListNode*)malloc(sizeof(SListNode));

	assert(tmp);

	tmp->_data = val;
	tmp->_next = pos->_next;
	pos->_next = tmp;
}
// 在pos的前面进行插入 
void SListInsertFront(SList* plist, SListNode* pos, SLTDataType val)
{
	assert(plist);

	SListNode *tmp = (SListNode*)malloc(sizeof(SListNode));
	SListNode *cur;

	assert(tmp);

	tmp->_data = val;
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
// 删除pos下一个位置的数据
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
// 删除最先出现的指定数据
void SListRemove(SList* plist, SLTDataType val)
{
	assert(plist);

	SListNode *cur, *tmp;

	for (cur = plist->_head; cur->_next; cur = cur->_next)
	{
		if (cur->_next->_data == val)
		{
			tmp = cur->_next;
			cur->_next = cur->_next->_next;
			free(tmp);
			return;
		}
	}
}
// 链表反转
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
// 判断两链表是否相交
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
// 判断链表是否成环
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
// 找到入环结点
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

// 删除所有指定元素
int RemoveElements(SList* head, int val)
{
	assert(head);

	int count = 0;
	SListNode *cur, *tmp;

	while (head->_head && head->_head->_data == val)
	{
		count++;
		tmp = head->_head;
		head->_head = tmp->_next;
		free(tmp);
	}
	cur = head->_head;
	while (cur)
	{
		if (cur->_next && cur->_next->_data == val)
		{
			count++;
			tmp = cur->_next;
			cur->_next = tmp->_next;
			free(tmp);
		}
		cur = cur->_next;
	}

	return count;
}
// 返回中间结点
SListNode* MiddleNode(SList* head)
{
	assert(head);

	SListNode *cur = head->_head, *next;

	if (!cur)
	{
		return NULL;
	}
	next = cur->_next;
	while (next)
	{
		next = next->_next;
		if (next)
		{
			next = next->_next;
		}
		cur = cur->_next;
	}

	return cur;
}
// 快速排序
void SListQuickSort(SListNode *head)
{
	SListNode *cur, *last, *mid;
	SLTDataType key;

	if (head && head->_next) // 当有两个数据以上时进行
	{
		cur = head->_next;
		mid = cur; // mid 是 key 值的结点
		key = cur->_data;
		if (head->_data > cur->_data) // 确保首数据小于次数据，并始终以次数据为 key 
		{
			key = head->_data;
			head->_data = cur->_data;
			cur->_data = key;
		}
		while (cur->_next)
		{
			last = cur;
			cur = cur->_next;
			if (cur->_data < key) // 将比 key 小的数据都放到 mid 结点的前面
			{
				last->_next = cur->_next;
				cur->_next = head->_next;
				head->_next = cur;
				cur = last;
			}
		}
		SListQuickSort(mid->_next);
		if (head->_next != mid) // 当前半部分只有一个数据时，前半部分不进行快排
		{
			SListQuickSort(head);
		}
	}
}
// 有序链表合并
SListNode* MergeTwoLists(SList* plist1, SList* plist2)
{
	SList head;
	SListNode *cur, *node1, *node2;

	if (!plist1 || !plist1->_head)
	{
		return plist2->_head;
	}
	else if (!plist2 || !plist2->_head)
	{
		return plist1->_head;
	}
	node1 = plist1->_head;
	node2 = plist2->_head;
	plist1->_head = NULL;
	plist2->_head = NULL;

	if (node1->_data < node2->_data)
	{
		head._head = node1;
		node1 = node1->_next;
	}
	else
	{
		head._head = node2;
		node2 = node2->_next;
	}
	cur = head._head;
	while (node1 && node2)
	{
		if (node1->_data < node2->_data)
		{
			cur->_next = node1;
			node1 = node1->_next;
		}
		else
		{
			cur->_next = node2;
			node2 = node2->_next;
		}
		cur = cur->_next;
	}
	if (node1)
	{
		cur->_next = node1;
	}
	else
	{
		cur->_next = node2;
	}

	return head._head;
}
// 链表复制
SListNode* SListClone(SList* plist)
{
	assert(plist);

	SListNode *aim = plist->_head, head, *cur = (SListNode*)malloc(sizeof(SListNode));

	head._next = cur;
	cur->_data = aim->_data;
	while (aim->_next)
	{
		cur->_next = (SListNode*)malloc(sizeof(SListNode));
		cur = cur->_next;
		aim = aim->_next;
		cur->_data = aim->_data;
	}
	cur->_next = NULL;

	return head._next;
}
// 以给定值 val 为基准保留原来的数据顺序将链表分割成两部分
SListNode* SListPartition(SList* plist, int val)
{
	assert(plist);

	SListNode head1, head2; // 带头结点
	SListNode *cur = plist->_head, *before, *after;

	before = &head1;
	after = &head2;
	while (cur)
	{
		if (cur->_data < val)
		{
			before->_next = cur;
			before = before->_next;
		}
		else
		{
			after->_next = cur;
			after = after->_next;
		}
		cur = cur->_next;
	}
	before->_next = head2._next;
	after->_next = NULL;


	return head1._next;
}
// 有序链表中删除重复结点
SListNode* DeleteDuplication(SList* plist)
{
	assert(plist);

	SListNode *cur = plist->_head, *tmp;

	while (cur && cur->_next)
	{
		if (cur->_data == cur->_next->_data)
		{
			tmp = cur->_next;
			cur->_next = tmp->_next;
			free(tmp);
			continue;
		}
		cur = cur->_next;
	}

	return plist->_head;
}
// 回文链表判断
int CheckPalindrome(SList* plist)
{
	assert(plist);

	SList head;
	SListNode *cur = plist->_head, *other;

	head._head = SListClone(plist);
	SListReverse(&head);
	other = head._head;
	while (cur)
	{
		if (cur->_data != other->_data)
		{
			return 0;
		}
		cur = cur->_next;
		other = other->_next;
	}
	
	return 1;
}

// 打印链表
void SListPrint(SList* plist)
{
	assert(plist);

	SListNode *cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%2d -> ", cur->_data);
	}
	printf("NULL\n");
}
// 测试函数
void TestSList()
{
	int ret, val = 9;
	SList test, *pt = &test;
	SList test2, *pt2 = &test2;
	SList test3, *pt3 = &test3;
	SList test4, *pt4 = &test4;

	SListInit(pt);
	SListInit(pt2);
	SListInit(pt3);
	SListInit(pt4);

	SListPushFront(pt, 4);
	SListPushFront(pt, 3);
	SListPushFront(pt, 1);
	SListPushFront(pt, 2);
	SListPushFront(pt, 9);
	SListPushFront(pt, 4);
	SListPushFront(pt, 1);

	SListPrint(pt);
	pt2->_head = SListClone(pt);
	SListPushFront(pt2, -2);
	SListPushFront(pt2, 6);
	pt4->_head = SListClone(pt2);
	SListQuickSort(pt2->_head);
	SListQuickSort(pt->_head);
	printf("pt1 :> ");
	SListPrint(pt);
	printf("pt2 :> ");
	SListPrint(pt2);

	pt3->_head = SListClone(pt);
	pt3->_head = MergeTwoLists(pt2, pt3);
	printf("pt3 :> ");
	SListPrint(pt3);

	DeleteDuplication(pt3);
	printf("pt3 :> ");
	SListPrint(pt3);

	printf("pt4 :> ");
	SListPrint(pt4);
	pt4->_head = SListPartition(pt4, 3);
	printf("pt4 :> ");
	SListPrint(pt4);

	SListPushFront(pt2, 4);
	SListPushFront(pt2, 3);
	SListPushFront(pt2, 1);
	SListPushFront(pt2, 2);
	SListPushFront(pt2, 1);
	SListPushFront(pt2, 3);
	SListPushFront(pt2, 4);
	printf("pt2 :> ");
	SListPrint(pt2);
	if (CheckPalindrome(pt2))
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}

	if (MiddleNode(pt))
	{
		printf("MiddleNode(pt) = %d\n", MiddleNode(pt)->_data);
	}

	ret = RemoveElements(pt, val);
	printf("RemoveElements(pt, %d) = %d\n", val, ret);
	SListPrint(pt);
	if (MiddleNode(pt))
	{
		printf("MiddleNode(pt) = %d\n", MiddleNode(pt)->_data);
	}

	SListPopFront(pt);
	SListPrint(pt);
	SListPopFront(pt);
	SListPrint(pt);

	SListReverse(pt);
	SListPrint(pt);

	SListInsertAfter(SListFind(pt, 3), 0);
	SListPrint(pt);

	SListInsertFront(pt, SListFind(pt, 3), 0);
	SListPrint(pt);

	SListEraseAfter(SListFind(pt, 3));
	SListPrint(pt);

	SListRemove(pt, 0);
	SListPrint(pt);

	//tmp1 = SListFind(pt, 3);
	//tmp1 = pt->_head;
	//tmp2 = SListFind(pt, 9);
	//tmp2->_next = tmp1;
	if (SListHasCycle(pt) > 0)
	{
		printf("yes\n");
		printf("%d\n", (SListDetectCycle(pt))->_data);
	}
	else
		printf("no\n");

	SListReverse(pt);
	//SListPrint(pt);
	//SListPrint(pt2);

	//if (GetIntersectionNode(pt, pt2))
	//{
	//	SListPrint(GetIntersectionNode(pt, pt2));
	//}
	//else
	//{
	//	printf("未相交!\n");
	//}


	SListDestory(pt);
	SListDestory(pt2);
}