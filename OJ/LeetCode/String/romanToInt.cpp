#include "Leetcode.h"

/*
 *
 *	13. 罗马数字转整数
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了94.18%的用户
 *  	内存消耗:		8.3 MB, 在所有 C++ 提交中击败了91.64%的用户
 *
 */
int romanToInt(string s)
{
	int res = 0, size = s.size();
	for (int i = 0; i < size; i++)
	{
		switch (s[i])
		{
		case 'I':
			if (i + 1 >= size)
				res += 1;
			else if (s[i + 1] == 'V')
			{
				res += 4;
				++i;
			}
			else if (s[i + 1] == 'X')
			{
				res += 9;
				++i;
			}
			else
				res += 1;
			break;
		case 'V':
			res += 5;
			break;
		case 'X':
			if (i + 1 >= size)
				res += 10;
			else if (s[i + 1] == 'L')
			{
				res += 40;
				++i;
			}
			else if (s[i + 1] == 'C')
			{
				res += 90;
				++i;
			}
			else
				res += 10;
			break;
		case 'L':
			res += 50;
			break;
		case 'C':
			if (i + 1 >= size)
				res += 100;
			else if (s[i + 1] == 'D')
			{
				res += 400;
				++i;
			}
			else if (s[i + 1] == 'M')
			{
				res += 900;
				++i;
			}
			else
				res += 100;
			break;
		case 'D':
			res += 500;
			break;
		case 'M':
			res += 1000;
			break;
		}
	}
	return res;
}