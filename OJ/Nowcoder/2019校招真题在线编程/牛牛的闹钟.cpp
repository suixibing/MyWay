#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i, n, A, B, X, t;
    cin >> n;
    vector<int> time(n);
    for (i = 0; i < n; ++i)
    {
        cin >> A >> B;
        time[i] = A * 60 + B;
    }
    sort(time.begin(), time.end());
    cin >> X;
    cin >> A >> B;
    t = A * 60 + B;
    for (i = 0; i < n; ++i)
    {
        if (t < time[i] + X)
            break;
    }
    cout << time[i - 1] / 60 << " " << time[i - 1] % 60 << endl;
    
    return 0;
}