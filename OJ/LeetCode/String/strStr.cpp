#include "Leetcode.h"

/*
 *
 *	28. 实现 strStr()
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了93.41%的用户
 *  	内存消耗:		9.2 MB, 在所有 C++ 提交中击败了75.85%的用户
 *
 */
int strStr(string haystack, string needle)
{
	if (needle == "")
		return 0;
	int i, size1 = haystack.size(), size2 = needle.size();
	for (i = 0; i + size2 <= size1; i++)
	{
		if (haystack[i] == needle[0] && haystack.substr(i, size2) == needle)
		{
			return i;
		}
	}
	return -1;
}