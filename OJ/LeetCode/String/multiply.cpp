#include "Leetcode.h"

/*
 *
 *	43. 字符串相乘
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了64.49%的用户
 *  	内存消耗:		8.5 MB, 在所有 C++ 提交中击败了97.87%的用户
 *
 */
string multiply(string num1, string num2)
{
	if (num1.size() == 1 && num1[0] == '0' || num2.size() == 1 && num2[0] == '0')
		return "0";
	string res;
	int i, j, tmp, size = num1.size() + num2.size();
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	res.resize(size);
	for (i = 0; i < size; ++i)
		res[i] = '0';
	for (i = 0; i < num1.size(); ++i)
	{
		for (j = 0; j < num2.size(); ++j)
		{
			tmp = (num1[i] - '0') * (num2[j] - '0');
			res[i + j + 1] += (res[i + j] - '0' + tmp) / 10;
			res[i + j] = (res[i + j] - '0' + tmp) % 10 + '0';
		}
	}
	if (res[size - 1] == '0')
		res.pop_back();
	reverse(res.begin(), res.end());
	return res;
}