#include "Leetcode.h"

/*
 *
 *	191. 位1的个数
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.2 MB, 在所有 C++ 提交中击败了14.97%的用户
 *
 */
int hammingWeight_1(uint32_t n)
{
	int cnt = 0;
	for (int i = 0; i < 32; ++i)
	{
		if ((n >> i) & 1 == 1)
			++cnt;
	}
	return cnt;
}

/*
 *
 *	191. 位1的个数
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.2 MB, 在所有 C++ 提交中击败了24.40%的用户
 *
 */
int hammingWeight_2(uint32_t n)
{
	int cnt = 0;
	while (n)
	{
		++cnt;
		n &= n - 1;
	}
	return cnt;
}

int hammingWeight(uint32_t n)
{
	return hammingWeight_1(n);
}