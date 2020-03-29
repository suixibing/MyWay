class Solution {
public:
    int FirstNotRepeatingChar(string str)
    {
        map<char, int> book;
        for (int i = 0; i < str.size(); ++i)
            ++book[str[i]];
        for (int i = 0; i < str.size(); ++i)
        {
            if (book[str[i]] == 1)
                return i;
        }
        return -1;
    }
};