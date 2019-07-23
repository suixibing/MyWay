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
			cur->_next = tmp->_next;
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

	SListNode *tmp, *cur = plist->_head; // 一个一个结点的插入开头

	while (cur->_next) // 存在要插入的结点
	{
		tmp = cur->_next; // 将 tmp 指向要插入的结点
		cur->_next = tmp->_next; // 从链表中移除要插入的结点
		tmp->_next = plist->_head; // 将要插入的结点放到链表的开头
		plist->_head = tmp; // 将链表指向首结点
	}

#elif 1

	SListNode *cur = plist->_head;
	SListNode *tmp;

	if (cur)
	{
		tmp = cur->_next; // 将 tmp 指向剩余未处理的结点
		cur->_next = NULL; // cur 将首结点取出
		while (tmp) // tmp 存在新的首结点
		{
			plist->_head = tmp; // 将链表指向新的首结点
			tmp = tmp->_next; // 将 tmp 指向剩余未处理的结点
			plist->_head->_next = cur; // 将新首结点与原首结点连接
			cur = plist->_head; // 将 cur 指向现在的首结点
		}
	}

#else

	SList *newhead = (SList*)malloc(sizeof(SList)); // 创建一个新的头指针
	SListNode *cur;

	SListInit(newhead); // 初始化新链表
	
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		SListPushFront(newhead, cur->_data); // 将旧链表逆序存入新链表
	}
	SListDestory(plist); // 销毁旧链表
	plist->_head = newhead->_head; // 将旧链表头指针指向新链表的首结点

	free(newhead); // 释放新链表的头指针

#endif
}
// 判断两链表是否相交，返回相交结点
SListNode* GetIntersectionNode(SList* listA, SList* listB)
{
	assert(listA);
	assert(listB);

	int lenA = 0, lenB = 0, i, gap;
	SListNode *cur, *headlong = listA->_head, *headshort = listB->_head; //默认链表A的长度大于等于链表B的长度

	for (cur = listA->_head; cur; cur = cur->_next) // 求链表A的长度
	{
		lenA++;
	}
	for (cur = listB->_head; cur; cur = cur->_next) // 求链表B的长度
	{
		lenB++;
	}
	gap = lenA - lenB; // 求链表A和链表B的长度差
	if (gap < 0) // headlong 永远指向较长的链表
	{
		gap *= -1;
		headshort = listA->_head;
		headlong = listB->_head;
	}
	for (i = 0; i < gap; i++) // 跳过长链表必然不相交的部分，使两链表的长度相同
	{
		headlong = headlong->_next;
	}
	for (; headlong; headlong = headlong->_next, headshort = headshort->_next)
	{
		if (headlong == headshort) // 两等长链表相交的条件
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
		slow = slow->_next; // slow 每次向后移动一个结点
		fast = fast->_next->_next; // fast 每次向后移动两个结点
		if (slow == fast) // 如果两指针相交说明链表成环
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
	SListNode *slow = plist->_head, *fast = plist->_head;

	while (slow && fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast) // 找到相遇结点
		{
			while (cur != slow) // 相遇结点到相交结点的结点数等于起始结点到相交结点的结点数
			{
				cur = cur->_next;
				slow = slow->_next;
			}
			return cur;
		}
	}

	return NULL;
}

