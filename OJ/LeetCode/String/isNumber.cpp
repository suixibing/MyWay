#include "Leetcode.h"

/*
 *
 *	65. 有效数字
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了88.07%的用户
 *  	内存消耗:		8.3 MB, 在所有 C++ 提交中击败了68.46%的用户
 *
 */
bool isNumber(string s)
{
	int flag = 0, digit = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		switch (flag)
		{
		case 0:
			while (s[i] == ' ')
				++i;
			if (s[i] == '+' || s[i] == '-')
				++i;
			if (i < s.size() && s[i] >= '0' && s[i] <= '9')
			{
				++i;
				digit = 1;
				while (i < s.size() && s[i] >= '0' && s[i] <= '9')
					++i;
				if (i >= s.size())
					return true;
			}
			if (s[i] == '.')
				flag = 1;
			else if (s[i] == 'e' && i + 1 < s.size())
				flag = 2;
			else if (s[i] == ' ')
				flag = 3;
			else
				return false;
			break;
		case 1:
			if (s[i] >= '0' && s[i] <= '9')
			{
				++i;
				digit = 1;
				while (i < s.size() && s[i] >= '0' && s[i] <= '9')
					++i;
				while (i < s.size() && s[i] == ' ')
					++i;
				if (i >= s.size())
					return true;
			}
			if (s[i] == 'e' && i + 1 < s.size())
				flag = 2;
			else if (s[i] == ' ')
				flag = 3;
			else
				return false;
			break;
		case 2:
			if (s[i] == '+' || s[i] == '-')
				++i;
			if (s[i] >= '0' && s[i] <= '9')
			{
				++i;
				while (i < s.size() && s[i] >= '0' && s[i] <= '9')
					++i;
				if (i >= s.size() && digit == 1)
					return true;
			}
			if (s[i] == ' ' && s[i - 1] != 'e')
				flag = 3;
			else
				return false;
			break;
		case 3:
			while (i < s.size() && s[i] == ' ')
				++i;
			if (i < s.size() && digit == 1)
				return false;
			break;
		default:
			break;
		}
	}
	if (digit == 0)
		return false;
	return true;
}