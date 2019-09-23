#include "Leetcode.h"

/*
 *
 *	6. Z 字形变换
 *
 *  	执行用时:		16 ms, 在所有 C++ 提交中击败了79.35%的用户
 *  	内存消耗:		12.2 MB, 在所有 C++ 提交中击败了83.14%的用户
 *
 */
string convert(string s, int numRows)
{
	int i, j, plus = 1;
	string *res = new string[numRows];
	if (numRows == 1)
	{
		return s;
	}
	for (i = 0, j = 0; i < s.size(); i++)
	{
		res[j].push_back(s[i]);
		if ((j + 1) % numRows == 0)
		{
			plus = -1;
		}
		else if (j % numRows == 0)
		{
			plus = 1;
		}
		j += plus;
	}
	for (i = 0, s.resize(0); i < numRows; i++)
	{
		s += res[i];
	}
	delete[] res;
	return s;
}
