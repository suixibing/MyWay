#include "Leetcode.h"

/*
 *
 *	58. 最后一个单词的长度
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.8 MB, 在所有 C++ 提交中击败了71.77%的用户
 *
 */
int lengthOfLastWord(string s)
{
	while (s.size() != 0 && s.find_last_of(' ') == s.size() - 1)
		s.pop_back();
	if (s.find_last_of(' ') >= 0)
		return s.size() - s.find_last_of(' ') - 1;
	else
		return s.size();
}