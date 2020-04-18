#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int n, res;
    string str;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> str;
            vector<int> data;
            map<char, int> book;
            for (int j = 0; j < str.size(); ++j)
                ++book[str[j]];
            for (auto &iter : book)
                data.push_back(iter.second);
            res = 0;
            sort(data.begin(), data.end(), greater<int>());
            for (int j = 0; j < data.size(); ++j)
                res += (26 - j) * data[j];
            cout << res << endl;
        }
    }
    return 0;
}