#include "Leetcode.h"

/*
 *
 *	101. 对称二叉树
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了71.89%的用户
 *  	内存消耗:		14.7 MB, 在所有 C++ 提交中击败了89.46%的用户
 *
 */
bool isSymmetric(TreeNode* root)
{
	if (root == NULL)
		return true;
	if (root->left != NULL && root->right != NULL)
	{
		if (root->left->val == root->right->val)
		{
			TreeNode tmp1(0), tmp2(0);
			tmp1.left = root->left->left;
			tmp1.right = root->right->right;
			tmp2.left = root->left->right;
			tmp2.right = root->right->left;
			return isSymmetric(&tmp1) && isSymmetric(&tmp2);
		}
		else
			return false;
	}
	else if (root->left == NULL && root->right == NULL)
		return true;
	else
		return false;
}