#include <map>
#include <iostream>
using namespace std;

int main()
{
    int n, index, val;
    map<int, int> book;
    
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &index, &val);
        book[index] += val;
    }
    for (auto & i : book)
        cout << i.first << ' ' << i.second << endl;
    
    return 0;
}