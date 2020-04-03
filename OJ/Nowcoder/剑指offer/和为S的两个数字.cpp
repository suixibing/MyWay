class Solution {
public:
    vector<int> FindNumbersWithSum(const vector<int> &array, int sum)
    {
        vector<int> res;
        int l = 0, r = array.size() - 1;
        while (l < r)
        {
            if (array[l] + array[r] == sum)
            {
                res.push_back(array[l]);
                res.push_back(array[r]);
                break;
            }
            if (array[l] + array[r] > sum)
                --r;
            else
                ++l;
        }
        return res;
    }
};