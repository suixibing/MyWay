#include "Leetcode.h"

/*
 *
 *	189. 旋转数组27. 移除元素
 *
 *  	执行用时 :		20 ms, 在所有 C++ 提交中击败了87.52%的用户
 *  	内存消耗 :		9.5 MB, 在所有 C++ 提交中击败了46.82%的用户
 *
 */
void rotate(vector<int>& nums, int k) 
{
    vector<int> res(nums);
    if (k > nums.size())
        k = k % nums.size();
    for (int i = 0; i < nums.size(); ++i)
        res[(i + k) % nums.size()] = nums[i];
    nums = res;
}