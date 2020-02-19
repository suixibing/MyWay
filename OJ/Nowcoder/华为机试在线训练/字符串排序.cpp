#include <string>
#include <iostream>
using namespace std;

int main()
{
	int i, j, k;
	string str, tmp;

	while (getline(cin, tmp))
	{
		str.clear();
		for (i = 0; i < 26; ++i)
		{
			for (j = 0; str.size() < tmp.size() && j < tmp.size(); ++j)
			{
				k = str.size();
				while (k < tmp.size() && !(tmp[k] >= 'a' && tmp[k] <= 'z' || tmp[k] >= 'A' && tmp[k] <= 'Z'))
					str.push_back(tmp[k++]);
				if (tmp[j] >= 'A' && tmp[j] <= 'Z' && tmp[j] - 'A' == i ||
					tmp[j] >= 'a' && tmp[j] <= 'z' && tmp[j] - 'a' == i)
					str.push_back(tmp[j]);
			}
		}
		cout << str << endl;
	}

	return 0;
}