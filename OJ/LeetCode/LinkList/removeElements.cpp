#include "Leetcode.h"

/*
 *
 *	203. 移除链表元素
 *
 *  	执行用时:		32 ms, 在所有 C++ 提交中击败了84.96%的用户
 *  	内存消耗:		11.2 MB, 在所有 C++ 提交中击败了56.68%的用户
 *
 */
ListNode* removeElements(ListNode* head, int val)
{
	ListNode *cur = head, *tmp;
	while (cur && cur->val == val)
	{
		cur = cur->next;
		delete head;
		head = cur;
	}
	while (cur && cur->next)
	{
		if (cur->next->val == val)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			delete tmp;
		}
		else
			cur = cur->next;
	}
	return head;
}