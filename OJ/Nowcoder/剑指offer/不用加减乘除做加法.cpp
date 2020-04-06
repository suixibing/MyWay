class Solution {
public:
    int Add(int num1, int num2)
    {
        if (num2 > 0)
        {
            while (num2--)
                ++num1;
        }
        else
        {
            while (num2++)
                --num1;
        }
        return num1;
    }
};