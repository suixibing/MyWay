#include <iostream>
using namespace std;

int main()
{
    int n;
    
    while (scanf("%d", &n) != EOF)
    {
        int cnt = 0;
        while (n)
        {
            n &= n - 1;
            ++cnt;
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}