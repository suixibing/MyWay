#include "Leetcode.h"

/*
 *
 *	1. 两数之和
 *
 *  	执行用时:		364 ms, 在所有 C++ 提交中击败了17.71%的用户
 *  	内存消耗:		9.1 MB, 在所有 C++ 提交中击败了92.84%的用户
 *
 */
vector<int> twoSum_1(vector<int>& nums, int target)
{
	vector<int> res;
	int i, j, size = nums.size();
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
				continue;
			else if (nums[i] + nums[j] == target)
			{
				res.push_back(i);
				res.push_back(j);
				return res;
			}
		}
	}
	return res;
}
