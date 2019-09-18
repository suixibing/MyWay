#pragma once


#include<iostream>
#include<string>
#include<valarray>


// 使用包含对象的方法，实现 Student 类
class Student
{
private:
	typedef std::valarray<double> Array;
	std::string m_name;
	Array m_scores;
	std::ostream & ArrOut(std::ostream& os)const;
public:
	Student() : m_name("Null Student"), m_scores() {}
	Student(const std::string& s) : m_name(s), m_scores() {}
	explicit Student(int n) : m_name("Null Student"), m_scores(n) {}
	Student(const std::string& s, int n) : m_name(s), m_scores(n) {}
	Student(const std::string& s, const Array& a) : m_name(s), m_scores(a) {}
	Student(const char* s, const double* pd, int n) : m_name(s), m_scores(pd, n) {}
	~Student() {}
	double Average()const;
	const std::string& Name()const;
	double& operator[](int n);
	double operator[](int n)const;
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
	friend std::istream& operator>>(std::istream& is, Student& stu);
	friend std::istream& getline(std::istream& is, Student& stu);
};

