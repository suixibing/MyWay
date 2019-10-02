#include "Leetcode.h"

/*
 *
 *	31. 下一个排列
 *
 *  	执行用时 :		12 ms, 在所有 C++ 提交中击败了81.71%的用户
 *  	内存消耗 :		8.6 MB, 在所有 C++ 提交中击败了87.02%的用户
 *
 */
void nextPermutation(vector<int>& nums)
{
	int i, j, min, size = nums.size();
	if (size <= 1)
		return;
	for (i = size - 1; i > 0; i--)
	{
		if (nums[i] > nums[i - 1])
		{
			j = i - 1;
			break;
		}
	}
	if (i == 0)
	{
		sort(nums.begin(), nums.end());
		return;
	}
	for (min = i; i < size; i++)
	{
		if (nums[i] > nums[j] && nums[i] < nums[min])
		{
			min = i;
		}
	}
	i = nums[j];
	nums[j] = nums[min];
	nums[min] = i;
	sort(nums.begin() + j + 1, nums.end());
}