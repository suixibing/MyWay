#include <iostream>
#include <cstdlib>
#include "BadClass.h"

using namespace std;

enum
{
	CASE1,
	CASE2,
	CASE3,
	CASE4,
	CASE5,
};
#define SET CASE5

int main()
{
	int set = SET;
	double x, y, z;
	Demo d1("创建 main()");

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
		case CASE4:
			try
			{
				z = hmean4(x, y);
				cout << x << "和" << y << "的调和平均数为：" << z << endl;
				cout << x << "和" << y << "的几何平均数为：" << gmean4(x, y) << endl;
			}
			catch (bad_hmean& bg)
			{
				bg.mesg();
			}
			catch (bad_gmean& hg)
			{
				cout << hg.mesg();
				cout << "(x = " << x << ", y = " << y << ")" << endl;
			}
			break;
		case CASE5:
			try
			{
				z = means5(x, y);
				cout << "means5(" << x << ", " << y << ")：" << z << endl;
			}
			catch (bad_hmean& bg)
			{
				bg.mesg();
				cout << "请输入两个新的数：";
				continue;
			}
			catch (bad_gmean& hg)
			{
				cout << "(x = " << x << ", y = " << y << ")" << endl;
				cout << hg.mesg();
				cout << "请输入两个新的数：";
				continue;
			}
			d1.Show();
			break;
		default:
			break;
		}
		
		cout << "请输入两个新的数：";
	}
	system("pause");
	return 0;
}
