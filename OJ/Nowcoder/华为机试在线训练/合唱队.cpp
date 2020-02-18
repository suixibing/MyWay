#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int i, j, n, max;

	while (cin >> n)
	{
		vector<int> stu(n), increase(n, 1), decrease(n, 1);
		for (i = 0; i < n; ++i)
			cin >> stu[i];
		for (i = 1; i < n; ++i)
		{
			for (j = i - 1; j >= 0; --j)
			{
				if (stu[i] > stu[j] && increase[j] + 1 > increase[i])
					increase[i] = increase[j] + 1;
				if (stu[n - i - 1] > stu[n - j - 1] && decrease[n - j - 1] + 1 > decrease[n - i - 1])
					decrease[n - i - 1] = decrease[n - j - 1] + 1;
			}
		}
		for (i = max = 0; i < n; ++i)
		{
			if (increase[i] + decrease[i] - 1 > max)
				max = increase[i] + decrease[i] - 1;
		}
		cout << n - max << endl;
	}

	return 0;
}