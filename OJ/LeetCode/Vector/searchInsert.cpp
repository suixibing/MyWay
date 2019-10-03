#include "Leetcode.h"

/*
 *
 *	35. 搜索插入位置
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了80.20%的用户
 *  	内存消耗:		8.9 MB, 在所有 C++ 提交中击败了78.37%的用户
 *
 */
int searchInsert(vector<int>& nums, int target)
{
	int left = 0, right = nums.size() - 1, mid = (left + right) / 2;
	if (right == -1 || nums[0] > target)
		return 0;
	else if (nums[right] < target)
		return right + 1;
	while (left <= right)
	{
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
		else
			return mid;
		mid = (left + right) / 2;
	}
	for (mid = right; nums[mid] < target; mid++)
		continue;
	return mid;
}