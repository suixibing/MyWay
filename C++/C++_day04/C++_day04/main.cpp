#include<string>
#include<ctime>
#include"ArrayTP.h"
#include"StackTP.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

void Test1();
void Test2();
void ArrayTPHelp();

int main()
{
	char choice;

	while (1)
	{
		cout << "1: 测试1\t2: 测试2\t3: 模板说明\tq: 退出\n";
		cout << "请选择：";
		cin >> choice;
		while (strchr("123q", choice) == NULL)
		{
			cin >> choice;
		}
		if (choice == 'q')
		{
			break;
		}
		while (cin.get() != '\n');
		switch (choice)
		{
		case '1':
			Test1();
			break;
		case '2':
			Test2();
			break;
		case '3':
			ArrayTPHelp();
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}

void Test1()
{
	char ch;
	string str;
	StackTP<string> s;

	while (1)
	{
		cout << "a: 添加\tp:删除\tq:退出\n";
		cout << "请选择：";
		cin >> ch;
		while (strchr("apq", ch) == NULL)
		{
			cin >> ch;
		}
		if (ch == 'q')
		{
			cout << "退出！\n";
			break;
		}
		while (cin.get() != '\n');
		switch (ch)
		{
		case 'a':
			cout << "请输入字符串：";
			cin >> str;
			if (!s.Push(str))
			{
				cout << "已满！\n";
			}
			break;
		case 'p':
			if (s.Pop(str))
			{
				cout << "# " << str << endl;
			}
			else
			{
				cout << "为空！\n";
			}
			break;
		default:
			break;
		}
	}
}

void Test2()
{
	const int NUM = 10;
	std::srand(unsigned(std::time(NULL)));
	cout << "请输入要建立栈的容量：";
	int capacity;
	while (!(cin >> capacity));
	StackTP<const char*> s(capacity);

	const char* input[NUM] = { "1  haha", "2  heihei", "3  hehe", "4  keek", "5  haia",
		"6  keai", "7  iaae", "8  fiau", "9  funa", "10 kese" };
	const char* output[NUM];
	int in = 0, out = 0;

	while (out < NUM)
	{
		if (s.IsEmpty())
		{
			s.Push(input[in++]);
		}
		else if (s.IsFull())
		{
			s.Pop(output[out++]);
		}
		else if (in < NUM && std::rand() % 2)
		{
			s.Push(input[in++]);
		}
		else
		{
			s.Pop(output[out++]);
		}
	}
	for (int i = 0; i < NUM; i++)
	{
		cout << "# " << output[i] << endl;
	}
}

void ArrayTPHelp()
{
	cout << endl;
	cout << "ArrayTP<double, Size1> arr1;\n"
		<< "ArrayTP<double, Size2> arr2;\n"
		<< "注：arr1 和 arr2 是两种不同的类\n\n";

	cout << "ArrayTP< StackTP<int> > arr3;\n"
		<< "1、非类型参数可以有默认参数\n"
		<< "2、类型参数也可以由模板类担当\n"
		<< "3、注意使用模板类作为类型参数时必须要有 ' ' 将两个 '>' 分隔开，"
		<< "避免变成 \">>\"\n\n";
	
	cout << "ArrayTP< ArrayTP<int, Size1>, Size2 > arr4; \n"
		<< "1、模板类的递归使用\n"
		<< "2、等价于 int arr4[Size2][Size1];\n\n";

	cout << "实例化：\n"
		<< "隐式实例化：只有在实际使用类时才会生成进行隐式实例化，例如声明类指针时并不会立刻进行实例化\n\n"
		<< "显式实例化：template class ArrayTP<double, 10>;\n"
		<< "\t\t同时生成类声明和定义"
		<< "显式具体化：template <> class ArrayTP<double, 10> {} \n\t\t用于替换模板中的通用类型\n\n"
		<< "部分具体化：如果有 template <class T1, class T2> class A {} \n"
		<< "\t\t那么可以用 template <class T1> class A<T1, int> {} 进行部分具体化\n\n";
}