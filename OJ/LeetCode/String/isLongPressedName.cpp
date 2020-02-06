#include "Leetcode.h"

/*
 *
 *	925. 长按键入
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了39.23%的用户
 *  	内存消耗:		8.5 MB, 在所有 C++ 提交中击败了40.94%的用户
 *
 */
bool isLongPressedName(string name, string typed)
{
	int i = 0, j = 0;
	while (i < name.size())
	{
		if (i < name.size() && j < typed.size() && name[i] == typed[j])
		{
			++i;
			++j;
		}
		else if (i - 1 >= 0 && j < typed.size() && name[i - 1] == typed[j])
			++j;
		else
			return false;
	}
	return true;
}