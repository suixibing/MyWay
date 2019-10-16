#include "Leetcode.h"

/*
 *
 *	59. 螺旋矩阵 II
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了94.59%的用户
 *  	内存消耗:		9 MB, 在所有 C++ 提交中击败了36.16%的用户
 *
 */
vector< vector<int> > generateMatrix(int n)
{
	int i, row = 0, col = 0, num = 1, max = n * n;
	vector< vector<int> > res;
	for (i = 0; i < n; ++i)
		res.push_back(vector<int>(n, 1));
	for (--n; n > 0; n -= 2)
	{
		for (i = 0; num <= max && i < n; ++i)
			res[row][col++] = num++;
		for (i = 0; num <= max && i < n; ++i)
			res[row++][col] = num++;
		for (i = 0; num <= max && i < n; ++i)
			res[row][col--] = num++;
		for (i = 0; num <= max && i < n; ++i)
			res[row--][col] = num++;
		++row;
		++col;
	}
	if (num <= max)
		res[row][col] = num;
	return res;
}