#include "Leetcode.h"

/*
 *
 *	18. 四数之和
 *
 *  	执行用时:		72 ms, 在所有 C++ 提交中击败了53.16%的用户
 *  	内存消耗:		8.9 MB, 在所有 C++ 提交中击败了97.16%的用户
 *
 */
vector< vector<int> > fourSum(vector<int>& nums, int target)
{
	vector< vector<int> > res;
	int i, j, m, n, tmp, size = nums.size();
	sort(nums.begin(), nums.end());
	for (i = 0, j = i + 1; i + 3 < size; )
	{
		for (m = j + 1, n = size - 1; m < n; )
		{
			tmp = nums[i] + nums[j] + nums[m] + nums[n];
			if (tmp == target)
			{
				res.push_back({ nums[i], nums[j], nums[m], nums[n] });
				m++;
				while (m < n && nums[m] == nums[m - 1])
					m++;
			}
			else if (tmp < target)
				m++;
			else
				n--;
		}
		if (j + 2 < size)
		{
			j++;
			while (j < size && nums[j] == nums[j - 1])
				j++;
		}
		else
		{
			i++;
			while (i < size && nums[i] == nums[i - 1])
				i++;
			j = i + 1;
		}
	}
	return res;
}