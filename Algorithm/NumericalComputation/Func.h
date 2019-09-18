#pragma once

#include <iostream>
#include <valarray>
#include <cmath>

class Func
{
public:
	typedef std::pair<double, int> Data;
	struct Node
	{
		Data node;
		struct Node* next;
	};

	Func();
	Func(const Func& func);
	Func(double coef, int index);
	~Func();

	void add(double coef, int index);
	double calculate(double x);
	void derivative();
	void checkZero();
	void show()const;

	Func& operator=(const Func& func);

private:
	Node* m_head;
};