class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2)
    {
        map<int, int> book;
        *num1 = *num2 = book[0];
        for (auto t : data)
            ++book[t];
        for (auto t : data)
        {
            if (book[t] == 1)
            {
                if (book[*num1] != 1)
                    *num1 = t;
                else
                {
                    *num2 = t;
                    return;
                }
            }
        }
    }
};