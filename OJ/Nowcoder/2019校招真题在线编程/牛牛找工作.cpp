#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N, M, Di, Pi, Ai;
    while (scanf("%d%d", &N, &M) != EOF)
    {
        vector<int> hardNum, people;
        map<int, int> records, output;
        for (int i = 0; i < N; ++i)
        {
            scanf("%d%d", &Di, &Pi);
            records[Di] = Pi;
            hardNum.push_back(Di);
        }
        sort(hardNum.begin(), hardNum.end());
        for (int i = 0; i < M; ++i)
        {
            scanf("%d", &Ai);
            people.push_back(Ai);
        }
        vector<int> tmp(people);
        sort(people.begin(), people.end());
        for (int i = 0, j = 0, max = 0; i < M; ++i)
        {
            for (; j < N && hardNum[j] <= people[i]; ++j)
            {
                if (max < records[hardNum[j]])
                    max = records[hardNum[j]];
            }
            //cout << max << endl;
            output[people[i]] = max;
        }
        for (int i = 0; i < M; ++i)
            printf("%d\n", output[tmp[i]]);
    }
    return 0;
}