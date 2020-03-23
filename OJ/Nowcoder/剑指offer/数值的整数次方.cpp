class Solution {
public:
    double Power(double base, int exponent)
    {
        if (exponent < 0)
            return 1 / Power(base, -exponent);
        if (exponent == 0)
            return 1;
        double ret = Power(base, exponent / 2);
        return (exponent % 2) ? ret * ret * base : ret * ret;
    }
};