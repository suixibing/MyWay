#include "Leetcode.h"

/*
 *
 *	86. 分隔链表
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了54.35%的用户
 *  	内存消耗:		8.5 MB, 在所有 C++ 提交中击败了92.44%的用户
 *
 */
ListNode* partition(ListNode* head, int x)
{
	if (!head || !head->next)
		return head;
	ListNode *left = nullptr, *right = nullptr, *cur, *tmp;
	for (cur = head; cur; cur = cur->next)
	{
		if (cur->val >= x)
		{
			right = cur;
			break;
		}
		else
			left = cur;
	}
	if (right == head)
	{
		for (cur = head; cur->next; cur = cur->next)
		{
			if (cur->next->val < x)
			{
				left = cur->next;
				cur->next = left->next;
				left->next = head;
				head = left;
				break;
			}
		}
	}
	while (cur && cur->next)
	{
		if (cur->next->val < x)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = left->next;
			left->next = tmp;
			left = tmp;
		}
		else
			cur = cur->next;
	}
	return head;
}