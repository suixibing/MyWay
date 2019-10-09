#include "Leetcode.h"

/*
 *
 *	53. 最大子序和
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了99.20%的用户
 *  	内存消耗:		9.3 MB, 在所有 C++ 提交中击败了77.84%的用户
 *
 */
int maxSubArray(vector<int>& nums)
{
	int i, sum = 0, res = -2147483647, size = nums.size();
	for (i = 0; i < size; ++i)
	{
		sum += nums[i];
		if (sum > res)
			res = sum;
		if (sum < 0)
			sum = 0;
	}
	return res;
}