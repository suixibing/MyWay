#include "expressionTree.h"
//#include "test.h"
#include <iostream>

using namespace std;
using namespace lb;

int main()
{
	Expr b = Expr("-", 5), c = Expr("+", 3, 4);
	Expr e = Expr("*", b, c);
	cout << e << " = " << e.eval() << endl;
	Expr a("?:", Expr("!=", e, e.eval()), 1, 0);
	cout << a << " = " << a.eval() << endl;
	Expr d("||", a, a);
	cout << d << " = " << d.eval() << endl;

	return 0;
}