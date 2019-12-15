#include "Leetcode.h"

/*
 *
 *	169. 多数元素
 *
 *  	执行用时:		24 ms, 在所有 C++ 提交中击败了62.41%的用户
 *  	内存消耗:		11 MB, 在所有 C++ 提交中击败了85.94%的用户
 *
 */
int majorityElement(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	return nums[nums.size() / 2];
}