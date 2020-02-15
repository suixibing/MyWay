#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    char ch;
    bitset<128> book;
    
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            printf("%d\n", static_cast<int>(book.count()));
            book.reset();
        }
        else if (!book[ch])
            book.set(ch);
    }
    
    return 0;
}