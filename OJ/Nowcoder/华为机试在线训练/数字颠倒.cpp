#include <iostream>
using namespace std;

int main()
{
    int num;
    
    while (scanf("%d", &num) != EOF)
    {
        while (num)
        {
            printf("%d", num % 10);
            num /= 10;
        }
        putchar('\n');
    }
    
    return 0;
}