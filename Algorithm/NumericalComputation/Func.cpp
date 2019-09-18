#include "Func.h"

Func::Func() 
{ 
	m_head = new Node; 
	m_head->next = nullptr; 
	m_head->node.second = INT_MIN;
}

Func::Func(const Func& func)
{
	m_head = new Node;
	m_head->next = nullptr;
	m_head->node.second = INT_MIN;
	Node *cur = func.m_head, *now = m_head, *tmp;
	while (cur && cur->next)
	{
		cur = cur->next;
		tmp = new Node;
		tmp->node = cur->node;

		tmp->next = now->next;
		now->next = tmp;
		now = tmp;
	}
}

Func::Func(double coef, int index)
{
	m_head = new Node;
	m_head->node.second = INT_MIN;
	m_head->next = new Node;
	m_head->next->node.first = coef;
	m_head->next->node.second = index;
	m_head->next->next = nullptr;
}

Func::~Func()
{
	Node *tmp;
	while (m_head->next)
	{
		tmp = m_head->next;
		m_head->next = tmp->next;
		delete tmp;
	}
	delete m_head;
}

void Func::add(double coef, int index)
{
	Node *cur, *tmp;

	Data node(coef, index);
	tmp = new Node;
	tmp->node = node;
	for (cur = m_head; cur->next && cur->next->node.second < index; cur = cur->next)
	{
		continue;
	}
	if (cur->next && cur->next->node.second == index)
	{
		cur->next->node.first += coef;
		delete tmp;
	}
	else
	{
		tmp->next = cur->next;
		cur->next = tmp;
	}
	checkZero();
}

double Func::calculate(double x)
{
	double sum = 0;
	Node* cur = m_head->next;

	while (cur)
	{
		sum += cur->node.first * pow(x, cur->node.second);
		cur = cur->next;
	}
	return sum;
}

void Func::show()const
{
	Node* cur = m_head->next;

	while (cur)
	{
		if (cur->node.first < 0)
		{
			std::cout << "(";
		}
		std::cout << cur->node.first;
		if (cur->node.first < 0)
		{
			std::cout << ")";
		}
		if (cur->node.second)
		{
			std::cout << "x^";
			if (cur->node.second < 0)
			{
				std::cout << "(";
			}
			std::cout << cur->node.second;
			if (cur->node.second < 0)
			{
				std::cout << ")";
			}
		}
		if (cur->next)
		{
			std::cout << " + ";
		}
		cur = cur->next;
	}
	std::cout << std::endl;
}

void Func::derivative()
{
	Node* cur = m_head->next;

	while (cur)
	{
		cur->node.first *= cur->node.second;
		--cur->node.second;
		cur = cur->next;
	}
	checkZero();
}

void Func::checkZero()
{
	for (Node* cur = m_head; cur && cur->next; cur = cur->next)
	{
		if (cur->next->node.first == 0)
		{
			Node* tmp = cur->next;
			cur->next = tmp->next;
			delete tmp;
		}
	}
}

Func& Func::operator=(const Func& func)
{
	Node *cur = func.m_head->next, *tmp, *h = m_head;
	if (&func == this)
	{
		return *this;
	}
	while (m_head->next)
	{
		tmp = m_head->next;
		m_head->next = tmp->next;
		delete tmp;
	}
	while (cur)
	{
		tmp = new Node;
		tmp->node = cur->node;
		tmp->next = h->next;
		h->next = tmp;
		h = tmp;
		cur = cur->next;
	}
	return *this;
}