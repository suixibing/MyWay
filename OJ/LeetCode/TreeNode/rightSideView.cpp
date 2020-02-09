#include "Leetcode.h"

/*
 *
 *	199. 二叉树的右视图
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了87.15%的用户
 *  	内存消耗:		10 MB, 在所有 C++ 提交中击败了5.63%的用户
 *
 */
vector<int> rightSideView(TreeNode* root)
{
	if (!root)
		return vector<int>();
	int i, size;
	TreeNode *cur;
	vector<int> ret(1, root->val);
	vector<TreeNode*> s1(1, root), s2;
	while (s1.size())
	{
		size = s1.size();
		for (i = 0; i < size; ++i)
		{
			if (s1[i]->left)
				s2.push_back(s1[i]->left);
			if (s1[i]->right)
				s2.push_back(s1[i]->right);
		}
		if (s2.size())
			ret.push_back(s2[s2.size() - 1]->val);
		s1 = s2;
		s2.clear();
	}
	return ret;
}