#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Log
{
	string m_filename;
	unsigned int m_line;
	unsigned int m_count;
	Log(string & filename, unsigned int line)
		: m_filename(filename), m_line(line), m_count(1) { }
};

int main()
{
	unsigned int pos, flag, line;
	string filename;
	vector<Log> book;

	while (cin >> filename >> line)
	{
		pos = filename.find_last_of('\\');
		if (pos < filename.size())
		{
			if (filename.size() - pos - 1 <= 16)
				filename = filename.substr(pos + 1);
			else
				filename = filename.substr(filename.size() - 16);
		}
		flag = 1;
		for (auto & k : book)
		{
			if (k.m_filename == filename && k.m_line == line)
			{
				++k.m_count;
				flag = 0;
				break;
			}
		}
		if (flag)
			book.push_back(Log(filename, line));
	}
	int i = (book.size() > 8) ? book.size() - 8 : 0;
	for (; i < book.size(); ++i)
		printf("%s %d %d\n", book[i].m_filename.c_str(),
			book[i].m_line, book[i].m_count);

	return 0;
}