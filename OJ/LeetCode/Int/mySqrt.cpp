#include "Leetcode.h"

/*
 *
 *	69. x 的平方根
 *
 *  	执行用时:		24 ms, 在所有 C++ 提交中击败了13.68%的用户
 *  	内存消耗:		8 MB, 在所有 C++ 提交中击败了94.43%的用户
 *
 */
int mySqrt(int x)
{
	long res = 1;
	while (res * res <= x)
		++res;
	return res - 1;
}

/*
 *
 *	69. x 的平方根
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了58.12%的用户
 *  	内存消耗:		8.1 MB, 在所有 C++ 提交中击败了83.99%的用户
 *
 */
int mySqrt(int x)
{
	long res = x / 2;
	while (res * res > x)
		res /= 2;
	while (res * res <= x)
		++res;
	return res - 1;
}

/*
 *
 *	69. x 的平方根
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了88.84%的用户
 *  	内存消耗:		8.2 MB, 在所有 C++ 提交中击败了82.25%的用户
 *
 */
int mySqrt(int x)
{
	long left = 0, right = x, mid;
	while (left < right)
	{
		mid = left + (right - left + 1) / 2;
		if (mid * mid > x)
			right = mid - 1;
		else
			left = mid;
	}
	return left;
}