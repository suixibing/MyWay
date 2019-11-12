#include "Leetcode.h"

/*
 *
 *	89. 格雷编码
 *
 *  	执行用时:		20 ms, 在所有 C++ 提交中击败了9.09%的用户
 *  	内存消耗:		8.6 MB, 在所有 C++ 提交中击败了40.68%的用户
 *
 */
vector<int> grayCode(int n)
{
	int i, j, k, tmp, num = 0, size = pow(2, n);
	vector<int> res;
	res.push_back(0);
	for (i = 1; i < size; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			tmp = num ^ (1 << j);
			for (k = 0; k < i; ++k)
			{
				if (res[k] == tmp)
					break;
			}
			if (k >= i)
			{
				num = tmp;
				res.push_back(num);
				break;
			}
		}
	}
	return res;
}