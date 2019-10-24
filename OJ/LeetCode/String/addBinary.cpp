#include "Leetcode.h"

/*
 *
 *	67. 二进制求和
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.6 MB, 在所有 C++ 提交中击败了51.84%的用户
 *
 */
string addBinary(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i, flag = 0, max = (a.size() < b.size() ? b.size() : a.size());
	a.resize(max, '0');
	b.resize(max, '0');
	for (i = 0; i < max; ++i)
	{
		flag += a[i] - '0' + b[i] - '0';
		a[i] = flag % 2 + '0';
		flag /= 2;
	}
	if (flag)
		a.push_back('1');
	reverse(a.begin(), a.end());
	return a;
}