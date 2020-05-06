#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long count(const vector<int> &book, int pos, int num)
{
    if (num < 0)
        return 0;
    int cnt = 1;
    for (int i = pos; i < book.size(); ++i)
        cnt += count(book, i + 1, num - book[i]);
    return cnt;
}

int main()
{
    int n, w;
    unsigned long long sum;
    
    while (cin >> n >> w)
    {
        vector<int> book(n);
        sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> book[i];
            sum += book[i];
        }
        if (sum <= w)
            printf("%d\n", static_cast<int>(pow(2, n)));
        else
            cout << count(book, 0, w) << endl;
    }
    
    return 0;
}