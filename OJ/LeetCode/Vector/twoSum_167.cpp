#include "Leetcode.h"

/*
 *
 *	167. 两数之和 II - 输入有序数组
 *
 *  	执行用时:		280 ms, 在所有 C++ 提交中击败了5.69%的用户
 *  	内存消耗:		9.6 MB, 在所有 C++ 提交中击败了19.68%的用户
 *
 */
vector<int> twoSum_167(vector<int>& numbers, int target)
{
	int i, j;
	vector<int> res;
	for (i = 0; i < numbers.size(); ++i)
	{
		for (j = i + 1; j < numbers.size(); ++j)
		{
			if (numbers[i] + numbers[j] > target)
				break;
			else if (numbers[i] + numbers[j] == target)
			{
				res.push_back(i + 1);
				res.push_back(j + 1);
				return res;
			}
		}
	}
	return res;
}