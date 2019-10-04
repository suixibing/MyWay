#include "Leetcode.h"

/*
 *
 *	38. 报数
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了91.27%的用户
 *  	内存消耗:		8.5 MB, 在所有 C++ 提交中击败了97.52%的用户
 *
 */
string countAndSay(int n)
{
	int i, j, k;
	string str, tmp, res;
	res.push_back('1');
	for (i = 1; i < n; i++)
	{
		str = res;
		res = tmp;
		if (str.size() == 1)
		{
			res.push_back('1');
			res.push_back(str[0]);
			continue;
		}
		for (j = 0; j < str.size(); j++)
		{
			k = j;
			while (j + 1 < str.size() && str[j] == str[j + 1])
				j++;
			res.push_back('0' + j - k + 1);
			res.push_back(str[k]);
		}
	}
	return res;
}