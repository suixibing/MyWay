#include <iostream>
#include <cctype>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
	string key, str;
	bitset<26> book;

	while (cin >> key >> str)
	{
		book.reset();
		vector<char> vec;
		for (auto c : key)
		{
			if (book[tolower(c) - 'a'] == 0)
			{
				book[tolower(c) - 'a'] = 1;
				vec.push_back(tolower(c));
			}
		}
		for (size_t i = 0; i < 26; ++i)
		{
			if (!book.test(i))
				vec.push_back('a' + i);
		}
		for (auto &c : str)
		{
			if (isupper(c))
				c = vec[c - 'A'] - 'a' + 'A';
			else
				c = vec[c - 'a'];
		}
		cout << str << endl;
	}

	return 0;
}