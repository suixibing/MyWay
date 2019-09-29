#include "Leetcode.h"

/*
 *
 *	21. 合并两个有序链表
 *
 *  	执行用时 :		12 ms, 在所有 C++ 提交中击败了83.26%的用户
 *  	内存消耗 :		8.9 MB, 在所有 C++ 提交中击败了80.41%的用户
 *
 */
ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2)
{
	if (!l1)
		return l2;
	else if (!l2)
		return l1;
	ListNode *head = l1->val < l2->val ? l1 : l2;
	ListNode *cur = head;
	if (head == l1)
		l1 = l1->next;
	else
		l2 = l2->next;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			cur->next = l1;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	cur->next = l1 ? l1 : l2;
	return head;
}

/*
 *
 *	21. 合并两个有序链表
 *
 *  	执行用时 :		12 ms, 在所有 C++ 提交中击败了83.03%的用户
 *  	内存消耗 :		9 MB, 在所有 C++ 提交中击败了76.64%的用户
 *
 */
ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2)
{
	if (!l1)
		return l2;
	else if (!l2)
		return l1;
	if (l1->val < l2->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	return mergeTwoLists1(l1, l2);
}
