#include "Leetcode.h"

/*
 *
 *	25. K 个一组翻转链表
 *
 *  	执行用时:		24 ms, 在所有 C++ 提交中击败了95.86%的用户
 *  	内存消耗:		9.7 MB, 在所有 C++ 提交中击败了86.99%的用户
 *
 */
ListNode* reverseKGroup(ListNode* head, int k)
{
	int i, count = 0;
	ListNode *tmp, *cur = head, newhead(0);
	newhead.next = head;
	while (cur)
	{
		++count;
		cur = cur->next;
	}
	count = (count / k) * (k - 1);
	head = &newhead;
	tmp = head;
	for (i = 0; i < count; i++)
	{
		if (i % (k - 1) == 0)
		{
			head = tmp;
			tmp = tmp->next;
		}
		cur = tmp->next;
		tmp->next = cur->next;
		cur->next = head->next;
		head->next = cur;
	}
	return newhead.next;
}
