#include "Leetcode.h"

/*
 *
 *	66. 加一
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了87.74%的用户
 *  	内存消耗:		8.7 MB, 在所有 C++ 提交中击败了6.09%的用户
 *
 */
vector<int> plusOne(vector<int>& digits)
{
	int i = digits.size() - 1;
	++digits[i];
	while (i > 0 && digits[i] > 9)
	{
		++digits[i - 1];
		digits[i--] = 0;
	}
	if (digits[0] > 9)
	{
		digits[0] = 0;
		digits.insert(digits.begin(), 1);
	}
	return digits;
}