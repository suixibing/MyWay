#include"Tv.h"

using std::cout;
using std::endl;

void Test();
void Note();

int main()
{
	Test();
	cout << endl;
	Note();

	system("pause");
	return 0;
}

void Test()
{
	Tv tv1;
	cout << "初始设置：" << endl;
	tv1.Settings();
	tv1.OnOff();
	tv1.ChannelUp();
	cout << "操作后：" << endl;
	tv1.Settings();

	Remote grey;
	grey.ChannelUp(tv1);
	grey.ChannelUp(tv1);
	grey.SetChannel(tv1, 19);
	cout << "遥控操作后：" << endl;
	tv1.Settings();

	Tv tv2(Tv::On);
	tv2.SetMode();
	grey.SetChannel(tv2, 8);
	cout << "设置：" << endl;
	tv2.Settings();
}

void Note()
{
	cout << "友元：\n";
	cout << "1、友元类\n"
	    << "当类A中需要操作另一个类B中的私有成员时，可以选择将此类作为另一个类B的友元类\n";
	cout << "2、友元成员函数\n"
	    << "如果只有个别函数需要操作另一个类B中的私有成员的话，也可以选择将这些函数作为另一个类B的友元成员函数\n"
	    << "此时需要注意定义类的顺序，类B的声明 -> 类A的定义 -> 类B的定义\n"
	    << "这是为了让类A知道B是一个类，注意的是此时类A中不要出现直接使用B中成员的语句\n"
	    << "因为此时类A并不知道类B中有哪些成员，如果要使用类B，可以将函数定义在别的文件\n"
	    << "如果想要定义此函数为内联函数的话，可以选择定义在类B的定义之后并且使用 inline \n";
	cout << "3、两个类互为友元类\n"
	    << "如果两个类需要能够互相访问私有成员的话，可以将两个类都定义为友元类\n"
	    << "此时和定义友元成员函数的情况类似，但是因为定义友元类时已经对类进行了声明\n"
	    << "所以不需要在类外进行特别的类声明\n";
	cout << "4、共同的友元函数\n"
		<< "也可以将一个函数同时作为两个类的友元达到与互为友元类类似的效果\n"
		<< "适用于这种函数较少的情况，而且可以通过参数顺序重载此函数达到更好的效果\n";
}