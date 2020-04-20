
#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n, flag, score;
	string name;

	while (cin >> n >> flag)
	{
		map<int, vector<string> > book;
		for (int i = 0; i < n; ++i)
		{
			cin >> name >> score;
			book[score].push_back(name);
		}
		if (flag == 1)
		{
			auto begin = book.begin(), end = book.end();
			while (begin != end)
			{
				for (int i = 0; i < begin->second.size(); ++i)
					cout << begin->second[i] << " " << begin->first << endl;
				++begin;
			}
		}
		else
		{
			auto begin = book.rbegin(), end = book.rend();
			while (begin != end)
			{
				for (int i = 0; i < begin->second.size(); ++i)
					cout << begin->second[i] << " " << begin->first << endl;
				++begin;
			}
		}
	}

	return 0;
}