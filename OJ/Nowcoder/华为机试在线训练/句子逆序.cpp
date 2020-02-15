#include <string>
#include <iostream>
using namespace std;

int main()
{
    string line;
    
    while (getline(cin, line))
    {
        char *p = const_cast<char*>(line.c_str());
        for (int i = line.size() - 2; i >= 0; --i)
        {
            if (p[i] == ' ' && p[i + 1] != ' ')
            {
                p[i] = '\0';
                printf("%s ", p + i + 1);
            }
        }
        printf("%s\n", p);
    }
    
    return 0;
}