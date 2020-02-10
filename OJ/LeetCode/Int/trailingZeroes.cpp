#include "Leetcode.h"

/*
 *
 *	172. 阶乘后的零
 *
 *  	执行用时 :		4 ms, 在所有 C++ 提交中击败了70.20%的用户
 *  	内存消耗 :		8.1 MB, 在所有 C++ 提交中击败了80.43%的用户
 *
 */
int trailingZeroes(int n)
{
	int cnt = 0;
	while (n)
	{
		cnt += n / 5;
		n /= 5;
	}
	return cnt;
}