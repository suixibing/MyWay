class Solution {
public:
    void reOrderArray(vector<int> &array)
    {
        queue<int> left, right;
        for (auto t : array)
        {
            if (t % 2)
                left.push(t);
            else
                right.push(t);
        }
        int i = 0, tmp;
        while (!left.empty())
        {
            tmp = left.front();
            left.pop();
            array[i++] = tmp;
        }
        while (!right.empty())
        {
            tmp = right.front();
            right.pop();
            array[i++] = tmp;
        }
    }
};