#include "MailClass.hpp"
using namespace std;
using namespace lb;

int main()
{
	Message msg("hello"), msg2("world");
	Folder f;

	f.save(msg);
	cout << "f.save(msg);" << endl;
	f.print("f");
	f.save(msg2);
	cout << "f.save(msg2);" << endl;
	f.print("f");

	Folder f2(f);
	cout << "f2(f);" << endl;
	f.print("f");
	f2.print("f2");

	Message msg3(msg), msg4(msg2);
	cout << "msg3(msg), msg4(msg2);" << endl;
	f.print("f");
	f2.print("f2");

	f.remove(msg3);
	cout << "f.remove(msg3);" << endl;
	f.print("f");
	f2.print("f2");

	swap(msg, msg2);
	cout << "swap(msg, msg2);" << endl;
	f.print("f");
	f2.print("f2");

	swap(f, f2);
	cout << "swap(f, f2);" << endl;
	f.print("f");
	f2.print("f2");

	return 0;
}