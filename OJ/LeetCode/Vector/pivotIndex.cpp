#include "Leetcode.h"

/*
 *
 *	724. 寻找数组的中心索引
 *
 *  	执行用时:		36 ms, 在所有 C++ 提交中击败了31.70%的用户
 *  	内存消耗:		9.8 MB, 在所有 C++ 提交中击败了65.26%的用户
 *
 */
int pivotIndex(vector<int>& nums)
{
	int i, leftsum = 0, sum = 0;
	for (i = 0; i < nums.size(); ++i)
		sum += nums[i];
	for (i = 0; i < nums.size(); ++i)
	{
		if (sum == leftsum * 2 + nums[i])
			return i;
		leftsum += nums[i];
	}
	return -1;
}