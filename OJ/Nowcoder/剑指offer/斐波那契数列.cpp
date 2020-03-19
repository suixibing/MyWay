class Solution {
public:
    int Fibonacci(int n)
    {
        int f1 = 0, f2 = 1, f3;
        for (int i = 0; i < n; ++i)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f1;
    }
};