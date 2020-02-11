#include "Leetcode.h"

/*
 *
 *	142. 环形链表 II
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了97.50%的用户
 *  	内存消耗:		10.1 MB, 在所有 C++ 提交中击败了23.56%的用户
 *
 */
ListNode *detectCycle(ListNode *head)
{
	if (head && head->next)
	{
		ListNode *cur = head->next, *cur2 = head->next->next;
		while (cur && cur2)
		{
			if (cur == cur2)
			{
				for (cur2 = head; cur != cur2; cur2 = cur2->next)
					cur = cur->next;
				return cur;
			}
			cur = cur->next;
			if (!cur2->next || cur2->next && !cur2->next->next)
				break;
			cur2 = cur2->next->next;
		}
	}
	return nullptr;
}