#include "Leetcode.h"

/*
 *
 *	19. 删除链表的倒数第N个节点
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了78.45%的用户
 *  	内存消耗:		8.5 MB, 在所有 C++ 提交中击败了83.54%的用户
 *
 */
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode *tmp = head, *cur = head, *last = head;
	if (n <= 0)
		return NULL;
	while (n--)
	{
		if (!tmp->next && n > 0)
			return NULL;
		tmp = tmp->next;
	}
	while (tmp)
	{
		last = cur;
		tmp = tmp->next;
		cur = cur->next;
	}
	if (cur == head)
		head = head->next;
	else
		last->next = cur->next;
	delete cur;
	return head;
}