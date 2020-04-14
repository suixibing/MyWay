class Solution {
    int subfunc(vector<int> &data, int left, int right)
    {
        if (left >= right)
            return 0;
        int mid = left + (right - left) / 2;
        int ret = subfunc(data, left, mid) + subfunc(data, mid + 1, right);
        vector<int> tmp(data.begin() + left, data.begin() + right + 1);
        int i = 0, l = mid - left, r = right - left, m = l;
        for (int i = right; i >= left; --i)
        {
            if (l >= 0 && r > m)
            {
                if (tmp[l] > tmp[r])
                {
                    data[i] = tmp[l--];
                    ret = (ret + (r - m) % 1000000007) % 1000000007;
                }
                else
                    data[i] = tmp[r--];
            }
            else if (l >= 0)
                data[i] = tmp[l--];
            else
                data[i] = tmp[r--];
        }
        return ret;
    }
public:
    int InversePairs(vector<int> data)
    {
        return subfunc(data, 0, data.size() - 1);
    }
};