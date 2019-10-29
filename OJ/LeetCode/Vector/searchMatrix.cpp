#include "Leetcode.h"

/*
 *
 *	74. 搜索二维矩阵
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了99.44%的用户
 *  	内存消耗:		9.7 MB, 在所有 C++ 提交中击败了92.57%的用户
 *
 */
bool searchMatrix(vector< vector<int> >& matrix, int target)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int i = 0, j = 0, m = matrix.size(), n = matrix[0].size();
	while (i < m && j < n)
	{
		if (i + 1 < m && matrix[i + 1][j] <= target)
			++i;
		else if (matrix[i][j] < target)
			++j;
		else if (matrix[i][j] == target)
			return true;
		else
			break;
	}
	return false;
}