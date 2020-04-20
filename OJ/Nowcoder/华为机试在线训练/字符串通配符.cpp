#include <string>
#include <iostream>
using namespace std;

bool regexJudge(const char *str1, const char *str2)
{
	if (*str1 == '\0' && *str2 == '\0')
		return true;
	if (*str1 == '\0' || *str2 == '\0')
		return false;
	if (*str1 == *str2 || *str1 == '?')
		return regexJudge(str1 + 1, str2 + 1);
	else if (*str1 == '*')
		return regexJudge(str1, str2 + 1) || regexJudge(str1 + 1, str2 + 1);
	else
		return false;
}

int main()
{
	string str1, str2;
	
	cout.setf(ios::boolalpha);
	while (cin >> str1 >> str2)
		cout << regexJudge(str1.c_str(), str2.c_str()) << endl;

	return 0;
}