#include "Leetcode.h"

/*
 *
 *	205. 同构字符串
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了99.75%的用户
 *  	内存消耗:		9.1 MB, 在所有 C++ 提交中击败了38.94%的用户
 *
 */
bool isIsomorphic(string s, string t)
{
	if (s.size() != t.size())
		return false;
	map<char, char> book;
	int bbook[128] = { 0 };
	for (int i = 0; i < s.size(); ++i)
	{
		if (book[s[i]] != t[i])
		{
			if (book[s[i]] || bbook[t[i]])
				return false;
			book[s[i]] = t[i];
			bbook[t[i]] = 1;
		}
	}
	return true;
}