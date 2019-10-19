#include "Leetcode.h"

/*
 *
 *	62. 不同路径
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.3 MB, 在所有 C++ 提交中击败了48.62%的用户
 *
 */
int uniquePaths1(int m, int n)
{
	if (m <= 0 || n <= 0)
		return 0;
	if (m == 1 || n == 1)
		return 1;
	int i, j;
	vector< vector<int> > res;
	res.push_back(vector<int>(n, 1));
	res.push_back(vector<int>(n, 1));
	for (i = 1; i < m; ++i)
	{
		res[1][0] = res[0][0];
		for (j = 1; j < n; ++j)
			res[1][j] = res[1][j - 1] + res[0][j];
		res[0] = res[1];
	}
	return res[0][n - 1];
}

/*
 *
 *	62. 不同路径
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了73.34%的用户
 *  	内存消耗:		8.6 MB, 在所有 C++ 提交中击败了32.24%的用户
 *
 */
int uniquePaths2(int m, int n)
{
	if (m <= 0 || n <= 0)
		return 0;
	int i, j;
	vector< vector<int> > res;
	res.push_back(vector<int>(n, 1));
	for (i = 1; i < m; ++i)
	{
		res.push_back(vector<int>(n, 1));
		res[i][0] = res[i - 1][0];
		for (j = 1; j < n; ++j)
			res[i][j] = res[i - 1][j] + res[i][j - 1];
	}
	return res[m - 1][n - 1];
}

int uniquePaths(int m, int n)
{
	return uniquePaths1(m, n);
}