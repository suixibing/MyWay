#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	char ch;
	string word;
	vector<string> output;

	while ((ch = getchar()) != '\n')
	{
		if (!isalpha(ch))
		{
			if (word.empty())
				continue;
			output.push_back(word);
			word.clear();
		}
		else
			word.push_back(ch);
	}
	if (!word.empty())
		output.push_back(word);
	cout << output.back();
	for (int i = output.size() - 2; i >= 0; --i)
		cout << ' ' << output[i];
	cout << endl;

	return 0;
}