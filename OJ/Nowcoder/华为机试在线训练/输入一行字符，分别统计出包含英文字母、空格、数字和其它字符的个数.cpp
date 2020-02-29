#include <cctype>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string line;
    
    while (getline(cin, line))
    {
        int alpha = 0, num = 0, space = 0, others = 0;
        for (int i = 0; i < line.size(); ++i)
        {
            if (isalpha(line[i]))
                ++alpha;
            else if (isdigit(line[i]))
                ++num;
            else if (isspace(line[i]))
                ++space;
            else
                ++others;
        }
        cout << alpha << endl;
        cout << space << endl;
        cout << num << endl;
        cout << others << endl;
    }
    
    return 0;
}