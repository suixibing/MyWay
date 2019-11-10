#include "Leetcode.h"

/*
 *
 *	85. 最大矩形
 *
 *  	执行用时:		32 ms, 在所有 C++ 提交中击败了54.59%的用户
 *  	内存消耗:		10.4 MB, 在所有 C++ 提交中击败了98.86%的用户
 *
 */
int maximalRectangle(vector< vector<char> >& matrix)
{
	int i, j, res = 0;
	for (i = 1; i < matrix.size(); ++i)
	{
		for (j = 0; j < matrix[0].size(); ++j)
		{
			if (matrix[i][j] != '0')
				matrix[i][j] += matrix[i - 1][j] - '0';
		}
	}
	int left, right;
	for (i = 0; i < matrix.size(); ++i)
	{
		for (j = 0; j < matrix[0].size(); ++j)
		{
			if (j == 0 || matrix[i][j] > matrix[i][j - 1])
				left = right = j;
			while (left - 1 >= 0 && matrix[i][j] <= matrix[i][left - 1])
				--left;
			while (right + 1 < matrix[i].size() && matrix[i][j] <= matrix[i][right + 1])
				++right;
			if (res < (matrix[i][j] - '0') * (right - left + 1))
				res = (matrix[i][j] - '0') * (right - left + 1);
		}
	}
	return res;
}