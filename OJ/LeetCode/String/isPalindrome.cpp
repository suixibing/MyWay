#include "Leetcode.h"

/*
 *
 *	125. 验证回文串
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了49.47%的用户
 *  	内存消耗:		9.5 MB, 在所有 C++ 提交中击败了30.40%的用户
 *
 */
bool isPalindrome(string s)
{
	int i = 0, j = s.size() - 1;
	while (i < j)
	{
		while (i < j && !isalnum(s[i]))
			++i;
		while (i < j && !isalnum(s[j]))
			--j;
		if (tolower(s[i]) != tolower(s[j]))
			break;
		++i, --j;
	}
	return i >= j;
}