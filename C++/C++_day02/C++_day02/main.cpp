#include"Student.h"
#include"StudentPrivate.h"

using std::endl;
using std::cout;
using std::cin;

void Set(Student& s, int n);
void Set(StudentPrivate& s, int n);

const int pupils = 3;
const int quizzes = 5;

void TestStudent()
{
	Student stu[pupils] = { Student(quizzes), Student(quizzes), Student(quizzes) };

	int i;
	for (i = 0; i < pupils; ++i)
	{
		Set(stu[i], quizzes);
	}
	cout << "学生列表:\n";
	for (i = 0; i < pupils; i++)
	{
		cout << stu[i].Name() << endl;
	}
	cout << "成绩列表:\n";
	for (i = 0; i < pupils; i++)
	{
		cout << stu[i];
		cout << "平均分：" << stu[i].Average() << endl;
	}
}

void TestStudentPrivate()
{
	StudentPrivate stu[pupils] = { StudentPrivate(quizzes), StudentPrivate(quizzes), StudentPrivate(quizzes) };

	int i;
	for (i = 0; i < pupils; ++i)
	{
		Set(stu[i], quizzes);
	}
	cout << "学生列表:\n";
	for (i = 0; i < pupils; i++)
	{
		cout << stu[i].Name() << endl;
	}
	cout << "成绩列表:\n";
	for (i = 0; i < pupils; i++)
	{
		cout << stu[i];
		cout << "平均分：" << stu[i].Average() << endl;
	}
}

int main()
{
	TestStudentPrivate();

	system("pause");
	return 0;
}

void Set(Student& s, int n)
{
	cout << "请输入学生的姓名：";
	getline(cin, s);
	cout << "请输入" << n << "个成绩：";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	while (cin.get() != '\n');
}

void Set(StudentPrivate& s, int n)
{
	cout << "请输入学生的姓名：";
	getline(cin, s);
	cout << "请输入" << n << "个成绩：";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	while (cin.get() != '\n');
}