#include "Leetcode.h"

/*
 *
 *	263. 丑数
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.1 MB, 在所有 C++ 提交中击败了18.02%的用户
 *
 */
bool isUgly(int num)
{
	while (num)
	{
		if (num % 2 == 0)
			num /= 2;
		else if (num % 3 == 0)
			num /= 3;
		else if (num % 5 == 0)
			num /= 5;
		else
			break;
	}
	return num == 1;
}