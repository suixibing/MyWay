#include "Leetcode.h"

/*
 *
 *	171. Excel表列序号
 *
 *  	执行用时 :		4 ms, 在所有 C++ 提交中击败了80.55%的用户
 *  	内存消耗 :		8.2 MB, 在所有 C++ 提交中击败了63.96%的用户
 *
 */
int titleToNumber(string s)
{
	unsigned int ret = 0;
	for (auto & i : s)
		ret = ret * 26 + i - 'A' + 1;
	return ret;
}