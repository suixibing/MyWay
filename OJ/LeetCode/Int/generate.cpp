#include "Leetcode.h"

/*
 *
 *	118. 杨辉三角
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了38.83%的用户
 *  	内存消耗:		8.6 MB, 在所有 C++ 提交中击败了72.81%的用户
 *
 */
vector< vector<int> > generate(int numRows)
{
	vector<int> line;
	vector< vector<int> > res;
	if (!numRows)
		return res;
	line.push_back(1);
	res.push_back(line);
	for (int i = 1; i < numRows; ++i)
	{
		line.push_back(1);
		for (int j = i - 1; j > 0; --j)
			line[j] += line[j - 1];
		res.push_back(line);
	}
	return res;
}