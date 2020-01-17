#include "Leetcode.h"

/*
 *
 *	129. 求根到叶子节点数字之和
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了85.42%的用户
 *  	内存消耗:		12.7 MB, 在所有 C++ 提交中击败了16.00%的用户
 *
 */
int sumNumbers(TreeNode* root)
{
	int res = 0;
	queue<TreeNode*> q;
	TreeNode *cur = root;
	if (cur)
		q.push(cur);
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (!cur->left && !cur->right)
			res += cur->val;
		else
		{
			if (cur->left)
			{
				cur->left->val += 10 * cur->val;
				q.push(cur->left);
			}
			if (cur->right)
			{
				cur->right->val += 10 * cur->val;
				q.push(cur->right);
			}
		}
	}
	return res;
}