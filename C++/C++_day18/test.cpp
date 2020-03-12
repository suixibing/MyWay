#include "Token.h"
#include <iostream>
using namespace std;
using namespace lb;

int main()
{
	Token t1(1024), t2('$'), t3(3.14), t4("Hello World!"), t5(t1);

	cout << "t1 " << t1 << endl;
	cout << "t2 " << t2 << endl;
	cout << "t3 " << t3 << endl;
	cout << "t4 " << t4 << endl;
	cout << "t5 " << t5 << endl;

	t1 = "Hello C++!!";
	t2 = 3.1415926;
	t3 = '@';
	t4 = 2048;
	cout << "t1 " << t1 << endl;
	cout << "t2 " << t2 << endl;
	cout << "t3 " << t3 << endl;
	cout << "t4 " << t4 << endl;
	
	return 0;
}