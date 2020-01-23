#include "Leetcode.h"

/*
 *
 *	326. 3的幂
 *
 *  	执行用时:		20 ms, 在所有 C++ 提交中击败了75.98%的用户
 *  	内存消耗:		7.9 MB, 在所有 C++ 提交中击败了97.89%的用户
 *
 */
bool isPowerOfThree(int n)
{
	if (n <= 0)
		return false;
	while (n)
	{
		if (n == 1)
			break;
		if (n % 3)
			return false;
		n /= 3;
	}
	return true;
}