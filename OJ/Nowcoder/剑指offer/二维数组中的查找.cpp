class Solution {
public:
    bool Find(int target, vector<vector<int> > array)
    {
        int i = 0, j = array[i].size() - 1;
        while (i < array.size() && j >= 0)
        {
            cout << array[i][j] << " ";
            if (array[i][j] == target)
                return true;
            if (i + 1 < array.size() && array[i + 1][j] <= target)
                ++i;
            else
                --j;
        }
        return false;
    }
};