#include<string>
#include"StackTP.h"

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	StackTP<std::string> s;
	char ch;
	std::string str;

	while (1)
	{
		cout << "a: Ìí¼Ó\tp:É¾³ý\tq:ÍË³ö\n";
		cout << "ÇëÑ¡Ôñ£º";
		cin >> ch;
		while (strchr("apq", ch) == NULL)
		{
			cin >> ch;
		}
		if (ch == 'q')
		{
			cout << "ÍË³ö£¡\n";
			break;
		}
		while (cin.get() != '\n');
		switch (ch)
		{
		case 'a':
			cout << "ÇëÊäÈë×Ö·û´®£º";
			cin >> str;
			if (!s.Push(str))
			{
				cout << "ÒÑÂú£¡\n";
			}
			break;
		case 'p':
			if (s.Pop(str))
			{
				cout << "# " << str << endl;
			}
			else
			{
				cout << "Îª¿Õ£¡\n";
			}
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}