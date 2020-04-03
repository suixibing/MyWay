class Solution {
public:
    string LeftRotateString(const string &str, int n)
    {
        if (str.empty())
            return str;
        n %= str.size();
        string res;
        for (int i = n; i < str.size(); ++i)
            res.push_back(str[i]);
        for (int i = 0; i < n; ++i)
            res.push_back(str[i]);
        return res;
    }
};