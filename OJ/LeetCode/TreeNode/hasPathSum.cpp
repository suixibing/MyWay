#include "Leetcode.h"

/*
 *
 *	112. 路径总和
 *
 *  	执行用时:		24 ms, 在所有 C++ 提交中击败了27.34%的用户
 *  	内存消耗:		19.7 MB, 在所有 C++ 提交中击败了80.69%的用户
 *
 */
bool hasPathSum(TreeNode* root, int sum)
{
	if (!root)
		return false;
	if (!root->left && !root->right && root->val == sum)
		return true;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}