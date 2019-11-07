#include "Leetcode.h"

/*
 *
 *	82. 删除排序链表中的重复元素 II
 *
 *  	执行用时 :		12 ms, 在所有 C++ 提交中击败了77.47%的用户
 *  	内存消耗 :		9.3 MB, 在所有 C++ 提交中击败了7.32%的用户
 *
 */
ListNode* deleteDuplicates_82(ListNode* head)
{
	int flag;
	ListNode *cur = head, *tmp, tmphead(0);
	tmphead.next = head;

	cur = &tmphead;
	while (cur->next && cur->next->next)
	{
		flag = 0;
		while (cur->next && cur->next->next && cur->next->val == cur->next->next->val)
		{
			flag = 1;
			tmp = cur->next->next;
			cur->next->next = tmp->next;
			delete tmp;
		}
		if (flag)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			delete tmp;
		}
		else
			cur = cur->next;
	}
	return tmphead.next;
}