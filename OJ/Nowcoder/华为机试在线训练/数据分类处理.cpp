#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string ToString(size_t val)
{
	if (val == 0)
		return "0";
	string ret;
	while (val)
	{
		ret.push_back(val % 10 + '0');
		val /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
	size_t i, n, pos, tmp;
	string str;

	while (cin >> n)
	{
		vector<string> I(n);
		for (i = 0; i < n; ++i)
			cin >> I[i];
		cin >> n;
		set<int> R;
		for (i = 0; i < n; ++i)
		{
			cin >> tmp;
			R.insert(tmp);
		}
		vector<string> res;
		pos = n = 0;
		for (auto & k : R)
		{
			str = ToString(k);
			res.push_back(str);
			res.push_back(str);
			for (i = 0; i < I.size(); ++i)
			{
				if (I[i].find(str) != I[i].npos)
				{
					res.push_back(ToString(i));
					res.push_back(I[i]);
					++n;
				}
			}
			if (n)
			{
				res[pos + 1] = ToString(n);
				pos += 2 + 2 * n;
				n = 0;
			}
			else
			{
				res.pop_back();
				res.pop_back();
			}
		}
		cout << res.size();
		for (auto & s : res)
			cout << " " << s;
		cout << endl;
	}

	return 0;
}