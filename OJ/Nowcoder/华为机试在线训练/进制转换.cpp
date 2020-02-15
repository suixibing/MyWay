#include <string>
#include <iostream>
using namespace std;

int main()
{
    string num;
    
    while (cin >> num)
    {
        int res = 0;
        for (int i = 2; i < num.size(); ++i)
        {
            if (num[i] >= 'A' && num[i] <= 'F')
                res = res * 16 + num[i] - 'A' + 10;
            else if (num[i] >= 'a' && num[i] <= 'f')
                res = res * 16 + num[i] - 'a' + 10;
            else
                res = res * 16 + num[i] - '0';
        }
        printf("%d\n", res);
    }
    
    return 0;
}