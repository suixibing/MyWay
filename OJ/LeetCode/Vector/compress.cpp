#include "Leetcode.h"

/*
 *
 *	443. 压缩字符串
 *
 *  	执行用时:		16 ms, 在所有 C++ 提交中击败了24.35%的用户
 *  	内存消耗:		9.4 MB, 在所有 C++ 提交中击败了12.39%的用户
 *
 */
int compress1(vector<char>& chars)
{
	int i = 0, cnt = 1;
	chars.push_back(' ');
	while (i + 1 < chars.size())
	{
		while (i + cnt < chars.size() && chars[i + cnt] == chars[i])
			++cnt;
		chars.erase(chars.begin() + i, chars.begin() + i + cnt - 1);
		if (cnt > 1)
		{
			while (cnt > 0)
			{
				chars.insert(chars.begin() + i + 1, cnt % 10 + '0');
				cnt /= 10;
			}
			++i;
		}
		++i;
	}
	chars.pop_back();
	return chars.size();
}

/*
 *
 *	443. 压缩字符串
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了94.37%的用户
 *  	内存消耗:		9.5 MB, 在所有 C++ 提交中击败了8.54%的用户
 *
 */
int compress2(vector<char>& chars)
{
	int i, j, cnt;
	vector<char> tmp(chars);
	chars.clear();
	for (i = 0, cnt = 1; i < tmp.size(); ++i)
	{
		chars.push_back(tmp[i]);
		while (i + cnt < tmp.size() && tmp[i + cnt] == tmp[i])
			++cnt;
		i += cnt - 1;
		if (cnt > 1)
		{
			chars.push_back(cnt % 10 + '0');
			cnt /= 10;
			while (cnt)
			{
				chars.insert(chars.end() - 1, cnt % 10 + '0');
				cnt /= 10;
			}
			cnt = 1;
		}
	}
	return chars.size();
}

int compress(vector<char>& chars)
{
	return compress1(chars);
}