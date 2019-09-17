#pragma once

#include "task.h"
#include <cmath>

class Func
{
private:
	struct Node
	{
		std::pair<double, int> node;
		struct Node* next;
	};
	Node* head;
public:
	Func() { head = new Node; head->next = nullptr; }
	Func(const Func& func);
	~Func();
	void add();
	void add(const Func& func);
	void multiplication(const Node& node);
	double calculate(double x);
	void derivative();
	void checkzero();
	void show()const;
	
	const Func operator+(const Func& func)const;
	const Func operator-(const Func& func)const;
	const Func operator*(const Func& func)const;
	Func& operator-();
	Func& operator=(const Func& func);
};