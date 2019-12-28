#include "Leetcode.h"

/*
 *
 *	217. 存在重复元素
 *
 *  	执行用时:		56 ms, 在所有 C++ 提交中击败了39.23%的用户
 *  	内存消耗:		16.6 MB, 在所有 C++ 提交中击败了16.11%的用户
 *
 */
bool containsDuplicate(vector<int>& nums)
{
	map<int, int> book;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (book[nums[i]] == 1)
			return true;
		book[nums[i]] = 1;
	}
	return false;
}