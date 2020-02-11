#include "Leetcode.h"

/*
 *
 *	136. 只出现一次的数字
 *
 *  	执行用时:		24 ms, 在所有 C++ 提交中击败了28.09%的用户
 *  	内存消耗:		9.8 MB, 在所有 C++ 提交中击败了32.95%的用户
 *
 */
int singleNumber(vector<int>& nums)
{
	int ret = nums[0];
	for (int i = nums.size() - 1; i > 0; --i)
		ret ^= nums[i];
	return ret;
}