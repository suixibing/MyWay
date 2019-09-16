#include "Func.h"

Func::Func(Func& func)
{
	head = new Node;
	head->next = nullptr;
	Node *cur = func.head->next, *now = head, *tmp;
	while (cur)
	{
		tmp = new Node;
		tmp->node = cur->node;

		tmp->next = now->next;
		now->next = tmp;
		now = tmp;
		cur = cur->next;
	}
}

Func::~Func()
{
	Node *tmp;
	while (head->next)
	{
		tmp = head->next;
		head->next = tmp->next;
		delete tmp;
	}
	delete head;
}

void Func::add()
{
	double coef;
	int index;
	Node *cur, *tmp;

	cin >> coef >> index;
	pair<double, int> node(coef, index);
	tmp = new Node;
	tmp->node = node;
	for (cur = head; cur->next && cur->next->node.second > index; cur = cur->next)
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
}

void Func::add(Func& func)
{
	Node *cur = func.head->next, *tmp;

	while (cur)
	{
		for (tmp = head; tmp->next && tmp->next->node.second > cur->node.second; tmp = tmp->next)
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
}

void Func::show()const
{
	Node* cur = head->next;

	while (cur)
	{
		cout << cur->node.first << "^" << cur->node.second;
		if (cur->next)
		{
			cout << " + ";
		}
		cur = cur->next;
	}
	cout << endl;
}

void Func::derivative()
{
	Node* cur = head->next;

	while (cur)
	{
		cur->node.first *= cur->node.second;
		--cur->node.second;
		cur = cur->next;
	}
	for (cur = head; cur && cur->next; cur = cur->next)
	{
		if (cur->next->node.first == 0)
		{
			Node* tmp = cur->next;
			cur->next = tmp->next;
			delete tmp;
		}
	}
}

Func& Func::operator=(Func& func)
{
	Node *cur = func.head->next, *tmp, *h = head;
	if (&func == this)
	{
		return *this;
	}
	while (head->next)
	{
		tmp = head->next;
		head->next = tmp->next;
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