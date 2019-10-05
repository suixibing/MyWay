#include "Leetcode.h"

/*
 *
 *	46. 全排列
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了98.14%的用户
 *  	内存消耗:		9 MB, 在所有 C++ 提交中击败了96.26%的用户
 *
 */
vector< vector<int> > permute(vector<int>& nums)
{
	vector<vector<int>> res;
	res.push_back(nums);
	next_permutation(nums.begin(), nums.end());
	while (res[0] != nums)
	{
		res.push_back(nums);
		next_permutation(nums.begin(), nums.end());
	}
	return res;
}