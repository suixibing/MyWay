#include "Leetcode.h"

/*
 *
 *	27. 移除元素
 *
 *  	执行用时 :		8 ms, 在所有 C++ 提交中击败了59.36%的用户
 *  	内存消耗 :		8.5 MB, 在所有 C++ 提交中击败了86.95%的用户
 *
 */
int removeElement(vector<int>& nums, int val) 
{
	int left = 0, right = 0, size = nums.size();
	for (; right < size; ++right)
	{
		if (nums[right] != val)
		{
			nums[left] = nums[right];
			++left;
		}
	}
	nums.resize(left);
	return left;
}