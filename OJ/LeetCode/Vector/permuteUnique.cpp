#include "Leetcode.h"

/*
 *
 *	47. 全排列 II
 *
 *  	执行用时:		40 ms, 在所有 C++ 提交中击败了66.14%的用户
 *  	内存消耗:		9.8 MB, 在所有 C++ 提交中击败了91.38%的用户
 *
 */
vector< vector<int> > permuteUnique(vector<int>& nums)
{
	vector< vector<int> > res;
	res.push_back(nums);
	next_permutation(nums.begin(), nums.end());
	while (res[0] != nums)
	{
		res.push_back(nums);
		next_permutation(nums.begin(), nums.end());
	}
	return res;
}