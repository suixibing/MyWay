#include "Leetcode.h"

/*
 *
 *	977. 有序数组的平方
 *
 *  	执行用时:		56 ms, 在所有 C++ 提交中击败了86.28%的用户
 *  	内存消耗:		17.4 MB, 在所有 C++ 提交中击败了5.08%的用户
 *
 */
vector<int> sortedSquares(vector<int>& A)
{
	vector<int> ret;
	for (int i = 0; i < A.size(); ++i)
		ret.push_back(A[i] * A[i]);
	sort(ret.begin(), ret.end());
	return ret;
}