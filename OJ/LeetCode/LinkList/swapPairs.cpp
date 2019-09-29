#include "Leetcode.h"

/*
 *
 *	24. 两两交换链表中的节点
 *
 *  	执行用时 :		8 ms, 在所有 C++ 提交中击败了55.66%的用户
 *  	内存消耗 :		8.7 MB, 在所有 C++ 提交中击败了71.16%的用户
 *
 */
ListNode* swapPairs1(ListNode* head) 
{
	if (!head || !head->next)
		return head;
	ListNode *res = head->next;
	head->next = res->next;
	res->next = head;
	res->next->next = swapPairs(res->next->next);
	return res;
}

/*
 *
 *	24. 两两交换链表中的节点
 *
 *  	执行用时 :		8 ms, 在所有 C++ 提交中击败了55.39%的用户
 *  	内存消耗 :		8.5 MB, 在所有 C++ 提交中击败了91.10%的用户
 *
 */
ListNode* swapPairs2(ListNode* head) 
{
	if (!head || !head->next)
		return head;
	ListNode *res = head->next;
	head->next = swapPairs(res->next);
	res->next = head;
	return res;
}

/*
 *
 *	24. 两两交换链表中的节点
 *
 *  	执行用时 :		4 ms, 在所有 C++ 提交中击败了90.26%的用户
 *  	内存消耗 :		8.5 MB, 在所有 C++ 提交中击败了92.04%的用户
 *
 */
ListNode* swapPairs3(ListNode* head) 
{
	if (!head || !head->next)
		return head;
	ListNode *tmp = head->next, *cur = head;
	head = tmp;
	tmp = tmp->next;
	cur->next = tmp;
	head->next = cur;
	while (tmp && tmp->next)
	{
		cur->next = tmp->next;
		tmp->next = tmp->next->next;
		cur->next->next = tmp;
		cur = tmp;
		tmp = tmp->next;
	}
	return head;
}

ListNode* swapPairs(ListNode* head)
{
	return swapPairs1(head);
}