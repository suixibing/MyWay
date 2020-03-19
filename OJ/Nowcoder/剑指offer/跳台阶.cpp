class Solution {
public:
    int jumpFloor(int number)
    {
        if (number == 0)
            return 0;
        int f1 = 1, f2 = 1, f3;
        for (int i = 0; i < number; ++i)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f1;
    }
};