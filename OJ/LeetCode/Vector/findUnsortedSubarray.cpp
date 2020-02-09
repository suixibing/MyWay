#include "Leetcode.h"

/*
 *
 *	581. 最短无序连续子数组
 *
 *  	执行用时:		60 ms, 在所有 C++ 提交中击败了19.75%的用户
 *  	内存消耗:		11.6 MB, 在所有 C++ 提交中击败了9.14%的用户
 *
 */
int findUnsortedSubarray(vector<int>& nums)
{
	int i, j;
	vector<int> tmp(nums);
	sort(nums.begin(), nums.end());
	for (i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != tmp[i])
			break;
	}
	for (j = nums.size() - 1; j > i; --j)
	{
		if (nums[j] != tmp[j])
			break;
	}
	return j - i + 1;
}