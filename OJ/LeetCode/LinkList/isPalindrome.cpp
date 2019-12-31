#include "Leetcode.h"

/*
 *
 *	234. 回文链表
 *
 *  	执行用时 :		24 ms, 在所有 C++ 提交中击败了69.62%的用户
 *  	内存消耗 :		13.2 MB, 在所有 C++ 提交中击败了24.59%的用户
 *
 */
bool isPalindrome(ListNode* head)
{
	int tmp;
	stack<int> s;
	ListNode* cur;
	for (cur = head; cur; cur = cur->next)
		s.push(cur->val);
	for (cur = head; cur; cur = cur->next)
	{
		tmp = s.top();
		s.pop();
		if (tmp != cur->val)
			return false;
	}
	return true;
}