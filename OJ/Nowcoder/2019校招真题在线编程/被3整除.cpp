#include <iostream>
using namespace std;

int main()
{
	int l, r;

	while (scanf("%d%d", &l, &r) != EOF)
	{
		int cnt = 0;
		while (l++ <= r)
		{
			int sum = 0;
			for (int i = 1; i < l; ++i)
				sum += i;
			if (sum % 3 == 0)
				++cnt;
		}
		printf("%d\n", cnt);
	}

	return 0;
}