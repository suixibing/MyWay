#include "Leetcode.h"

/*
 *
 *	56. 合并区间
 *
 *  	执行用时:		24 ms, 在所有 C++ 提交中击败了88.11%的用户
 *  	内存消耗:		12.4 MB, 在所有 C++ 提交中击败了5.08%的用户
 *
 */
vector< vector<int> > merge1(vector< vector<int> >& intervals)
{
	if (intervals.size() < 2)
		return intervals;
	int i, cnt = 0;
	sort(intervals.begin(), intervals.end());
	for (i = 0; i < intervals.size(); ++i)
	{
		if (intervals[cnt][1] < intervals[i][0])
			intervals[++cnt] = intervals[i];
		else
			intervals[cnt][1] = intervals[cnt][1] > intervals[i][1] ? intervals[cnt][1] : intervals[i][1];
	}
	intervals.erase(intervals.begin() + cnt + 1, intervals.end());
	return intervals;
}

/*
 *
 *	56. 合并区间
 *
 *  	执行用时:		32 ms, 在所有 C++ 提交中击败了61.86%的用户
 *  	内存消耗:		12.5 MB, 在所有 C++ 提交中击败了5.08%的用户
 *
 */
vector< vector<int> > merge2(vector< vector<int> >& intervals)
{
	int i, j;
	vector< vector<int> > res;
	sort(intervals.begin(), intervals.end());
	for (i = 0; i < intervals.size(); i = j + 1)
	{
		vector<int> tmp;
		tmp.push_back(intervals[i][0]);
		for (j = i; j + 1 < intervals.size(); ++j)
		{
			if (intervals[j][1] < intervals[j + 1][0])
				break;
			else
				intervals[j + 1][1] = intervals[j][1] > intervals[j + 1][1] ? intervals[j][1] : intervals[j + 1][1];
		}
		tmp.push_back(intervals[j][1]);
		res.push_back(tmp);
	}
	return res;
}

vector< vector<int> > merge(vector< vector<int> >& intervals)
{
	return merge1(intervals);
}