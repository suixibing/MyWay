#include "Leetcode.h"

/*
 *
 *	84. 柱状图中最大的矩形
 *
 *  	执行用时 :		520 ms, 在所有 C++ 提交中击败了15.97%的用户
 *  	内存消耗 :		9.7 MB, 在所有 C++ 提交中击败了93.51%的用户
 *
 */
int largestRectangleArea(vector<int>& heights)
{
	int i = 0, res = 0, left = 0, right = 0;
	while (i < heights.size())
	{
		if (i - 1 >= 0 && heights[i] > heights[i - 1])
			left = right = i;
		while (left - 1 >= 0 && heights[i] <= heights[left - 1])
			--left;
		while (right + 1 < heights.size() && heights[i] <= heights[right + 1])
			++right;
		if (res < (right - left + 1) * heights[i])
			res = (right - left + 1) * heights[i];
		++i;
	}
	return res;
}