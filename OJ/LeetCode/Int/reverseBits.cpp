#include "Leetcode.h"

/*
 *
 *	190. 颠倒二进制位
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了88.77%的用户
 *  	内存消耗:		8.1 MB, 在所有 C++ 提交中击败了15.06%的用户
 *
 */
uint32_t reverseBits(uint32_t n)
{
	uint32_t res = 0;
	for (int i = 0; i < 32; ++i)
	{
		if ((1 << i) & n)
			res |= (1 << (31 - i));
	}
	return res;
}