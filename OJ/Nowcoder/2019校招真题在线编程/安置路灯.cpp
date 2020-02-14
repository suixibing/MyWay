#include <iostream>
using namespace std;

int main()
{
	int t, n, res;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int res = 0;
		char *pc = new char[n + 1];
		scanf("%s", pc);
		for (int i = 0, cnt = 0, tmp = 0; i <= n; ++i)
		{
			if (tmp)
			{
				pc[i] == 'X';
				--tmp;
			}
			else if (i == n || pc[i] == 'X')
			{
				res += (cnt + 2) / 3;
				tmp = (1 == cnt % 3);
				cnt = 0;
			}
			else
				++cnt;
		}
		printf("%d\n", res);
	}

	return 0;
}