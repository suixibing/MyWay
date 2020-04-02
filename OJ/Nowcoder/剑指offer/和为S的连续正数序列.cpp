class Solution {
public:
    vector< vector<int> > FindContinuousSequence(int sum)
    {
        int left = 1, right = 0, tmp = 0;
        vector<int> book(sum - 1);
        vector< vector<int> > res;
        for (int i = 0; i < book.size(); ++i)
            book[i] = i + 1;
        while (left < book.size())
        {
            if (tmp < sum)
                tmp += ++right;
            else
            {
                if (tmp > sum)
                {
                    tmp -= left++;
                    while (tmp > sum)
                        tmp -= right--;
                }
                if (tmp == sum)
                {
                    res.push_back(vector<int>(book.begin() + left - 1, book.begin() + right));
                    tmp -= left++;
                }
            }
        }
        return res;
    }
};