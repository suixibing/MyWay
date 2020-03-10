#include <string>
#include <cctype>
#include <iostream>
using namespace std;

void Encrypt(string password, string result)
{
    result = password;
    for (auto & i : result)
    {
        if (isdigit(i))
            i = (i + 1 - '0') % 10 + '0';
        else if (isupper(i))
            i = (i + 1 - 'A') % 26 + 'a';
        else if (islower(i))
            i = (i + 1 - 'a') % 26 + 'A';
    }
    cout << result << endl;
}

void unEncrypt(string password, string result)
{
    result = password;
    for (auto & i : result)
    {
        if (isdigit(i))
            i = (i + 9 - '0') % 10 + '0';
        else if (isupper(i))
            i = (i + 25 - 'A') % 26 + 'a';
        else if (islower(i))
            i = (i + 25 - 'a') % 26 + 'A';
    }
    cout << result << endl;
}

int main()
{
    string input1, input2, result;
    
    while (cin >> input1 >> input2)
    {
        Encrypt(input1, result);
        unEncrypt(input2, result);
    }
    
    return 0;
}