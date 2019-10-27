#include "Leetcode.h"

/*
 *
 *	71. 简化路径
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了68.01%的用户
 *  	内存消耗:		8.9 MB, 在所有 C++ 提交中击败了100.00%的用户
 *
 */
string simplifyPath(string path)
{
	string tmp;
	int start = 1, i = 0, pos = 1;
	if (path[path.size() - 1] != '/')
		path.push_back('/');
	while (start + i < path.size())
	{
		if (path[start + i] == '/')
		{
			if (tmp.size() != 0)
			{
				if (tmp == ".." && pos == 1 || tmp == "." && pos == 1)
					pos = 1;
				else if (tmp == "..")
					pos = path.find_last_of('/', pos - 2) + 1;
				else if (tmp != ".")
				{
					copy(tmp.begin(), tmp.end(), path.begin() + pos);
					pos += tmp.size() + 1;
					path[pos - 1] = '/';
				}
			}
			start += i + 1;
			i = 0;
			tmp.clear();
		}
		else
			tmp.push_back(path[start + (i++)]);
	}
	path.erase(path.begin() + pos - 1, path.end());
	if (path.size() == 0)
		return "/";
	return path;
}