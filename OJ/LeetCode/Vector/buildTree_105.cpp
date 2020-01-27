#include "Leetcode.h"

/*
 *
 *	105. 从前序与中序遍历序列构造二叉树
 *
 *  	执行用时:		60 ms, 在所有 C++ 提交中击败了23.81%的用户
 *  	内存消耗:		77.4 MB, 在所有 C++ 提交中击败了25.72%的用户
 *
 */
TreeNode* buildTree_105(vector<int>& preorder, vector<int>& inorder)
{
	TreeNode *root = nullptr;
	for (int i = 0; i < preorder.size(); ++i)
	{
		for (int j = 0; j < inorder.size(); ++j)
		{
			if (preorder[i] == inorder[j])
			{
				root = new TreeNode(preorder[i]);
				vector<int> newpre(preorder.begin() + i + 1, preorder.end());
				vector<int> newin1(inorder.begin(), inorder.begin() + j);
				root->left = buildTree(newpre, newin1);
				vector<int> newin2(inorder.begin() + j + 1, inorder.end());
				root->right = buildTree(newpre, newin2);
				return root;
			}
		}
	}
	return root;
}