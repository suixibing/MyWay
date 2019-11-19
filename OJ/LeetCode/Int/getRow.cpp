#include "Leetcode.h"

/*
 *
 *	119. 杨辉三角 II
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了24.48%的用户
 *  	内存消耗:		8.4 MB, 在所有 C++ 提交中击败了59.66%的用户
 *
 */
vector<int> getRow(int rowIndex)
{
	vector<int> res(rowIndex + 1, 0);
	res[0] = 1;
	for (int i = 1; i <= rowIndex; ++i)
	{
		for (int j = i; j > 0; --j)
			res[j] += res[j - 1];
	}
	return res;
}