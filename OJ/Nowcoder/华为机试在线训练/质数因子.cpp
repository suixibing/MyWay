#include <iostream>
using namespace std;

int main ()
{
    long input;
    
    while (scanf("%ld", &input) != EOF)
    {
        int i = 2;
        while (i <= input)
        {
            if (input % i == 0)
            {
                printf("%d ", i);
                input /= i;
            }
            else
                ++i;
        }
        putchar('\n');
    }
    
    return 0;
}