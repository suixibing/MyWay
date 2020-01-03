#include "Leetcode.h"

/*
 *
 *	237. 删除链表中的节点
 *
 *  	执行用时 :		16 ms, 在所有 C++ 提交中击败了71.68%的用户
 *  	内存消耗 :		9.2 MB, 在所有 C++ 提交中击败了50.13%的用户
 *
 */
void deleteNode(ListNode* node)
{
	*node = *(node->next);
}