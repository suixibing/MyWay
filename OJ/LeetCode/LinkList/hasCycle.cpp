#include "Leetcode.h"

/*
 *
 *	141. 环形链表
 *
 *  	执行用时 :		8 ms, 在所有 C++ 提交中击败了98.37%的用户
 *  	内存消耗 :		9.7 MB, 在所有 C++ 提交中击败了61.40%的用户
 *
 */
bool hasCycle(ListNode *head)
{
	ListNode *cur = head;
	ListNode *next = head;
	while (next)
	{
		cur = cur->next;
		next = next->next;
		if (next)
			next = next->next;
		if (cur == next && next != NULL)
			return true;
	}
	return false;
}