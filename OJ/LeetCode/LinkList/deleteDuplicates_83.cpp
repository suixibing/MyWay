#include "Leetcode.h"

/*
 *
 *	83. 删除排序链表中的重复元素
 *
 *  	执行用时 :		12 ms, 在所有 C++ 提交中击败了96.17%的用户
 *  	内存消耗 :		9.1 MB, 在所有 C++ 提交中击败了66.01%的用户
 *
 */
ListNode* deleteDuplicates_83(ListNode* head)
{
	ListNode *cur, *tmp;
	for (cur = head; cur; cur = cur->next)
	{
		while (cur->next && cur->val == cur->next->val)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			delete tmp;
		}
	}
	return head;
}