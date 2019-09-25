#include "Leetcode.h"

/*
 *
 *	14. 最长公共前缀
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了75.50%的用户
 *  	内存消耗:		8.6 MB, 在所有 C++ 提交中击败了97.06%的用户
 *
 */
string longestCommonPrefix(vector<string>& strs)
{
	string res;
	char tmp[2];
	int i, letter = 0, strnums = strs.size();
	if (strnums == 1)
		return strs[0];
	else if (!strnums)
		return res;
	while (1)
	{
		tmp[0] = strs[0][letter];
		tmp[1] = strs[1][letter];
		if (tmp[0] != tmp[1] || tmp[0] == '\0')
			return res;
		for (i = 2; i < strnums; i++)
		{
			if (letter >= strs[i].size())
				return res;
			tmp[i % 2] = strs[i][letter];
			if (tmp[0] != tmp[1])
				return res;
		}
		tmp[1] = '\0';
		res.append(tmp);
		letter++;
	}
}