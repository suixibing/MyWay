#include <iostream>
#include <vector>
using namespace std;

bool hasK(const vector< vector<int> > &data, int K)
{
    for (int i = 0, j = data[0].size() - 1; i < data.size() && j >= 0; )
    {
        if (data[i][j] > K)
            --j;
        else if (data[i][j] < K)
            ++i;
        else
            return true;
    }
    return false;
}

int main()
{
    int N, M, K;
    
    while (cin >> N >> M >> K)
    {
        vector< vector<int> > data(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
                cin >> data[i][j];
        }
        if (hasK(data, K))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
    return 0;
}