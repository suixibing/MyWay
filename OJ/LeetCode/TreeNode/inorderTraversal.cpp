#include "Leetcode.h"

/*
 *
 *	94. 二叉树的中序遍历
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		9.1 MB, 在所有 C++ 提交中击败了69.40%的用户
 *
 */
vector<int> inorderTraversal(TreeNode* root)
{
	TreeNode* cur = root;
	stack<TreeNode*> st;
	vector<int> res;
	while (cur)
	{
		st.push(cur);
		cur = cur->left;
	}
	while (!st.empty())
	{
		cur = st.top();
		st.pop();
		res.push_back(cur->val);
		if (cur->right)
		{
			cur = cur->right;
			while (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
		}
	}
	return res;
}