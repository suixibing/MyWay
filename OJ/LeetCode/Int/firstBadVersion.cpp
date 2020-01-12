#include "Leetcode.h"

/*
 *
 *	278. 第一个错误的版本
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.1 MB, 在所有 C++ 提交中击败了41.47%的用户
 *
 */
int badVersion;
bool isBadVersion(int version)
{
	return version == badVersion;
}
int firstBadVersion(int n)
{
	int l = 0, r = n - 1, mid;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (isBadVersion(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}