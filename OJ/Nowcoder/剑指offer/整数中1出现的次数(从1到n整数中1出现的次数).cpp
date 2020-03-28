class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n == 1 || n == 0)
            return n;
        int res = NumberOf1Between1AndN_Solution(n - 1);
        while (n)
        {
            if (n % 10 == 1)
                ++res;
            n /= 10;
        }
        return res;
    }
};