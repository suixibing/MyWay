#include "Leetcode.h"

/*
 *
 *	107. 二叉树的层次遍历 II
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了66.48%的用户
 *  	内存消耗:		13.8 MB, 在所有 C++ 提交中击败了73.60%的用户
 *
 */
vector< vector<int> > levelOrderBottom(TreeNode* root)
{
	TreeNode* cur;
	vector<TreeNode*> que;
	vector<int> floor;
	vector< vector<int> > res;
	int left = 0, right = 1, flag = 1;
	que.push_back(root);
	while (left < right)
	{
		cur = que[left++];
		if (cur)
		{
			floor.push_back(cur->val);
			que.push_back(cur->left);
			que.push_back(cur->right);
			right += 2;
		}
		if (left == flag && !floor.empty())
		{
			res.insert(res.begin(), floor);
			floor.clear();
			flag = right;
		}
	}
	return res;
}