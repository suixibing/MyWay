#include "Leetcode.h"

/*
 *
 *	16. 最接近的三数之和
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了79.25%的用户
 *  	内存消耗:		8.7 MB, 在所有 C++ 提交中击败了83.48%的用户
 *
 */
int threeSumClosest(vector<int>& nums, int target)
{
	int i, j, k, tmp, size = nums.size(), leastGap = 2147483647, res = 0;
	sort(nums.begin(), nums.end());
	for (i = 0; i < size; i++)
	{
		for (j = i + 1, k = size - 1; j < k; )
		{
			tmp = nums[i] + nums[j] + nums[k] - target;
			if (abs(tmp) < leastGap)
			{
				res = tmp + target;
				leastGap = abs(tmp);
			}
			else if (tmp > 0)
				k--;
			else
				j++;
		}
	}
	return res;
}