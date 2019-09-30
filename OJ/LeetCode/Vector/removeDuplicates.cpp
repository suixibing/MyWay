#include "Leetcode.h"

/*
 *
 *	26. 删除排序数组中的重复项
 *
 *  	执行用时 :		260 ms, 在所有 C++ 提交中击败了15.61%的用户
 *  	内存消耗 :		9.8 MB, 在所有 C++ 提交中击败了89.27%的用户
 *
 */
int removeDuplicates1(vector<int>& nums)
{
	int i, j, count, size = nums.size();
	for (i = size - 1; i > 0 && size > 1; i--)
	{
		if (nums[i] != nums[i - 1])
			continue;
		count = 1;
		while (count + 1 <= i && nums[i] == nums[i - count - 1])
			count++;
		for (j = i + 1; j < size; j++)
		{
			nums[j - count] = nums[j];
		}
		size -= count;
		i -= count;
	}
	nums.resize(size);
	return size;
}

/*
 *
 *	26. 删除排序数组中的重复项
 *
 *  	执行用时 :		16 ms, 在所有 C++ 提交中击败了99.97%的用户
 *  	内存消耗 :		9.7 MB, 在所有 C++ 提交中击败了97.27%的用户
 *
 */
int removeDuplicates2(vector<int>& nums)
{
	if (nums.size() <= 1)
		return nums.size();
	int left = 0, right = 0, size = nums.size();
	for ( ; right < size; ++right)
	{
		if (nums[left] != nums[right])
		{
			nums[left + 1] = nums[right];
			++left;
		}
	}
	nums.resize(left + 1);
	return left + 1;
}

int removeDuplicates(vector<int>& nums)
{
	return removeDuplicates1(nums);
}