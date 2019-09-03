#pragma once

#include<iostream>
#include<string>
#include<valarray>

using std::string;


// 使用私有继承的方法，实现 Student 类
class StudentPrivate : private string, private std::valarray<double>
{
private:
	typedef std::valarray<double> Array;
	std::ostream & ArrOut(std::ostream & os)const;
public:
	StudentPrivate() : string("Null Student"), Array() {}
	StudentPrivate(const string & s) : string(s), Array() {}
	explicit StudentPrivate(int n) : string("Null Student"), Array(n) {}
	StudentPrivate(const string & s, int n) : string(s), Array(n) {}
	StudentPrivate(const string & s, const Array & a) : string(s), Array(a) {}
	StudentPrivate(const char * s, const double * pd, int n) : string(s), Array(pd, n) {}
	~StudentPrivate() {}
	double Average()const;
	const std::string & Name()const;
	double & operator[](int n);
	double operator[](int n)const;
	friend std::ostream & operator<<(std::ostream & os, const StudentPrivate & stu);
	friend std::istream & operator>>(std::istream & is, StudentPrivate & stu);
	friend std::istream & getline(std::istream & is, StudentPrivate & stu);
};
