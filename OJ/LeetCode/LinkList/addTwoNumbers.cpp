#include "Leetcode.h"

/*
 *
 *	2. 两数相加
 *
 *  	执行用时 :		24 ms, 在所有 C++ 提交中击败了98.61%的用户
 *  	内存消耗 :		10.4 MB, 在所有 C++ 提交中击败了79.09%的用户
 *
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int val = l1->val + l2->val;
	ListNode *t, *res, *head = new ListNode(val % 10);
	res = head;
	while (l1->next && l2->next)
	{
		l1 = l1->next;
		l2 = l2->next;
		val = val / 10 + l1->val + l2->val;
		res->next = new ListNode(val % 10);
		res = res->next;
	}
	t = l1->next ? l1 : l2;
	while (t->next)
	{
		t = t->next;
		val = val / 10 + t->val;
		res->next = new ListNode(val % 10);
		res = res->next;
	}
	if (val > 9)
	{
		res->next = new ListNode(1);
	}
	return head;
}
