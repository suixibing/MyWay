#include "Leetcode.h"

/*
 *
 *	268. 缺失数字
 *
 *  	执行用时 :		36 ms, 在所有 C++ 提交中击败了24.31%的用户
 *  	内存消耗 :		10.2 MB, 在所有 C++ 提交中击败了5.19%的用户
 *
 */
int missingNumber(vector<int>& nums)
{
	int i;
	sort(nums.begin(), nums.end());
	if (nums[0] == 1)
		return 0;
	for (i = 0; i + 1 < nums.size(); ++i)
	{
		if (nums[i] + 2 == nums[i + 1])
			break;
	}
	return nums[i] + 1;
}