#include "Leetcode.h"

/*
 *
 *	231. 2的幂
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了72.27%的用户
 *  	内存消耗:		8 MB, 在所有 C++ 提交中击败了54.45%的用户
 *
 */
bool isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;
	return !(n & n - 1);
}