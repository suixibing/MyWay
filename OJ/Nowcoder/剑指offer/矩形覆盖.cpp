class Solution {
public:
    int rectCover(int number)
    {
        if (number < 4)
            return number;
        return rectCover(number - 1) + rectCover(number - 2);
    }
};