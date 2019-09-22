#include "Leetcode.h"

// 3. 无重复字符的最长子串
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
