#include "Leetcode.h"

/*
 *
 *	61. 旋转链表
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了81.10%的用户
 *  	内存消耗:		8.8 MB, 在所有 C++ 提交中击败了93.11%的用户
 *
 */
ListNode* rotateRight(ListNode* head, int k)
{
	int count = 0;
	ListNode *cur = head, *tmp;
	for (cur = head; cur; cur = cur->next)
		++count;
	if (count == 0 || !(k % count))
		return head;
	k = k % count;
	if (k > 1)
		head = rotateRight(head, k - 1);
	for (cur = head; cur && cur->next && cur->next->next; )
		cur = cur->next;
	if (cur && cur->next)
	{
		tmp = cur->next;
		cur->next = NULL;
		tmp->next = head;
		head = tmp;
	}
	return head;
}