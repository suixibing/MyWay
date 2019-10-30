#include "Leetcode.h"

/*
 *
 *	75. 颜色分类
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了90.03%的用户
 *  	内存消耗:		8.6 MB, 在所有 C++ 提交中击败了23.56%的用户
 *
 */
void sortColors(vector<int>& nums)
{
	int i = 0, flag1 = 0, flag2 = nums.size() - 1;
	while (i <= flag2)
	{
		if (nums[i] == 0)
			swap(nums[i++], nums[flag1++]);
		else if (nums[i] == 2)
			swap(nums[i], nums[flag2--]);
		else
			++i;
	}
}

/*
 *
 *	75. 颜色分类
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.4 MB, 在所有 C++ 提交中击败了80.22%的用户
 *
 */
void sortColors(vector<int>& nums)
{
	int i = 0, flag1 = 0, flag2 = nums.size() - 1;
	if (flag2 < 1)
		return;
	while (i <= flag2)
	{
		if (nums[i] == 0)
		{
			nums[i] = nums[flag1];
			nums[flag1] = 0;
		}
		else if (nums[i] == 2)
		{
			nums[i] = nums[flag2];
			nums[flag2] = 2;
		}
		else
			++i;
		while (flag1 <= flag2 && nums[flag1] == 0)
			++flag1;
		while (flag1 <= flag2 && nums[flag2] == 2)
			--flag2;
		if (i < flag1)
			i = flag1;
	}
}

/*
 *
 *	75. 颜色分类
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了55.89%的用户
 *  	内存消耗:		8.5 MB, 在所有 C++ 提交中击败了41.75%的用户
 *
 */
void sortColors(vector<int>& nums)
{
	int i, red = 0, white = 0, blue = 0;
	for (i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 0)
			++red;
		else if (nums[i] == 1)
			++white;
		else
			++blue;
	}
	for (i = 0; i < nums.size(); ++i)
	{
		if (i < red)
			nums[i] = 0;
		else if (i < red + white)
			nums[i] = 1;
		else
			nums[i] = 2;
	}
}