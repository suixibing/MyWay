#include <string>
#include <iostream>
using namespace std;

void Gapsort(string &str, int startPos, int gap)
{
    for (int i = startPos; i < str.size(); i += gap)
    {
        for (int j = i + gap; j < str.size(); j += gap)
        {
            if (str[i] > str[j])
                swap(str[i], str[j]);
        }
    }
}

int main()
{
    string str, tmp;
    
    while (cin >> str >> tmp)
    {
        str += tmp;
        Gapsort(str, 0, 2);
        Gapsort(str, 1, 2);
        for (auto & ch : str)
        {
            switch (ch)
            {
                case '1': ch = '8'; break;
                case '2': ch = '4'; break;
                case '3': ch = 'C'; break;
                case '4': ch = '2'; break;
                case '5': ch = 'A'; break;
                case '6': ch = '6'; break;
                case '7': ch = 'E'; break;
                case '8': ch = '1'; break;
                case '9': ch = '9'; break;
                case 'A': case 'a': ch = '5'; break;
                case 'B': case 'b': ch = 'D'; break;
                case 'C': case 'c': ch = '3'; break;
                case 'D': case 'd': ch = 'B'; break;
                case 'E': case 'e': ch = '7'; break;
                case 'f': case 'F': ch = 'F'; break;
            }
        }
        cout << str << endl;
    }
    
    return 0;
}