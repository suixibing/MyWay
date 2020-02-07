#include "Leetcode.h"

/*
 *
 *	905. 按奇偶排序数组
 *
 *  	执行用时:		20 ms, 在所有 C++ 提交中击败了76.80%的用户
 *  	内存消耗:		10.7 MB, 在所有 C++ 提交中击败了5.02%的用户
 *
 */
vector<int> sortArrayByParity(vector<int>& A)
{
	vector<int> ret(A);
	int i = 0, j = A.size() - 1, tmp;
	while (i < j)
	{
		while (i < j && ret[i] % 2 == 0)
			++i;
		while (i < j && ret[j] % 2)
			--j;
		if (i < j)
		{
			tmp = ret[i];
			ret[i++] = ret[j];
			ret[j--] = tmp;
		}
	}
	return ret;
}