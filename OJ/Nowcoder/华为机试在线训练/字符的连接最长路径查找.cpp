#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    
    while (cin >> n)
    {
        vector<string> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        sort(v.begin(), v.end());
        for (auto & i : v)
            cout << i << endl;
    }
    
    return 0;
}