#include <string>
#include <iostream>
using namespace std;

void print(string & str)
{
    for (int i = 0; i < str.size(); i += 8)
    {
        if (i + 8 < str.size())
            cout << str.substr(i, 8) << endl;
        else
        {
            int size = str.size() - i;
            cout << str.substr(i, size);
            while (size++ != 8)
                putchar('0');
            putchar('\n');
        }
    }
}

int main()
{
    string str;
    
    while (cin >> str)
        print(str);
    
    return 0;
}