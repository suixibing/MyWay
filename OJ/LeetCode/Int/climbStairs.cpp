#include "Leetcode.h"

/*
 *
 *	70. 爬楼梯
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.2 MB, 在所有 C++ 提交中击败了75.90%的用户
 *
 */
int climbStairs(int n)
{
	int i, pre = 0, cur = 1, res = 0;
	for (i = 0; i < n; ++i)
	{
		res = pre + cur;
		pre = cur;
		cur = res;
	}
	return res;
}