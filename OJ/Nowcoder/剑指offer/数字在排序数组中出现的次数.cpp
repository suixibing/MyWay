class Solution {
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        int cnt = 0, mid, left = 0, right = data.size() - 1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (data[mid] == k)
                break;
            else if (data[mid] > k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (mid < data.size() && data[mid] == k)
        {
            left = right = 0;
            while (mid - left - 1 >= 0 && data[mid - left - 1] == k)
                ++left;
            while (mid + right + 1 < data.size() && data[mid + right + 1] == k)
                ++right;
            cnt = left + right + 1;
        }
        return cnt;
    }
};