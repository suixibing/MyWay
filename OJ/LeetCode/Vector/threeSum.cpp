#include "Leetcode.h"

/*
 *
 *	15. 三数之和
 *
 *  	执行用时:		120 ms, 在所有 C++ 提交中击败了98.84%的用户
 *  	内存消耗:		14.4 MB, 在所有 C++ 提交中击败了99.13%的用户
 *
 */
vector<vector<int>> threeSum(vector<int>& nums)
{
	int i, j, k, size = nums.size();
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for (i = 0; i < size; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		for (j = i + 1, k = size - 1; j < k; )
		{
			if (nums[i] + nums[j] + nums[k] > 0)
				k--;
			else if (nums[i] + nums[j] + nums[k] < 0)
				j++;
			else
			{
				res.push_back({ nums[i], nums[j], nums[k] });
				j++;
				while (j < k && nums[j] == nums[j - 1])
					j++;
			}
		}
	}
	return res;
}