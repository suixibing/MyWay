#include "Leetcode.h"

/*
 *
 *	303. 区域和检索 - 数组不可变
 *
 *  	执行用时:		232 ms, 在所有 C++ 提交中击败了26.06%的用户
 *  	内存消耗:		17.3 MB, 在所有 C++ 提交中击败了20.81%的用户
 *
 */
class NumArray {
private:
	vector<int> m_nums;
public:
	NumArray(vector<int>& nums)
	{
		m_nums = nums;
	}

	int sumRange(int i, int j)
	{
		int res = 0;
		while (i <= j)
			res += m_nums[i++];
		return res;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */