#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i, n, pos;
    string str;
    const char direction[4] = { 'N', 'E', 'S', 'W' };
    
    while (cin >> n >> str)
    {
        pos = 0;
        for (int i = 0; i < n; ++i)
        {
            if (str[i] == 'R')
                ++pos;
            else
                --pos;
            if (pos >= 4)
                pos = 0;
            else if (pos < 0)
                pos = 3;
        }
        cout << direction[pos] << endl;
    }
    
    return 0;
}