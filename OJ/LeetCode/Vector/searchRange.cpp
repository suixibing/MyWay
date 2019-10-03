#include "Leetcode.h"

/*
 *
 *	34. 在排序数组中查找元素的第一个和最后一个位置
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了94.65%的用户
 *  	内存消耗:		10.4 MB, 在所有 C++ 提交中击败了75.63%的用户
 *
 */
vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> res;
	res.push_back(-1);
	res.push_back(-1);
	int left = 0, right = nums.size() - 1, mid = (left + right) / 2;
	if (right == -1)
		return res;
	while (left <= right)
	{
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
		else
			break;
		mid = (left + right) / 2;
	}
	if (left <= right)
	{
		for (res[0] = mid; res[0] > 0 && nums[res[0]] == nums[res[0] - 1]; --res[0])
			continue;
		for (res[1] = mid; res[1] + 1 < nums.size() && nums[res[1]] == nums[res[1] + 1]; ++res[1])
			continue;
	}
	return res;
}