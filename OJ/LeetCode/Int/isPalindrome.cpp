#include "Leetcode.h"

/*
 *
 *	9. 回文数
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了89.21%的用户
 *  	内存消耗:		8.1 MB, 在所有 C++ 提交中击败了82.64%的用户
 *
 */
bool isPalindrome(int x) 
{
	if (x < 0)
		return false;
	int tmp = x;
	long long y = 0;
	while (tmp)
	{
		y = y * 10 + tmp % 10;
		tmp /= 10;
	}
	return x == y;
}