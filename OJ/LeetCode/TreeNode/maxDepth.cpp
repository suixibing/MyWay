#include "Leetcode.h"

/*
 *
 *	104. 二叉树的最大深度
 *
 *  	执行用时:		20 ms, 在所有 C++ 提交中击败了31.92%的用户
 *  	内存消耗:		19 MB, 在所有 C++ 提交中击败了94.16%的用户
 *
 */
int maxDepth(TreeNode* root)
{
	if (!root)
		return 0;
	int res1 = maxDepth(root->left), res2 = maxDepth(root->right);
	return res1 > res2 ? res1 + 1 : res2 + 1;
}