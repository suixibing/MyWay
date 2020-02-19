#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int i, n, cnt;
    string str, output;
    while (cin >> n)
    {
        map<string, int> book;
        vector<int> flag(26, 0);
        for (i = 0; i < n; ++i)
        {
            cin >> str;
            ++book[str];
        }
        cin >> str >> n;
        cnt = 0;
        output.clear();
        for (auto & k : str)
            ++flag[k - 'a'];
        for (auto & k : book)
        {
            if (k.first == str)
                continue;
            vector<int> tmp(26, 0);
            for (auto & j : k.first)
                ++tmp[j - 'a'];
            if (tmp == flag)
            {
                if (cnt < n && n <= cnt + k.second)
                    output = k.first;
                cnt += k.second;
            }
        }
        cout << cnt << endl;
        if (!output.empty())
            cout << output << endl;
    }
    
    return 0;
}