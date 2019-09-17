#include "Func.h"

void manewton(double x1, int precision, int N)
{
	int i, n;
	Func f1, f2;
	double x2, ep = pow(0.1, precision);

	cout << "请输入方程的项数:> ";
	cin >> n;
	while (n--)
	{
		f1.add();
	}
	f2 = f1;
	f2.derivative();
	for (i = 0; i < N; i++)
	{
		x2 = x1 - f1.calculate(x1) / f2.calculate(x1);
		if (abs(x1 - x2) < ep)
		{
			break;
		}
		x1 = x2;
	}
	if (i == N)
	{
		cout << "已达迭代次数上限\n";
	}
	cout << "\nk = \n";
	cout.width(10);
	cout << i + 1;
	cout << "\nans = \n";
	cout.width(10);
	cout << x1 << endl << endl;
}
