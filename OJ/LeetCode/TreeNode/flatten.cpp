#include "Leetcode.h"

/*
 *
 *	114. 二叉树展开为链表
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了75.53%的用户
 *  	内存消耗:		9.9 MB, 在所有 C++ 提交中击败了13.20%的用户
 *
 */
void flatten(TreeNode* root)
{
	TreeNode *cur = root, *tmp;
	if (cur)
	{
		if (cur->left)
			flatten(cur->left);
		if (cur->right)
			flatten(cur->right);
		tmp = cur->left;
		if (tmp)
		{
			while (tmp->right)
				tmp = tmp->right;
			tmp->right = cur->right;
			cur->right = cur->left;
		}
		cur->left = nullptr;
	}
}