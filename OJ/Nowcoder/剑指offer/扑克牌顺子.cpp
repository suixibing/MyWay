class Solution {
public:
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.size() != 5)
            return false;
        int max = -1, min = 14, flag = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] < 0 || numbers[i] > 13)
                return false;
            if (numbers[i] == 0)
                continue;
            if ((flag >> numbers[i]) & 1)
                return false;
            flag |= (1 << numbers[i]);
            if (numbers[i] > max)
                max = numbers[i];
            if (numbers[i] < min)
                min = numbers[i];
            if (max - min > 4)
                return false;
        }
        return true;
    }
};