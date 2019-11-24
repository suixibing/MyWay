#include "Leetcode.h"

/*
 *
 *	78. 子集
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了52.56%的用户
 *  	内存消耗:		9 MB, 在所有 C++ 提交中击败了81.20%的用户
 *
 */
void subfunc(vector<int>& nums, vector<int>& ans, int pos, vector< vector<int> >& ret)
{
	if (pos == nums.size())
		return;
	for (int i = pos; i < nums.size(); ++i)
	{
		ans.push_back(nums[i]);
		if (find(ret.begin(), ret.end(), ans) == ret.end())
			ret.push_back(ans);
		subfunc(nums, ans, i + 1, ret);
		ans.pop_back();
	}
}
vector< vector<int> > subsets(vector<int>& nums)
{
	vector<int> ans;
	vector< vector<int> > ret;
	ret.push_back(ans);
	subfunc(nums, ans, 0, ret);
	return ret;
}