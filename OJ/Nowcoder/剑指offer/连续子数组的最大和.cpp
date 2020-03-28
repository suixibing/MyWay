class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int i, sum = array[0], maxsum = array[0];
        for (i = 1; i < array.size(); ++i)
        {
            if (sum < 0)
                sum = 0;
            sum += array[i];
            if (sum > maxsum)
                maxsum = sum;
        }
        return maxsum;
    }
};