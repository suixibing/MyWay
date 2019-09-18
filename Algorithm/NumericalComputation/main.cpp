#include "task.h"

int main()
{
	int input;
	int precision = 4;
	cout.setf(ios_base::fixed);
	cout.precision(precision);

	while (1)
	{
		menu();
		
		cout << "请输入您的选择:> ";
		cin >> input;
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << endl;
		switch (input)
		{
		case SETGAUSS:
			cout << "请输入新的精度:> ";
			cin >> precision;
			cout.precision(precision);
			break;
		case MAGAUSS:
			magauss();
			break;
		case MANETON:
			double x;
			cout << "输入x:> ";
			cin >> x;
			manewton(x, precision);
			break;
		case 5:
			system("type ..\\NumericalComputation\\example.txt");
		}
	}

	system("pause");
	return 0;
}