#include "Leetcode.h"

/*
 *
 *	204. 计数质数
 *
 *  	执行用时 :		96 ms, 在所有 C++ 提交中击败了60.69%的用户
 *  	内存消耗 :		8.6 MB, 在所有 C++ 提交中击败了67.83%的用户
 *
 */
int countPrimes(int n)
{
	if (n <= 2)
		return 0;
	int i, j, cnt = 0;
	vector<bool> book(n + 1, true);
	book[0] = book[1] = 0;
	for (i = 2; i < n; ++i)
	{
		if (book[i])
		{
			++cnt;
			for (j = 2; i * j <= n; ++j)
			{
				book[i * j] = false;
			}
		}
	}
	return cnt;
}