#include <string>
#include <iostream>
using namespace std;

int main()
{
    string str;
    
    while (cin >> str)
    {
        for (auto it = str.rbegin(); it != str.rend(); ++it)
            cout << *it;
        putchar('\n');
    }
    
    return 0;
}