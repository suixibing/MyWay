#include "Leetcode.h"

/*
 *
 *	113. 路径总和 II
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了92.88%的用户
 *  	内存消耗:		35.4 MB, 在所有 C++ 提交中击败了17.92%的用户
 *
 */
vector< vector<int> > pathSum(TreeNode* root, int sum)
{
	if (!root)
		return vector< vector<int> >();
	if (!root->left && !root->right && sum == root->val)
		return vector< vector<int> >(1, vector<int>(1, root->val));
	vector< vector<int> > ret, tmp;
	tmp = pathSum(root->right, sum - root->val);
	ret.insert(ret.begin(), tmp.begin(), tmp.end());
	tmp = pathSum(root->left, sum - root->val);
	ret.insert(ret.begin(), tmp.begin(), tmp.end());
	for (auto & i : ret)
		i.insert(i.begin(), root->val);
	return ret;
}