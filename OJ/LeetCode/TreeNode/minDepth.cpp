#include "Leetcode.h"

/*
 *
 *	111. 二叉树的最小深度
 *
 *  	执行用时:		16 ms, 在所有 C++ 提交中击败了74.21%的用户
 *  	内存消耗:		19.6 MB, 在所有 C++ 提交中击败了77.81%的用户
 *
 */
int minDepth(TreeNode* root)
{
	if (!root)
		return 0;
	int left = minDepth(root->left), right = minDepth(root->right);
	return (left && right) ? min(left, right) + 1 : left + right + 1;
}