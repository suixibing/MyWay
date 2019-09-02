#include "Student.h"

std::ostream & Student::ArrOut(std::ostream & os)const
{
	if (scores.size() > 0)
	{
		int i = 0, size = scores.size();
		for (i = 0; i < size; i++)
		{
			os << scores[i] << " ";
			if (i % 5 == 4)
			{
				os << std::endl;
			}
		}
		if (i % 5 != 0)
		{
			os << std::endl;
		}
	}
	else
	{
		os << "无成绩记录";
	}
	return os;
}

double Student::Average()const
{
	if (scores.size() > 0)
	{
		return scores.sum() / scores.size();
	}
	else
	{
		return 0;
	}
}

const std::string & Student::Name()const
{
	return name;
}

double & Student::operator[](int n)
{
	return scores[n];
}

double Student::operator[](int n)const
{
	return scores[n];
}

std::ostream & operator<<(std::ostream & os, const Student & stu)
{
	os << "姓名:" << stu.name << std::endl;
	stu.ArrOut(os);
	return os;
}

std::istream & operator>>(std::istream & is, Student & stu)
{
	is >> stu.name;
	return is;
}

std::istream & getline(std::istream & is, Student & stu)
{
	getline(is, stu.name);
	return is;
}