#include <iostream>
using namespace std;

int main()
{
	int empty = 0, full = 0, cnt = 0;

	while (scanf("%d", &empty) != EOF)
	{
		if (empty == 0)
			break;
		cnt = 0;
		while (empty / 3)
		{
			cnt += empty / 3;
			empty = empty % 3 + empty / 3;
		}
		if (empty == 2)
			++cnt;
		printf("%d\n", cnt);
	}

	return 0;
}