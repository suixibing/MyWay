#include "Polynomial.h"

Polynomial::Polynomial()
{
	m_head = new Node;
	m_head->next = nullptr;
	m_head->node.second = INT_MIN;
}

Polynomial::Polynomial(const Node& node)
{
	m_head = new Node;
	m_head->node.second = INT_MIN;
	m_head->next = new Node;
	m_head->next->node = node.node;
	m_head->next->next = nullptr;
}

Polynomial::Polynomial(const Polynomial& func)
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

Polynomial::Polynomial(double coef, int index)
{
	m_head = new Node;
	m_head->node.second = INT_MIN;
	m_head->next = new Node;
	m_head->next->node.first = coef;
	m_head->next->node.second = index;
	m_head->next->next = nullptr;
}

Polynomial::~Polynomial()
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

void Polynomial::add(double coef, int index)
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

void Polynomial::add(const Polynomial& func)
{
	Node *cur = func.m_head->next, *tmp;

	while (cur)
	{
		for (tmp = m_head; tmp->next && tmp->next->node.second < cur->node.second; tmp = tmp->next)
		{
			continue;
		}
		if (tmp && tmp->next && tmp->next->node.second == cur->node.second)
		{
			tmp->next->node.first += cur->node.first;
		}
		else
		{
			Node *t = new Node;
			t->node = cur->node;
			t->next = tmp->next;
			tmp->next = t;
		}
		cur = cur->next;
	}
	checkZero();
}

void Polynomial::multiplication(const Node& node)
{
	for (Node* cur = m_head->next; cur; cur = cur->next)
	{
		cur->node.first *= node.node.first;
		cur->node.second += node.node.second;
	}
	checkZero();
}

double Polynomial::calculate(double x)
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

void Polynomial::show()const
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

void Polynomial::derivative()
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

void Polynomial::checkZero()
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

const Polynomial::Node& Polynomial::largestIndex()const
{
	Node* cur;
	for (cur = m_head; cur->next; cur = cur->next)
	{
		continue;
	}
	return *cur;
}

const Polynomial Polynomial::operator+(const Polynomial& func)const
{
	Polynomial temp(*this);
	temp.add(func);
	return temp;
}

const Polynomial Polynomial::operator-(const Polynomial& func)const
{
	Polynomial temp(*this), temp2(func);
	temp.add(-temp2);
	return temp;
}

const Polynomial Polynomial::operator*(const Polynomial& func)const
{
	Polynomial ret, t(*this);
	for (Node* cur = func.m_head->next; cur; cur = cur->next)
	{
		t.multiplication(*cur);
		ret = ret + t;
		t = *this;
	}
	return ret;
}

const Polynomial Polynomial::operator/(const Polynomial& func)const
{
	int index;
	double coef;
	Node n1, n2;
	Polynomial ret, t1(*this);

	for (n1 = t1.largestIndex(), n2 = func.largestIndex(); n1.node.second > n2.node.second; n1 = t1.largestIndex(), n2 = func.largestIndex())
	{
		coef = n1.node.first / n2.node.first;
		index = n1.node.second - n2.node.second;
		ret.add(coef, index);
		t1 -= func * Polynomial(coef, index);
	}
	return ret;
}

Polynomial& Polynomial::operator-()
{
	Node* cur = m_head->next;
	while (cur)
	{
		cur->node.first = -cur->node.first;
		cur = cur->next;
	}
	return *this;
}

Polynomial& Polynomial::operator=(const Polynomial& func)
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

const Polynomial Polynomial::operator+=(const Polynomial& func)
{
	add(func);
	checkZero();
	return *this;
}

const Polynomial Polynomial::operator-=(const Polynomial& func)
{
	Polynomial temp(func);
	add(-temp);
	checkZero();
	return *this;
}

const Polynomial Polynomial::operator*=(const Polynomial& func)
{
	*this = *this * func;
	return *this;
}

const Polynomial Polynomial::operator/=(const Polynomial& func)
{
	*this = *this / func;
	return *this;
}