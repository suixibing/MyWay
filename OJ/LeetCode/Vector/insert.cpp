#include "Leetcode.h"

/*
 *
 *	57. 插入区间
 *
 *  	执行用时:		1332 ms, 在所有 C++ 提交中击败了6.04%的用户
 *  	内存消耗:		12.5 MB, 在所有 C++ 提交中击败了5.23%的用户
 *
 */
vector< vector<int> > insert(vector< vector<int> >& intervals, vector<int>& newInterval)
{
	if (intervals.size() < 1 || newInterval[0] > intervals[intervals.size() - 1][1])
	{
		intervals.push_back(newInterval);
		return intervals;
	}
	else if (intervals[0][0] > newInterval[1])
	{
		intervals.insert(intervals.begin(), newInterval);
		return intervals;
	}
	if (intervals[0][0] == newInterval[1])
	{
		intervals[0][0] = newInterval[0];
		return intervals;
	}
	intervals[0][0] = min(intervals[0][0], newInterval[0]);
	for (int i = 0; i < intervals.size(); ++i)
	{
		if (newInterval[0] <= intervals[i][1])
		{
			intervals[i][0] = min(intervals[i][0], newInterval[0]);
			intervals[i][1] = max(intervals[i][1], newInterval[1]);
			while (i + 1 < intervals.size() && intervals[i][1] >= intervals[i + 1][0])
			{
				intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
				intervals.erase(intervals.begin() + i + 1);
			}
			break;
		}
		if (newInterval[0] > intervals[i][1] && newInterval[1] < intervals[i + 1][0])
		{
			intervals.insert(intervals.begin() + i + 1, newInterval);
			break;
		}
	}
	return intervals;
}