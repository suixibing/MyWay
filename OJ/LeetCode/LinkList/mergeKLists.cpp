#include "Leetcode.h"

/*
 *
 *	23. 合并K个排序链表
 *
 *  	执行用时 :		164 ms, 在所有 C++ 提交中击败了31.54%的用户
 *  	内存消耗 :		10.7 MB, 在所有 C++ 提交中击败了98.28%的用户
 *
 */
ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	int i = 1, size = lists.size();
	if (size == 2)
		return mergeTwoLists(lists[0], lists[1]);
	if (size == 1)
		return lists[0];
	else if (size == 0)
		return NULL;
	while (i < size)
	{
		lists[i] = mergeTwoLists(lists[i - 1], lists[i]);
		++i;
	}
	return lists[size - 1];
}