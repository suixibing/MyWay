#include "Leetcode.h"

/*
 *
 *	41. 缺失的第一个正数
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.5 MB, 在所有 C++ 提交中击败了94.05%的用户
 *
 */
int firstMissingPositive(vector<int>& nums)
{
	int i, size = nums.size();
	char *book = new char[size];
	for (i = 0; i < size; ++i)
		book[i] = 0;
	for (i = 0; i < size; ++i)
	{
		if (nums[i] > 0 && nums[i] < size + 1)
			++book[nums[i] - 1];
	}
	for (i = 0; i < size; ++i)
	{
		if (book[i] == 0)
			break;
	}
	return i + 1;
}