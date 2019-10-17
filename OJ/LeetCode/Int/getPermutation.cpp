#include "Leetcode.h"

/*
 *
 *	60. 第k个排列
 *
 *  	执行用时:		520 ms, 在所有 C++ 提交中击败了12.05%的用户
 *  	内存消耗:		8.1 MB, 在所有 C++ 提交中击败了82.28%的用户
 *
 */
string getPermutation(int n, int k)
{
	int i;
	string res;
	for (i = 0; i < n; ++i)
		res.push_back('1' + i);
	for (i = 1; i < k; ++i)
		next_permutation(res.begin(), res.end());
	return res;
}