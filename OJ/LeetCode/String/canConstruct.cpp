#include "Leetcode.h"

/*
 *
 *	383. 赎金信
 *
 *  	执行用时:		16 ms, 在所有 C++ 提交中击败了91.87%的用户
 *  	内存消耗:		10.9 MB, 在所有 C++ 提交中击败了74.54%的用户
 *
 */
bool canConstruct(string ransomNote, string magazine)
{
	int book[128] = { 0 };
	for (int i = 0; i < magazine.size(); ++i)
		++book[magazine[i]];
	for (int i = 0; i < ransomNote.size(); ++i)
	{
		if (--book[ransomNote[i]] < 0)
			return false;
	}
	return true;
}