#include "Leetcode.h"

/*
 *
 *	108. 将有序数组转换为二叉搜索树
 *
 *  	执行用时:		24 ms, 在所有 C++ 提交中击败了58.27%的用户
 *  	内存消耗:		26.1 MB, 在所有 C++ 提交中击败了7.22%的用户
 *
 */
TreeNode* sortedArrayToBST(vector<int>& nums)
{
	TreeNode *root = nullptr;
	if (nums.size() <= 0)
		return root;
	if (nums.size() == 1)
		root = new TreeNode(nums[0]);
	root = new TreeNode(nums[nums.size() / 2]);
	vector<int> tmp1(nums.begin(), nums.begin() + nums.size() / 2);
	root->left = sortedArrayToBST(tmp1);
	vector<int> tmp2(nums.begin() + nums.size() / 2 + 1, nums.end());
	root->right = sortedArrayToBST(tmp2);
	return root;
}