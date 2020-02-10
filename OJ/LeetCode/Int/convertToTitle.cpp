#include "Leetcode.h"

/*
 *
 *	168. Excel表列名称
 *
 *  	执行用时 :		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗 :		8.2 MB, 在所有 C++ 提交中击败了24.04%的用户
 *
 */
string convertToTitle(int n)
{
	string ret;
	while (n)
	{
		ret.push_back((n - 1) % 26 + 'A');
		n = (n - 1) / 26;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}