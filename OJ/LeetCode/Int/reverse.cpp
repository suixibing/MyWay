#include "Leetcode.h"

/*
 *
 *	7. 整数反转
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8 MB, 在所有 C++ 提交中击败了95.52%的用户
 *
 */
int reverse(int x)
{
	long tmp, y = 0;
	int flag = x < 0 ? -1 : 1;
	tmp = x < 0 ? -(long)x : (long)x;
	while (tmp > 0)
	{
		y = y * 10 + tmp % 10;
		tmp /= 10;
	}
	if (y > 2147483647 || y < -2147483638)
	{
		return 0;
	}
	return flag * y;
}
