#include "Leetcode.h"

/*
 *
 *	68. 文本左右对齐
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了80.36%的用户
 *  	内存消耗:		9 MB, 在所有 C++ 提交中击败了82.03%的用户
 *
 */
vector<string> fullJustify(vector<string>& words, int maxWidth)
{
	string tmp;
	int i = 0, j = 0, more;
	int count = 0, mark = 0, blank = 0;
	vector<string> res;
	while (i < words.size())
	{
		if (count + words[i].size() + i - mark <= maxWidth)
		{
			count += words[i].size();
			++i;
		}
		else
		{
			res.push_back(string());
			if (i - mark - 1 > 0)
			{
				tmp = string((maxWidth - count) / (i - mark - 1), ' ');
				more = (maxWidth - count) % (i - mark - 1);
			}

			while (i - mark - 1 > 0)
			{
				res[j] += words[mark++] + tmp;
				if (more-- > 0)
					res[j] += ' ';
			}
			res[j] += words[mark++];
			while (res[j].size() < maxWidth)
				res[j].push_back(' ');
			++j;
			count = 0;
		}
	}
	if (i - mark)
	{
		res.push_back(string());
		while (i - mark - 1)
		{
			res[j] += words[mark++] + ' ';
		}
		res[j] += words[mark];
		while (res[j].size() < maxWidth)
			res[j].push_back(' ');
	}

	return res;
}