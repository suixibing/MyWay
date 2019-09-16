#pragma once

#include "task.h"

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
	Func(Func& func);
	~Func();
	void add();
	void add(Func& func);
	void show()const;
	void derivative();
	Func& operator=(Func& func);
};