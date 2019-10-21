#include "Leetcode.h"

/*
 *
 *	64. 最小路径和
 *
 *  	执行用时:		12 ms, 在所有 C++ 提交中击败了74.23%的用户
 *  	内存消耗:		10.4 MB, 在所有 C++ 提交中击败了97.53%的用户
 *
 */
int minPathSum(vector< vector<int> >& grid)
{
	if (grid.size() == 0 || grid.size() == 1 && grid[0].size() == 0)
		return 0;
	int i, j, tmp;
	for (j = 1; j < grid[0].size(); ++j)
		grid[0][j] += grid[0][j - 1];
	for (i = 1; i < grid.size(); ++i)
	{
		for (j = 0; j < grid[0].size(); ++j)
		{
			if (j == 0)
				grid[i][j] += grid[i - 1][j];
			else
				grid[i][j] += (grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1]);
		}
	}
	return grid[grid.size() - 1][grid[0].size() - 1];
}