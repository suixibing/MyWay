class Solution {
public:
    int StrToInt(string str)
    {
        int flag = 1;
        long long num = 0;
        if (str[0] == '-')
            flag = -1;
        if (isdigit(str[0]))
            num = str[0] - '0';
        else if (isalpha(str[0]))
            return 0;
        for (int i = 1; i < str.size(); ++i)
        {
            if (isalpha(str[i]))
                return 0;
            num = num * 10 + str[i] - '0';
        }
        num *= flag;
        if (num > 2147483647 || num < -2147483648)
            return 0;
        return num;
    }
};