#include "rsa.h"
#include "BigInt.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
using namespace lb;

void BigIntTest_sub(long long a, long long b)
{
	BigInt aa = a;
	BigInt bb = b;
	
	cout << a << " and " << b << endl;
	cout << aa << " and " << bb << endl;

	cout << a + b << endl;
	cout << aa + bb << endl;
	cout << a - b << endl;
	cout << aa - bb << endl;
	cout << a * b << endl;
	cout << aa * bb << endl;
	cout << a / b << endl;
	cout << aa / bb << endl;
	cout << a % b << endl;
	cout << aa % bb << endl;

	cout << "-----swap----" << endl;
	cout << b + a << endl;
	cout << bb + aa << endl;
	cout << b - a << endl;
	cout << bb - aa << endl;
	cout << b * a << endl;
	cout << bb * aa << endl;
	cout << b / a << endl;
	cout << bb / aa << endl;
	cout << b % a << endl;
	cout << bb % aa << endl;
}

// 用于测试大数运算
void BigIntTest()
{
	long long a = 6733454LL, b = -a;//7562452342LL;

	BigInt s = 366553;
	
	BigIntTest_sub(a, b);
	cout << endl;
	BigIntTest_sub(a, -b);
	cout << endl;
	BigIntTest_sub(-a, b);
	cout << endl;
	BigIntTest_sub(-a, -b);
	
}

// 生成一套密钥
int test1()
{
	RsaKey key = Rsa::getRsaKey();
	Rsa rsa(key);
	rsa.show();

	ofstream fileout;
	fileout.open("D:/WorkFile/比特/文件加密工具-RSA/文件加密工具-RSA/rsa.txt");
	fileout << key.m_eKey << ' ' << key.m_dKey << ' ' << key.m_pKey << endl;
	fileout.close();

	rsaDataType data = 2;
	rsaDataType num1 = rsa.ecrept(data);
	rsaDataType num2 = rsa.decrept(num1);

	while (cin >> data)
	{
		cout << "data: " << data << endl;

		num1 = rsa.ecrept(data);
		cout << "ecrept: " << num1 << endl;

		num2 = rsa.decrept(num1);
		cout << "decrept: " << num2 << endl;
	}

	return 0;
}

// 测试密钥功能
int test2()
{
	ifstream filein;
	filein.open("./rsa.txt");

	RsaKey key;
	filein >> key.m_eKey >> key.m_dKey >> key.m_pKey;
	Rsa rsa(key);

	cout << "加密: " << endl;
	string filename("D:/WorkFile/比特/文件加密工具-RSA/文件加密工具-RSA/signal.txt");
	string filename2(filename);
	if (filename2.rfind("/") < filename2.size())
		filename2.insert(filename2.rfind("/") + 1, "e_");
	else
		filename2.insert(0, "e_");
	cout << filename << endl;
	cout << filename2 << endl;
	rsa.ecreptFile(filename, filename2);

	cout << "解密: " << endl;
	string filename3(filename2);
	if (filename3.rfind("/e_") < filename3.size())
		filename3[filename3.rfind("/e_") + 1] = 'd';
	else if (filename3.rfind("/") < filename3.size())
		filename3.insert(filename3.rfind("/") + 1, "d_");
	else if (filename3.find("e_") < filename3.size())
		filename3[filename3.find("e_")] = 'd';
	else
		filename3.insert(0, "d_");
	cout << filename2 << endl;
	cout << filename3 << endl;
	rsa.decreptFile(filename2, filename3);

	return 0;
}

// 主要功能
int main()
{
	int flag = 1, input;
	string filename, filename2;
	ifstream filein;
	ofstream fileout;

	RsaKey key;
	filein.open("D:/WorkFile/比特/文件加密工具-RSA/文件加密工具-RSA/rsa.txt");
	filein >> key.m_eKey >> key.m_dKey >> key.m_pKey;
	Rsa rsa(key);

	//BigIntTest();
	//test1();
	while (flag)
	{
		cout << "请输入要进行的操作(1.加密 2.解密 0.退出): " << endl;
		cin >> input;
		cin.get(); // 抛弃输入的换行符
		switch (input)
		{
		case 0:
			flag = 0;
			break;
		case 1:
			cout << "请输入要进行加密的文件名: " << endl;
			getline(cin, filename);

			filename2 = filename; // 自动获得加密后的文件名
			if (filename2.rfind("/") < filename2.size())
				filename2.insert(filename2.rfind("/") + 1, "e_");
			else
				filename2.insert(0, "e_");

			if (rsa.ecreptFile(filename, filename2)) // 加密
				cout << "加密成功! 加密后的文件名为 " << filename2 << endl;
			break;
		case 2:
			cout << "请输入要进行解密的文件名(以e_开头): " << endl;
			getline(cin, filename);

			filename2 = filename; // 自动获得解密后的文件名
			if (filename2.rfind("/e_") < filename2.size())
				filename2[filename2.rfind("/e_") + 1] = 'd';
			else if (filename2.rfind("/") < filename2.size())
				filename2.insert(filename2.rfind("/") + 1, "d_");
			else if (filename2.find("e_") < filename2.size())
				filename2[filename2.find("e_")] = 'd';
			else
				filename2.insert(0, "d_");

			if (rsa.decreptFile(filename, filename2)) // 解密
				cout << "解密成功! 解密后的文件名为 " << filename2 << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}