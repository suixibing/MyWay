#include "StudentPrivate.h"

std::ostream & StudentPrivate::ArrOut(std::ostream & os)const
{
	if (Array::size() > 0)
	{
		int i = 0, size = Array::size();
		for (i = 0; i < size; i++)
		{
			os << Array::operator[](i) << " ";
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

double StudentPrivate::Average()const
{
	if (Array::size() > 0)
	{
		return Array::sum() / Array::size();
	}
	else
	{
		return 0;
	}
}

const std::string & StudentPrivate::Name()const
{
	return (const string & )*this;
}

double & StudentPrivate::operator[](int n)
{
	return Array::operator[](n);
}

double StudentPrivate::operator[](int n)const
{
	return Array::operator[](n);
}

std::ostream & operator<<(std::ostream & os, const StudentPrivate & stu)
{
	os << "姓名:" << (const string &)stu << std::endl;
	stu.ArrOut(os);
	return os;
}

std::istream & operator>>(std::istream & is, StudentPrivate & stu)
{
	is >> (string &)stu;
	return is;
}

std::istream & getline(std::istream & is, StudentPrivate & stu)
{
	getline(is, (string &)stu);
	return is;
}