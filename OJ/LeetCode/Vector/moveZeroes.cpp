#include "Leetcode.h"

/*
 *
 *	283. 移动零
 *
 *  	执行用时 :		24 ms, 在所有 C++ 提交中击败了32.11%的用户
 *  	内存消耗 :		10.2 MB, 在所有 C++ 提交中击败了5.49%的用户
 *
 */
void moveZeroes(vector<int>& nums)
{
	int i, j;
	for (i = 0; i < nums.size(); ++i)
	{
		while (i < nums.size() && nums[i] != 0)
			++i;
		j = i + 1;
		while (j < nums.size() && nums[j] == 0)
			++j;
		if (j >= nums.size())
			return;
		nums[i] = nums[j];
		nums[j] = 0;
	}
}