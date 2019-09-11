#include <iostream>
#include <cstdlib>

using namespace std;

#define CASE1 1
#define CASE2 2
#define CASE3 3
#define SET CASE1

double hmean1(double a, double b);
bool hmean2(double a, double b, double* ans);
double hmean3(double a, double b);

int main()
{
	int set = CASE3;
	double x, y, z;

	cout << "请输入两个数：";
	while (cin >> x >> y)
	{
		switch (set)
		{
		case CASE1:
			z = hmean1(x, y);
			cout << x << "和" << y << "的调和平均数为：" << z << endl;
			break;
		case CASE2:
			if (hmean2(x, y, &z))
			{
				cout << x << "和" << y << "的调和平均数为：" << z << endl;
			}
			else
			{
				cout << "您输入了两个相反数，计算调和平均出现问题！\n";
			}
			break;
		case CASE3:
			try
			{
				z = hmean3(x, y);
			}
			catch (const char *err)
			{
				cout << err << "请输入两个新的数：";
				continue;
			}
			cout << x << "和" << y << "的调和平均数为：" << z << endl;
			break;
		default:
			break;
		}
		
		cout << "请输入两个新的数：";
	}
	system("pause");
	return 0;
}

double hmean1(double a, double b)
{
	if (a == -b)
	{
		cout << "您输入了两个相反数，计算调和平均出现问题！\n";
		abort();
	}
	return 2.0 * a * b / (a + b);
}

bool hmean2(double a, double b, double* ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	*ans = 2.0 * a * b / (a + b);
	return true;
}

double hmean3(double a, double b)
{
	if (a == -b)
	{
		throw "您输入了两个相反数，计算调和平均出现问题！\n";
	}
	return 2.0 * a * b / (a + b);
}