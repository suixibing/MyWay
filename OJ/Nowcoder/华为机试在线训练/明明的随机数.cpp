#include <map>
#include <iostream>
using namespace std;

int main()
{
    int n, tmp;
    
    while (scanf("%d", &n) != EOF)
    {
        map<int, int> book;
        while (n--)
        {
            scanf("%d", &tmp);
            book[tmp] = 1;
        }
        for (auto & i : book)
            printf("%d\n", i.first);
    }
    
    return 0;
}