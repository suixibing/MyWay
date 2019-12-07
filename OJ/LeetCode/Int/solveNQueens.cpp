#include "Leetcode.h"

/*
 *
 *	51. N皇后
 *
 *  	执行用时 :		12 ms, 在所有 C++ 提交中击败了73.15%的用户
 *  	内存消耗 :		9.7 MB, 在所有 C++ 提交中击败了98.54%的用户
 *
 */
static bool judgeTrue(vector<string> &str, int x, int y)
{
	int i, j;
	for (i = 0; i < x; ++i)
		if (str[i][y] == 'Q')
			return false;
	for (i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
		if (str[i][j] == 'Q')
			return false;
	for (i = x - 1, j = y + 1; i >= 0 && j < str.size(); --i, ++j)
		if (str[i][j] == 'Q')
			return false;
	return true;
}
static bool subfunc(vector< string > &str, int cnt, int n, vector< vector<string> > &ret)
{
	if (cnt == n)
		return true;
	for (int i = 0; i < n; ++i)
	{
		if (judgeTrue(str, cnt, i))
		{
			str[cnt][i] = 'Q';
			if (subfunc(str, cnt + 1, n, ret))
				ret.push_back(str);
			str[cnt][i] = '.';
		}
	}
	return false;
}
vector< vector<string> > solveNQueens(int n)
{
	string tmp(n, '.');
	vector<string> res(n, tmp);
	vector< vector<string> > ret;
	subfunc(res, 0, n, ret);
	return ret;
}