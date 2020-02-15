#include <bitset>
#include <iostream>
using namespace std;

int main()
{
    int num;
    
    while (scanf("%d", &num) != EOF)
    {
        int newNum = 0;
        bitset<10> book;
        
        while (num)
        {
            if (!book[num % 10])
            {
                book.set(num % 10);
                newNum = newNum * 10 + num % 10;
            }
            num /= 10;
        }
        printf("%d\n", newNum);
    }
    
    return 0;
}