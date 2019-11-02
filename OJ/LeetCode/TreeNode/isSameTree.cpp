#include "Leetcode.h"

/*
 *
 *	100. 相同的树
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了78.15%的用户
 *  	内存消耗:		9.9 MB, 在所有 C++ 提交中击败了74.73%的用户
 *
 */
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p && q)
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
	else if (p || q)
		return false;
	else
		return true;
}