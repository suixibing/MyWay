#include "Leetcode.h"

/*
 *
 *	3. 无重复字符的最长子串
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了88.42%的用户
 *  	内存消耗:		9 MB, 在所有 C++ 提交中击败了96.60%的用户
 *
 */
int lengthOfLongestSubstring(string s)
{
	int start = 0, end = 1, len = 1;
	char book[256] = { 0 };
	int size = s.size();
	if (s.empty())
	{
		return 0;
	}
	book[s[start]] = 1;
	while (end < size)
	{
		while (end < size && book[s[end]] == 0)
		{
			len = len > (end - start + 1) ? len : end - start + 1;
			book[s[end]]++;
			end++;
		}
		book[s[start]]--;
		start++;
	}
	return len;
}
