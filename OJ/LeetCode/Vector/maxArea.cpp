#include "Leetcode.h"

/*
 *
 *	11. 盛最多水的容器
 *
 *  	执行用时:		1728 ms, 在所有 C++ 提交中击败了8.36%的用户
 *  	内存消耗:		9.9 MB, 在所有 C++ 提交中击败了59.14%的用户
 *
 */
int maxArea(vector<int>& height) 
{
	int i, j, sum, length, maxarea = 0, size = height.size();
        	for (i = 0; i < size; i++)
        	{
            		for (j = i + 1; j < size; j++)
            		{
                		length = height[i] < height[j] ? height[i] : height[j];
                		sum = length * (j - i);
                		if (sum > maxarea)
                    			maxarea = sum;
            		}
        	}
        	return maxarea;
}