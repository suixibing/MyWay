#include "Leetcode.h"

/*
 *
 *	102. 二叉树的层次遍历
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了73.60%的用户
 *  	内存消耗:		14.7 MB, 在所有 C++ 提交中击败了18.20%的用户
 *
 */
vector< vector<int> > levelOrder(TreeNode* root)
{
	vector<int> tmp;
	TreeNode *cur = root;
	queue<TreeNode*> q, qtmp, qclear;
	vector< vector<int> > res;
	if (root)
		q.push(root);
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur)
		{
			tmp.push_back(cur->val);
			if (cur->left)
				qtmp.push(cur->left);
			if (cur->right)
				qtmp.push(cur->right);
		}
		if (q.empty())
		{
			res.push_back(tmp);
			q = qtmp;
			qtmp = qclear;
			tmp.clear();
		}
	}
	return res;
}