// 删除所有指定数据，返回删除数据的个数
int RemoveElements(SList* head, int val)
{
	assert(head);

	int count = 0;
	SListNode h, *cur = &h, *tmp;

	cur->_next = head->_head;
	while (head->_head && head->_head->_data == val) // 将链表的头指针指向首个不为指定值的结点
	{
		head->_head = head->_head->_next;
	}
	while (cur)
	{
		if (cur->_next && cur->_next->_data == val) // 当下一结点为指定值时，计数并删除下一结点
		{
			count++;
			tmp = cur->_next;
			cur->_next = tmp->_next;
			free(tmp);
			continue;
		}
		cur = cur->_next;
	}

	return count;
}
// 返回中间结点(偶数个结点时为偏右结点)
SListNode* MiddleNode(SList* head)
{
	assert(head);

	SListNode *cur = head->_head, *next;

	if (!cur) // 当为空链时，返回 NULL
	{
		return NULL;
	}
	next = cur->_next; // 这里若为 next = cur; 则偶数个结点时为偏左结点
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
	SListNode *l1 = plist1->_head, *l2 = plist2->_head, *cur;

	plist1->_head = plist2->_head = NULL;
	if (l1 && l2 && l1->_data < l2->_data || l1 && !l2) // 当两链表都存在或只有链表1存在时，新链表以链表1为首结点
	{
		head._head = l1;
		l1 = l1->_next;
	}
	else if (l2) // 当只有链表2存在时，新链表以链表2为首结点
	{
		head._head = l2;
		l2 = l2->_next;
	}
	else // 当两链表都不存在时，没有首结点
	{
		head._head = NULL;
	}
	cur = head._head;
	while (l1 && l2) // 当两链表都存在时的操作
	{
		if (l1->_data < l2->_data)
		{
			cur->_next = l1;
			l1 = l1->_next;
		}
		else
		{
			cur->_next = l2;
			l2 = l2->_next;
		}
		cur = cur->_next;
	}
	if (l1) // 这里会处理之前未处理的结点
	{
		cur->_next = l1;
	}
	else if (l2)
	{
		cur->_next = l2;
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
	SListNode *cur = plist->_head, *before= &head1, *after = &head2;

	while (cur)
	{
		if (cur->_data < val) // 小于基准值的部分
		{
			before->_next = cur;
			before = before->_next;
		}
		else // 大于基准值的部分
		{
			after->_next = cur;
			after = after->_next;
		}
		cur = cur->_next;
	}
	before->_next = head2._next; // 连接两部分构成一个链表
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

	int flag = 1;
	SList head;
	SListNode *cur = plist->_head, *other;

	head._head = SListClone(plist); // 复制出一个新链表
	SListReverse(&head); // 将新链表逆序
	other = head._head;
	while (cur)
	{
		if (cur->_data != other->_data) // 当逆序后的链表和原链表不同时，原链表不是回文链表
		{
			flag = 0;
			break;
		}
		cur = cur->_next;
		other = other->_next;
	}
	SListDestory(&head); // 销毁逆序后的链表
	
	return flag;
}
// 两数相加， 链表数据按照数字的每一位的倒序来存储
SListNode* AddTwoNumbers(SList* plist1, SList* plist2) 
{
	assert(plist1);
	assert(plist2);

	int flag = 0; // flag 为进位
	SListNode head, *l1 = plist1->_head, *l2 = plist2->_head, *l3 = &head;

	while (l1 || l2 || flag) // 当存在下一位时进行循环
	{
		l3->_next = (SListNode*)malloc(sizeof(SListNode));
		l3 = l3->_next;
		l3->_data = flag;
		flag = 0;
		if (l1)
		{
			l3->_data += l1->_data;
			l1 = l1->_next;
		}
		if (l2)
		{
			l3->_data += l2->_data;
			l2 = l2->_next;
		}
		if (l3->_data > 9)
		{
			flag = 1;
			l3->_data -= 10;
		}
	}
	l3->_next = NULL;

	return head._next;
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
	SList test5, *pt5 = &test5;
	SListNode *tmp1, *tmp2;

	SListInit(pt);
	SListInit(pt2);
	SListInit(pt3);
	SListInit(pt4);
	SListInit(pt5);

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

	SListPushFront(pt2, 9);
	SListPushFront(pt2, 3);
	SListPushFront(pt2, 1);
	SListPushFront(pt2, 2);
	SListPushFront(pt2, 1);
	SListPushFront(pt2, 3);
	SListPushFront(pt2, 9);
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

	printf("pt1 :> ");
	SListPrint(pt);
	ret = RemoveElements(pt, 9);
	printf("RemoveElements(pt, %d) = %d\n", 9, ret);
	SListPrint(pt);
	if (MiddleNode(pt))
	{
		printf("MiddleNode(pt) = %d\n", MiddleNode(pt)->_data);
	}

	printf("pt1 :> ");
	SListPrint(pt);
	printf("pt2 :> ");
	SListPrint(pt2);
	printf("pt3 :> ");
	SListPrint(pt3);
	printf("pt4 :> ");
	SListPrint(pt4);

	pt5->_head = AddTwoNumbers(pt, pt2);
	printf("pt5 :> ");
	SListPrint(pt5);

	SListPopFront(pt);
	printf("pt1 :> ");
	SListPrint(pt);
	SListPopFront(pt);
	printf("pt1 :> ");
	SListPrint(pt);

	SListReverse(pt);
	printf("pt1 :> ");
	SListPrint(pt);

	SListInsertAfter(SListFind(pt, 3), 0);
	printf("pt1 :> ");
	SListPrint(pt);

	SListInsertFront(pt, SListFind(pt, 3), 0);
	printf("pt1 :> ");
	SListPrint(pt);

	SListEraseAfter(SListFind(pt, 3));
	printf("pt1 :> ");
	SListPrint(pt);

	SListRemove(pt, 0);
	printf("pt1 :> ");
	SListPrint(pt);

	tmp1 = SListFind(pt5, 3);
	//tmp1 = pt5->_head;
	tmp2 = SListFind(pt5, 9);
	tmp2->_next = tmp1;
	if (SListHasCycle(pt5) > 0)
	{
		printf("yes\n");
		printf("%d\n", (SListDetectCycle(pt5))->_data);
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
	SListDestory(pt3);
	SListDestory(pt4);
	//SListDestory(pt5);
}