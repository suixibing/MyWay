#include "Leetcode.h"

/*
 *
 *	709. 转换成小写字母
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.4 MB, 在所有 C++ 提交中击败了5.44%的用户
 *
 */
string toLowerCase(string str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	}
	return str;
}