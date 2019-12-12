#include "Leetcode.h"

/*
 *
 *	121. 买卖股票的最佳时机
 *
 *  	执行用时:		852 ms, 在所有 C++ 提交中击败了18.03%的用户
 *  	内存消耗:		9.6 MB, 在所有 C++ 提交中击败了8.93%的用户
 *
 */
int maxProfit1(vector<int>& prices)
{
	int i, j, tmp, max = 0;
	for (i = 0; i < prices.size(); ++i)
	{
		tmp = prices[i];
		for (j = i + 1; j < prices.size(); ++j)
		{
			if (prices[j] - prices[i] > max)
			{
				max = prices[j] - prices[i];
			}
		}
	}
	return max;
}

/*
 *
 *	121. 买卖股票的最佳时机
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了98.35%的用户
 *  	内存消耗:		9.3 MB, 在所有 C++ 提交中击败了89.85%的用户
 *
 */
int maxProfit2(vector<int>& prices)
{
	int i, before, max = 0;
	if (!prices.empty())
	{
		before = prices[0];
		for (i = 1; i < prices.size(); ++i)
		{
			if (prices[i] - before > max)
				max = prices[i] - before;
			else if (prices[i] < before)
				before = prices[i];
		}
	}
	return max;
}

int maxProfit(vector<int>& prices)
{
	return maxProfit2(prices);
}