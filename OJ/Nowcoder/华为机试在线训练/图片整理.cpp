#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	string line;

	while (cin >> line)
	{
		sort(line.begin(), line.end());
		cout << line << endl;
	}

	return 0;
}