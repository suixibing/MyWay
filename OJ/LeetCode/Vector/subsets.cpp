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
vector< vector<int> > subsets1(vector<int>& nums)
{
	vector<int> ans;
	vector< vector<int> > ret;
	ret.push_back(ans);
	subfunc(nums, ans, 0, ret);
	return ret;
}

/*
 *
 *	78. 子集
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了91.88%的用户
 *  	内存消耗:		9.6 MB, 在所有 C++ 提交中击败了24.43%的用户
 *
 */
vector< vector<int> > subsets2(vector<int>& nums)
{
	vector<int> tmp;
	vector< vector<int> > ret;
	if (nums.size() == 0)
	{
		ret.push_back(vector<int>());
		return ret;
	}
	int i, size, add = nums[nums.size() - 1];
	nums.pop_back();
	ret = subsets(nums);
	for (i = 0, size = ret.size(); i < size; ++i)
	{
		tmp = ret[i];
		tmp.push_back(add);
		ret.push_back(tmp);
	}
	return ret;
}

vector< vector<int> > subsets(vector<int>& nums)
{
	return subsets1(nums);
}