#include "Leetcode.h"

/*
 *
 *	88. 合并两个有序数组
 *
 *  	执行用时 :		4 ms, 在所有 C++ 提交中击败了97.31%的用户
 *  	内存消耗 :		8.6 MB, 在所有 C++ 提交中击败了92.46%的用户
 *
 */
void merge_88(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = 0, j = 0;
	vector<int> res(m + n);
	while (i < m && j < n)
	{
		if (nums1[i] < nums2[j])
		{
			res[i + j] = nums1[i];
			++i;
		}
		else
		{
			res[i + j] = nums2[j];
			++j;
		}
	}
	while (i < m)
	{
		res[i + j] = nums1[i];
		++i;
	}
	while (j < n)
	{
		res[i + j] = nums2[j];
		++j;
	}
	nums1 = res;
}
