#include "Leetcode.h"

/*
 *
 *	541. 反转字符串 II
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了69.49%的用户
 *  	内存消耗:		9.8 MB, 在所有 C++ 提交中击败了14.98%的用户
 *
 */
string reverseStr(string s, int k)
{
	char tmp;
	int i = 0, j;
	while (i < s.size())
	{
		if (i + k >= s.size())
			k = s.size() - i;
		for (j = 0; j < k / 2; ++j)
		{
			tmp = s[i + j];
			s[i + j] = s[i + k - j - 1];
			s[i + k - j - 1] = tmp;
		}
		i += 2 * k;
	}
	return s;
}