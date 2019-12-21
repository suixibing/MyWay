#include "Leetcode.h"

/*
 *
 *	202. 快乐数
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了77.15%的用户
 *  	内存消耗:		8.2 MB, 在所有 C++ 提交中击败了55.61%的用户
 *
 */
bool isHappy(int n)
{
	int tmp = n, sum = 0;
	vector<int> book;
	sum = (tmp % 10) * (tmp % 10);
	tmp /= 10;
	while (tmp != 0 || find(book.begin(), book.end(), sum) == book.end())
	{
		if (tmp == 0)
		{
			if (sum == 1)
				return true;
			book.push_back(sum);
			tmp = sum;
			sum = 0;
		}
		sum += (tmp % 10) * (tmp % 10);
		tmp /= 10;
	}
	return false;
}