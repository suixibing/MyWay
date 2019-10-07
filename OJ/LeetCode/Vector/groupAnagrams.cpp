#include "Leetcode.h"

/*
 *
 *	49. 字母异位词分组
 *
 *  	执行用时:		2108 ms, 在所有 C++ 提交中击败了5.01%的用户
 *  	内存消耗:		19.5 MB, 在所有 C++ 提交中击败了57.56%的用户
 *
 */
vector< vector<string> > groupAnagrams(vector<string>& strs)
{
	int i, j;
	vector< vector<string> > res;
	vector< vector<char> > book;
	for (i = 0; i < strs.size(); ++i)
	{
		vector<char> tmpBook(26, 0);
		for (j = 0; j < strs[i].size(); ++j)
			++tmpBook[strs[i][j] - 'a'];
		for (j = 0; j < book.size(); ++j)
			if (book[j] == tmpBook)
				break;
		if (j < book.size())
			res[j].push_back(strs[i]);
		else
		{
			vector<string> tmpVec;
			tmpVec.push_back(strs[i]);
			book.push_back(tmpBook);
			res.push_back(tmpVec);
		}
	}
	return res;
}

// 超时
vector< vector<string> > groupAnagrams(vector<string>& strs)
{
	char book[26 * 2];
	int i, j, k, flag;
	vector< vector<string> > res;
	for (i = 0; i < strs.size(); ++i)
	{
		if (strs[i] == "quittttttttttttt")
			continue;
		vector<string> tmp;
		for (j = 0; j < 26 * 2; ++j)
			book[j] = 0;
		for (j = 0; j < strs[i].size(); ++j)
			++book[strs[i][j] - 'a'];
		tmp.push_back(strs[i]);
		k = i + 1;
		for (j = 0; k < strs.size(); ++j)
		{
			if (strs[k].size() != strs[i].size() || strs[k] != strs[i] && !book[strs[k][j] - 'a'])
			{
				for (j = 0; j < 26; ++j)
					book[j + 26] = 0;
				++k;
				j = -1;
			}
			else if (strs[k] != strs[i])
			{
				++book[strs[k][j] - 'a' + 26];
				if (j + 1 == strs[i].size())
				{
					for (j = 0, flag = 1; j < 26; ++j)
					{
						if (book[j] != book[j + 26])
							flag = 0;
						book[j + 26] = 0;
					}
					if (flag)
					{
						tmp.push_back(strs[k]);
						strs[k] = "quittttttttttttt";
					}
					++k;
					j = -1;
				}
			}
			else
			{
				for (j = 0; j < 26; ++j)
					book[j + 26] = 0;
				tmp.push_back(strs[k]);
				strs[k] = "quittttttttttttt";
				++k;
				j = -1;
			}
		}
		if (tmp.size() > 0)
			res.push_back(tmp);
	}
	return res;
}