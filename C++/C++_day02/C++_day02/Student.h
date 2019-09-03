#pragma once


#include<iostream>
#include<string>
#include<valarray>


// 使用包含对象的方法，实现 Student 类
class Student
{
private:
	typedef std::valarray<double> Array;
	std::string name;
	Array scores;
	std::ostream & ArrOut(std::ostream & os)const;
public:
	Student() : name("Null Student"), scores() {}
	Student(const std::string & s) : name(s), scores() {}
	explicit Student(int n) : name("Null Student"), scores(n) {}
	Student(const std::string & s, int n) : name(s), scores(n) {}
	Student(const std::string & s, const Array & a) : name(s), scores(a) {}
	Student(const char * s, const double * pd, int n) : name(s), scores(pd, n) {}
	~Student() {}
	double Average()const;
	const std::string & Name()const;
	double & operator[](int n);
	double operator[](int n)const;
	friend std::ostream & operator<<(std::ostream & os, const Student & stu);
	friend std::istream & operator>>(std::istream & is, Student & stu);
	friend std::istream & getline(std::istream & is, Student & stu);
};

