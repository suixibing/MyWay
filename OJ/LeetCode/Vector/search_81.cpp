#include "Leetcode.h"

/*
 *
 *	81. 搜索旋转排序数组 II
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了97.57%的用户
 *  	内存消耗:		8.8 MB, 在所有 C++ 提交中击败了18.18%的用户
 *
 */
bool search_81(vector<int>& nums, int target)
{
	int size = nums.size(), left, right = size - 1, mid;
	for (left = 1; left < size; ++left)
		if (nums[left] < nums[left - 1])
			break;
	right += left;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid % size] == target)
			return true;
		else if (nums[mid % size] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return false;
}