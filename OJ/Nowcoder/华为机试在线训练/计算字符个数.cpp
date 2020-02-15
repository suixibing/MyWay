#include <iostream>
#include <string>
using namespace std;

int main()
{
    char c;
    int cnt = 0;
    string line;
    
    getline(cin, line);
    cin >> c;
    if (c >= 'a' || c <= 'z')
        c = c - 'a' + 'A';
    for (auto & i : line)
    {
        if (i == c || i - 'a' + 'A' == c)
            ++cnt;
    }
    printf("%d\n", cnt);
    
    return 0;
}