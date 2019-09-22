#include "Leetcode.h"

// 1. 两数之和
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> res;
	int i, j, size = nums.size();
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
			{
				continue;
			}
			else if (nums[i] + nums[j] == target)
			{
				res.push_back(i);
				res.push_back(j);
				goto ret;
			}
		}
	}
ret:
	return res;
}
