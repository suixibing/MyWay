#include "Leetcode.h"

/*
 *
 *	29. 两数相除
 *
 *  	执行用时 :		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗 :		8.2 MB, 在所有 C++ 提交中击败了74.70%的用户
 *
 */
int divide(int dividend, int divisor)
{
	if (!dividend)
		return 0;
	else if (dividend == -2147483648LL && divisor == -1LL)
		return 2147483647;
	int i, negative = (dividend ^ divisor) < 0 ? -1 : 1;
	unsigned num1 = dividend < 0 ? -(long long)dividend : dividend;
	unsigned num2 = divisor < 0 ? -(long long)divisor : divisor;
	unsigned res = 0;
	for (i = 31; i >= 0; i--)
	{
		if (num2 <= (num1 >> i))
		{
			res += ((unsigned)1) << i;
			num1 -= num2 << i;
		}
	}
	long num = (long)negative * res;
	if (num < -2147483647 || num > 2147483647)
		return -2147483648LL;
	return num;
}
