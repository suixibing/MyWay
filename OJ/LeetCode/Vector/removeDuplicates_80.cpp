#include "Leetcode.h"

/*
 *
 *	80. 删除排序数组中的重复项 II
 *
 *  	执行用时 :		16 ms, 在所有 C++ 提交中击败了84.49%的用户
 *  	内存消耗 :		8.6 MB, 在所有 C++ 提交中击败了94.13%的用户
 *
 */
int removeDuplicates_80(vector<int>& nums)
{
	int i = 0, j = 0;
	while (i < nums.size())
	{
		if (i + 1 < nums.size() && nums[i] == nums[i + 1])
		{
			while (i + 1 < nums.size() && nums[i] == nums[i + 1])
				++i;
			nums[j++] = nums[i];
		}
		nums[j++] = nums[i++];
	}
	nums.resize(j);
	return j;
}