#include "Leetcode.h"

/*
 *
 *	258. 各位相加
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了78.69%的用户
 *  	内存消耗:		8.2 MB, 在所有 C++ 提交中击败了23.20%的用户
 *
 */
int addDigits(int num)
{
	int tmp = 0;
	while (num > 9)
	{
		tmp += num % 10;
		num /= 10;
		if (num < 10)
		{
			tmp += num;
			num = tmp;
			tmp = 0;
		}
	}
	return num;
}