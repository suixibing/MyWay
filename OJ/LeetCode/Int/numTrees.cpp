#include "Leetcode.h"

/*
 *
 *	96. 不同的二叉搜索树
 *
 *  	执行用时:		560 ms, 在所有 C++ 提交中击败了6.99%的用户
 *  	内存消耗:		72.7 MB, 在所有 C++ 提交中击败了5.19%的用户
 *
 */
int numTrees_1(int n)
{
	if (n <= 1)
		return 1;
	int i, sum = 0;
	map<int, int> book;
	for (i = 0; i < n; ++i)
	{
		if (!book[i])
			book[i] = numTrees(i);
		if (!book[n - i - 1])
			book[n - i - 1] = numTrees(n - i - 1);
		sum += book[i] * book[n - i - 1];
	}
	return sum;
}

/*
 *
 *	96. 不同的二叉搜索树
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.3 MB, 在所有 C++ 提交中击败了50.23%的用户
 *
 */
int numTrees_2(int n) 
{
	int s[n + 1] = { 0 };
	s[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= i; k++)
			s[i] += s[i - k] * s[k - 1];
	}
	return s[n];
}

int numTrees(int n)
{
	return numTrees_2(n);
}