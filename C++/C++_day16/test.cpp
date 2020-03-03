#include "TextQuery.hpp"
using namespace std;
using namespace lb;

void runQueries(ifstream & fin)
{
	TextQuery test(fin); // 保存文件并创建查询map
	string word;
	// 提示用户输入，进行查询并输出
	while (true)
	{
		cout << "请输入要查找的单词(q 退出): ";
		if (!(cin >> word) || word == "q")
			break;
		QueryResult res = test.query(word);
		print(cout, res) << endl;
	}
}

int main()
{
	ifstream fin("input.txt");
	runQueries(fin);

	return 0;
}