#include <iostream>
#include <string>
using namespace std;

void pointSet(int &x, int &y, char op, int off)
{
	if (op == 'W')
		y += off;
	else if (op == 'A')
		x -= off;
	else if (op == 'S')
		y -= off;
	else if (op == 'D')
		x += off;
}

int main()
{
	char op = 0;
	string buffer;

	while (cin >> buffer)
	{
		int x = 0, y = 0;
		for (int i = 0, off = 0; i < buffer.size(); ++i)
		{
			if (buffer[i] != 'W' && buffer[i] != 'A'
				&& buffer[i] != 'S' && buffer[i] != 'D')
			{
				while (i < buffer.size() && buffer[i] != ';')
					++i;
			}
			else if (i + 1 < buffer.size()
				&& buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
			{
				op = buffer[i];
				off = buffer[++i] - '0';
				if (i + 1 < buffer.size()
					&& buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
					off = off * 10 + buffer[++i] - '0';
				if (buffer[i + 1] == ';')
					pointSet(x, y, op, off);
			}
		}
		cout << x << ',' << y << endl;
	}

	return 0;
}