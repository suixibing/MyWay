#include "Leetcode.h"

/*
 *
 *	77. 组合
 *
 *  	执行用时:		616 ms, 在所有 C++ 提交中击败了16.24%的用户
 *  	内存消耗:		166.7 MB, 在所有 C++ 提交中击败了19.21%的用户
 *
 */
void subCombine(vector<int> arr, int pos, int n, int k, vector< vector<int> >& ans)
{
	if (k == arr.size())
	{
		ans.push_back(arr);
		return;
	}
	for (int i = pos; i <= n; ++i)
	{
		arr.push_back(i);
		subCombine(arr, i + 1, n, k, ans);
		arr.pop_back();
	}
}
vector< vector<int> > combine(int n, int k)
{
	vector<int> arr;
	vector< vector<int> > res;
	subCombine(arr, 1, n, k, res);
	return res;
}