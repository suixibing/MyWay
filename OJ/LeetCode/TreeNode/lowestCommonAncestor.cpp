#include "Leetcode.h"

/*
 *
 *	235. 二叉搜索树的最近公共祖先
 *
 *  	执行用时:		40 ms, 在所有 C++ 提交中击败了72.39%的用户
 *  	内存消耗:		25.5 MB, 在所有 C++ 提交中击败了99.62%的用户
 *
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	TreeNode *cur = root;
	while (cur)
	{
		if (cur->val > p->val && cur->val > q->val)
			cur = cur->left;
		else if (cur->val < p->val && cur->val < q->val)
			cur = cur->right;
		else
			break;
	}
	return cur;
}