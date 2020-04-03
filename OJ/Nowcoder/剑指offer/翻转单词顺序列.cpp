class Solution {
private:
    void _reverse(string &str, size_t left, size_t right)
    {
        while (left < right)
            swap(str[left++], str[right--]);
    }
public:
    string ReverseSentence(string str)
    {
        if (str.find(" ") == string::npos)
            return str;
        size_t tmp, pos = 0;
        while (pos < str.size() && str[pos] == ' ')
            ++pos;
        while ((tmp = str.find(" ", pos)) != string::npos)
        {
            _reverse(str, pos, tmp - 1);
            pos = tmp + 1;
            while (pos < str.size() && str[pos] == ' ')
                ++pos;
        }
        _reverse(str, pos, str.size() - 1);
        _reverse(str, 0, str.size() - 1);
        return str;
    }
};