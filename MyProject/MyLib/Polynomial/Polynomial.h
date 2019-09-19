#pragma once

#include <iostream>
#include <valarray>
#include <cmath>

class Polynomial
{
public:
	typedef std::pair<double, int> Data;
	struct Node
	{
		Data node;
		struct Node* next;
	};

	Polynomial();
	explicit Polynomial(const Node& node);
	Polynomial(const Polynomial& func);
	Polynomial(double coef, int index);
	~Polynomial();

	void add(double coef, int index);
	void add(const Polynomial& func);
	void multiplication(const Node& node);
	double calculate(double x);
	void derivative();
	void checkZero();
	const Node& largestIndex()const;
	void show()const;

	const Polynomial operator+(const Polynomial& func)const;
	const Polynomial operator-(const Polynomial& func)const;
	const Polynomial operator*(const Polynomial& func)const;
	const Polynomial operator/(const Polynomial& func)const;
	Polynomial& operator-();
	Polynomial& operator=(const Polynomial& func);

	const Polynomial operator+=(const Polynomial& func);
	const Polynomial operator-=(const Polynomial& func);
	const Polynomial operator*=(const Polynomial& func);
	const Polynomial operator/=(const Polynomial& func);

private:
	Node* m_head;
};