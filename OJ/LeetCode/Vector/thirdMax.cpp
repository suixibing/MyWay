#include "Leetcode.h"

/*
 *
 *	414. 第三大的数
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了52.80%的用户
 *  	内存消耗:		9.5 MB, 在所有 C++ 提交中击败了43.54%的用户
 *
 */
int thirdMax(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	for (int i = nums.size() - 2, cnt = 1; i >= 0; --i)
	{
		while (i >= 0 && nums[i] == nums[i + 1])
			--i;
		if (i >= 0)
			++cnt;
		if (cnt == 3)
			return nums[i];
	}
	return nums[nums.size() - 1];
}