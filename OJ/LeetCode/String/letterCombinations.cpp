#include "Leetcode.h"

/*
 *
 *	17. 电话号码的字母组合
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了80.31%的用户
 *  	内存消耗:		8.5 MB, 在所有 C++ 提交中击败了79.12%的用户
 *
 */
void getCombinations(vector<string>& vec, string str, int flag)
{
	static const string keyboard[] = { " ", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	int i, size = str.size(), strsize = keyboard[str[flag] - '0'].size();
	string tmp(str);
	for (i = 0; i < strsize; i++)
	{
		tmp[flag] = keyboard[str[flag] - '0'][i];
		if (flag == size - 1)
		{
			vec.push_back(tmp);
			continue;
		}
		getCombinations(vec, tmp, flag + 1);
	}

}
vector<string> letterCombinations(string digits)
{
	vector<string> res;
	if (digits.size() == 0)
		return res;
	getCombinations(res, digits, 0);
	return res;
}