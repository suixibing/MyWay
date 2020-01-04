#include "Leetcode.h"

/*
 *
 *	242. 有效的字母异位词
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了96.59%的用户
 *  	内存消耗:		9.3 MB, 在所有 C++ 提交中击败了27.74%的用户
 *
 */
bool isAnagram(string s, string t)
{
	if (s.size() != t.size())
		return false;
	int book[128] = { 0 };
	for (auto i : s)
		++book[i];
	for (auto j : t)
	{
		if (book[j] == 0)
			return false;
		--book[j];
	}
	return true;
}