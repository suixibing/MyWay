#include "Leetcode.h"

/*
 *
 *	4. 寻找两个有序数组的中位数
 *
 *  	执行用时:		32 ms, 在所有 C++ 提交中击败了48.78%的用户
 *  	内存消耗:		10 MB, 在所有 C++ 提交中击败了79.98%的用户
 *
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> t;
	int i = 0, j = 0, size = nums1.size() + nums2.size();
	while (i + j <= size / 2)
	{
		if (j >= nums2.size() || i < nums1.size() && nums1[i] < nums2[j])
		{
			t.push_back(nums1[i++]);
		}
		else
		{
			t.push_back(nums2[j++]);
		}
	}
	if (size % 2)
	{
		return t[size / 2];
	}
	else
	{
		return (t[size / 2 - 1] + t[size / 2]) / 2.0;
	}
}
