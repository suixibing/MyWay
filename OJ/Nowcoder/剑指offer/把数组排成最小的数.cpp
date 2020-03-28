class Solution {
public:
    string PrintMinNumber(vector<int> numbers)
    {
        string res("");
        sort(numbers.begin(), numbers.end(), [](int a, int b)
        {
            return to_string(a) + to_string(b) < to_string(b) + to_string(a);
        });
        for (auto &t : numbers)
            res += to_string(t);
        return res;
    }
};