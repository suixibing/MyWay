#include "Leetcode.h"

/*
 *
 *	90. 子集 II
 *
 *  	执行用时:		16 ms, 在所有 C++ 提交中击败了56.53%的用户
 *  	内存消耗:		9 MB, 在所有 C++ 提交中击败了98.51%的用户
 *
 */
void subfunc(vector<int>& nums, int pos, vector<int>& tmp, vector< vector<int> >& res)
{
	for (int i = pos; i < nums.size(); ++i)
	{
		tmp.push_back(nums[i]);
		res.push_back(tmp);
		subfunc(nums, i + 1, tmp, res);
		tmp.pop_back();
		while (i + 1 < nums.size() && nums[i] == nums[i + 1])
			++i;
	}
}
vector< vector<int> > subsetsWithDup(vector<int>& nums)
{
	vector<int> tmp;
	vector< vector<int> > res;
	res.push_back(tmp);
	sort(nums.begin(), nums.end());
	subfunc(nums, 0, tmp, res);
	return res;
}