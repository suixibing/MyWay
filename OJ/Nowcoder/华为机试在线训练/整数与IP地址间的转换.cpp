#include <iostream>
using namespace std;

int main()
{
	string strip;
	unsigned int num, uip, out_strip;

	while (cin >> strip >> uip)
	{
		out_strip = num = 0;
		for (auto i : strip)
		{
			if (i == '.')
			{
				out_strip = (out_strip << 8) | num;
				num = 0;
			}
			else
				num = num * 10 + i - '0';
		}
		out_strip = (out_strip << 8) | num;
		cout << out_strip << endl;
		cout << ((uip >> 24) & 0xff) << "." << ((uip >> 16) & 0xff) << "."
			<< ((uip >> 8) & 0xff) << "." << (uip & 0xff) << endl;
	}

	return 0;
}