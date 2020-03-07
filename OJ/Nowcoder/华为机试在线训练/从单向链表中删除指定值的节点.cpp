#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, tmp, pos;
    
    while (cin >> n)
    {
        list<int> l;
        cin >> tmp;
        l.push_back(tmp);
        for (int i = 1; i < n; ++i)
        {
            cin >> tmp >> pos;
            l.insert(++find(l.begin(), l.end(), pos), tmp);
        }
        cin >> tmp;
        l.erase(find(l.begin(), l.end(), tmp));
        for (auto j = l.begin(); j != l.end(); ++j)
            cout << *j << ' ';
        cout << endl;
    }
    
    return 0;
}