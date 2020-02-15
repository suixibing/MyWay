#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    
    while (getline(cin, line))
        printf("%d\n", line.size() - line.find_last_of(' ') - 1);
    
    return 0;
}