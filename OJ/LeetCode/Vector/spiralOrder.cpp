#include "Leetcode.h"

/*
 *
 *	54. 螺旋矩阵
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.6 MB, 在所有 C++ 提交中击败了58.52%的用户
 *
 */
vector<int> spiralOrder(vector< vector<int> >& matrix)
{
	vector<int> res;
	if (matrix.size() == 0)
		return res;
	int i, x = 0, y = 0, row = matrix.size(), col = matrix[0].size(), num = row * col;
	if (row == 1)
		return matrix[0];
	while (num)
	{
		if (col == 1)
			break;
		for (i = 1; num && i < col; ++i)
		{
			res.push_back(matrix[x][y]);
			--num;
			++y;
		}
		for (i = 1; num && i < row; ++i)
		{
			res.push_back(matrix[x][y]);
			--num;
			++x;
		}
		for (i = 1; num && i < col; ++i)
		{
			res.push_back(matrix[x][y]);
			--num;
			--y;
		}
		for (i = 1; num && i < row; ++i)
		{
			res.push_back(matrix[x][y]);
			--num;
			--x;
		}
		++x;
		++y;
		row -= 2;
		col -= 2;
	}
	for (i = 0; i < num; ++i)
		res.push_back(matrix[x + i][y]);
	return res;
}