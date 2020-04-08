class Solution {
public:
    bool isNumeric(char* string)
    {
        int flag = 0; // 0表示开始
        if (*string == '+' || *string == '-')
            ++string; // 舍去开始的符号
        while (*string != '\0')
        {
            if (flag == 0 && *string == '.')
                flag = 1; // 1表示有了小数点
            else if (flag >= 0 && flag <= 1 && (*string == 'e' || *string =='E'))
                flag = 2; // 2表示有了E
            else if (flag == 2 && (*string == '+' || *string == '-'))
                flag = 3; // 3表示有了E后的符号
            else if (flag == 2)
                flag = 4; // 4表示进入了E后的正数阶段
            else if (isdigit(*string))
                ; // 什么都不用做
            else 
                break;
            ++string;
        }
        return flag != 2 && *string == '\0';
    }
};