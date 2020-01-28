#include "picture.h"
#include <iostream>
using namespace std;
using namespace lb;

const char *init[] = { "Paris", "in the", "Spring" };

int main()
{
	Picture p(init, 3);
	cout << p << endl;

	Picture q = frame(p);
	cout << q << endl;

	Picture r = p | q;
	cout << r << endl;

	Picture s = q & r;
	cout << s << endl;
	
	Picture n = frame(s);
	cout << n << endl;
	
	Picture k(s | n);
	cout << k << endl;

	cout << frame(k);

	return 0;
}