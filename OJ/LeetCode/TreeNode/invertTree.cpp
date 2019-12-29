#include "Leetcode.h"

/*
 *
 *	226. 翻转二叉树
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了72.72%的用户
 *  	内存消耗:		9.1 MB, 在所有 C++ 提交中击败了48.29%的用户
 *
 */
TreeNode* invertTree(TreeNode* root)
{
	if (root)
	{
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
	}
	return root;
}