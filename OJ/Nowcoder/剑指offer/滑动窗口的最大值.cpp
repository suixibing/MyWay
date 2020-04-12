class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if (num.size() < size || size == 0)
            return vector<int>();
        int i, j;
        vector<int> window(num.begin(), num.begin() + size), ret;
        sort(window.begin(), window.end());
        ret.push_back(window.back());
        for (i = size; i < num.size(); ++i)
        {
            window.erase(find(window.begin(), window.end(), num[i - size]));
            for (j = 0; j < size; ++j)
            {
                if (window[j] >= num[i])
                {
                    window.insert(window.begin() + j, num[i]);
                    break;
                }
            }
            if (j >= size)
                window.push_back(num[i]);
            ret.push_back(window.back());
        }
        return ret;
    }
};