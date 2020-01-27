#include "Leetcode.h"

/*
 *
 *	106. 从中序与后序遍历序列构造二叉树
 *
 *  	执行用时:		72 ms, 在所有 C++ 提交中击败了18.58%的用户
 *  	内存消耗:		76.9 MB, 在所有 C++ 提交中击败了22.81%的用户
 *
 */
TreeNode* buildTree_106(vector<int>& inorder, vector<int>& postorder)
{
	TreeNode *root = nullptr;
	for (int i = postorder.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < inorder.size(); ++j)
		{
			if (inorder[j] == postorder[i])
			{
				root = new TreeNode(postorder[i]);
				vector<int> newpost(postorder.begin(), postorder.begin() + i);
				vector<int> newin1(inorder.begin(), inorder.begin() + j);
				root->left = buildTree(newin1, newpost);
				vector<int> newin2(inorder.begin() + j + 1, inorder.end());
				root->right = buildTree(newin2, newpost);
				return root;
			}
		}
	}
	return root;
}