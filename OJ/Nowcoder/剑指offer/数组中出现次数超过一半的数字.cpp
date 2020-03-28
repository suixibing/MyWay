class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.empty())
            return 0;
        int i, mark = numbers[0], cnt = 1;
        for (i = 1; i < numbers.size(); ++i)
        {
            if (numbers[i] == numbers[i - 1])
                ++cnt;
            else
                --cnt;
            if (cnt <= 0)
            {
                cnt = 1;
                mark = numbers[i];
            }
        }
        for (i = cnt = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] == mark)
                ++cnt;
        }
        return (cnt > numbers.size() / 2) ? mark : 0;
    }
};