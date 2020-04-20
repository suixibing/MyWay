#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n, sum, num1, num2;
	string format;

	while (cin >> n)
	{
		sum = 0;
		vector<vector<int> > mats(n, vector<int>(2));
		for (int i = 0; i < n; ++i)
			cin >> mats[i][0] >> mats[i][1];
		cin >> format;
		stack<int> st;
		for (int i = 0; st.size() != 1 || i < format.size(); ++i)
		{
			if (i < format.size() && format[i] == '(')
				continue;
			if (i < format.size() && format[i] != ')')
				st.push(format[i] - 'A');
			else if (st.size() >= 2)
			{
				num2 = st.top();
				st.pop();
				num1 = st.top();
				st.pop();
				sum += mats[num1][1] * (mats[num1][0] * mats[num2][1]);
				mats[num2][0] = mats[num1][0];
				st.push(num2);
			}
		}
		cout << sum << endl;
	}

	return 0;
}