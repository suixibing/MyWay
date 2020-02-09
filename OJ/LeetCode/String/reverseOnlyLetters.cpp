#include "Leetcode.h"

/*
 *
 *	917. 仅仅反转字母
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了65.08%的用户
 *  	内存消耗:		8.5 MB, 在所有 C++ 提交中击败了5.19%的用户
 *
 */
string reverseOnlyLetters(string S)
{
	char tmp;
	int i = 0, j = S.size() - 1, k;
	while (i < j)
	{
		while (i < j && !(S[i] >= 'a' && S[i] <= 'z' || S[i] >= 'A' && S[i] <= 'Z'))
			++i;
		while (i < j && !(S[j] >= 'a' && S[j] <= 'z' || S[j] >= 'A' && S[j] <= 'Z'))
			--j;
		if (i < j)
		{
			tmp = S[i];
			S[i] = S[j];
			S[j] = tmp;
		}
		++i, --j;
	}
	return S;
}