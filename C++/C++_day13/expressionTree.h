#pragma once
#include "MyClass.h"
#include <string>
#include <iostream>

namespace lb
{
	using std::ostream;
	using std::string;
	class Expr_node
	{
	private:
		friend class Expr;
		friend ostream& operator<<(ostream & os, const Expr & en);
	public:
		virtual void print(ostream & os) const = 0;
		virtual int eval() const = 0;
		virtual ~Expr_node() { }
	};
	class Expr
	{
	private:
		UseCount m_uc;
		Expr_node *m_en;
	private:
		friend class Expr_node;
		friend ostream& operator<<(ostream & os, const Expr & en);
	public:
		Expr(const int data = 0);
		Expr(const string op, Expr opnd);
		Expr(const string op, Expr left, Expr right);
		Expr(const string op, Expr left, Expr middle, Expr right);
		Expr(const Expr & e) : m_en(e.m_en), m_uc(e.m_uc) { }
		~Expr() { if (m_uc.only()) delete m_en; }
		Expr& operator=(const Expr & e);
		int eval() const;
	};

	class Int_node : public Expr_node
	{
	private:
		int m_data;
	private:
		Int_node(const int data) : m_data(data) { }
		void print(ostream & os) const { os << m_data; }
		int eval() const { return m_data; }
		friend class Expr;
	};
	class Unary_node : public Expr_node
	{
	private:
		string m_op;
		Expr m_opnd;
	private:
		Unary_node(const string & op, Expr & opnd) : m_op(op), m_opnd(opnd) { }
		void print(ostream & os) const { os << "(" << m_op << m_opnd << ")"; }
		int eval() const;
		friend class Expr;
	};
	class Binary_node : public Expr_node
	{
	private:
		string m_op;
		Expr m_left;
		Expr m_right;
	private:
		Binary_node(const string & op, Expr & left, Expr & right) 
			: m_op(op), m_left(left), m_right(right) { }
		void print(ostream & os) const { os << "(" << m_left << m_op << m_right << ")"; }
		int eval() const;
		friend class Expr;
	};
	class Ternary_node : public Expr_node
	{
	private:
		string m_op;
		Expr m_left;
		Expr m_middle;
		Expr m_right;
	private:
		Ternary_node(const string & op, Expr & left, Expr & middle, Expr & right);
		void print(ostream & os) const 
		{ os << "(" << m_left << "?" << m_middle << ":" << m_right << ")"; }
		int eval() const;
		friend class Expr;
	};

	Expr::Expr(const int data)
	{
		m_en = new Int_node(data);
		if (data < 0) // 当为负数时,改为使用Unary_node类,输出带括号的负数
			*this = Expr("-", -data);
	}
	Expr::Expr(const string op, Expr opnd)
	{
		m_en = new Unary_node(op, opnd);
	}
	Expr::Expr(const string op, Expr left, Expr right)
	{
		m_en = new Binary_node(op, left, right);
	}
	Expr::Expr(const string op, Expr left, Expr middle, Expr right)
	{
		m_en = new Ternary_node(op, left, middle, right);
	}
	Expr& Expr::operator=(const Expr & e)
	{
		if (m_uc.reattach(e.m_uc))
			delete m_en;
		m_en = e.m_en;
		return *this;
	}
	int Expr::eval() const
	{
		return m_en->eval();
	}
	ostream& operator<<(ostream & os, const Expr & en)
	{
		en.m_en->print(os);
		return os;
	}

	int Unary_node::eval() const 
	{ 
		if (m_op == "-") 
			return -m_opnd.eval(); 
		throw "error, bad op " + m_op + "in Unary_node"; 
	}
	int Binary_node::eval() const
	{
		int op1 = m_left.eval(), op2 = m_right.eval();
		if (m_op == "+")
			return op1 + op2;
		if (m_op == "-")
			return op1 - op2;
		if (m_op == "*")
			return op1 * op2;
		if (m_op == "/" && op2 != 0)
			return op1 / op2;
		if (m_op == "==")
			return op1 == op2;
		if (m_op == "!=")
			return op1 != op2;
		if (m_op == ">")
			return op1 > op2;
		if (m_op == ">=")
			return op1 >= op2;
		if (m_op == "<")
			return op1 < op2;
		if (m_op == "<=")
			return op1 <= op2;
		if (m_op == "||")
			return op1 || op2;
		if (m_op == "&&")
			return op1 && op2;
		throw "error, bad op " + m_op + "in Binary_node";
	}
	Ternary_node::Ternary_node(const string & op, Expr & left, Expr & middle, Expr & right)
		: m_op(op), m_left(left), m_middle(middle), m_right(right)
	{
		if (m_op != "?:")
			throw "error, bad op " + m_op + "in Ternary_node";
	}
	int Ternary_node::eval() const
	{
		if (m_left.eval())
			return m_middle.eval();
		else
			return m_right.eval();
	}
}