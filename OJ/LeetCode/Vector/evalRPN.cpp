#include "Leetcode.h"

/*
 *
 *	150. 逆波兰表达式求值
 *
 *  	执行用时:		16 ms, 在所有 C++ 提交中击败了74.96%的用户
 *  	内存消耗:		13.2 MB, 在所有 C++ 提交中击败了5.03%的用户
 *
 */
int evalRPN(vector<string>& tokens)
{
	int op1, op2, ret = 0;
	string tmp = tokens[tokens.size() - 1];
	if (tmp != "+" && tmp != "-" && tmp != "*" && tmp != "/")
		return atoi(tmp.c_str());
	else
	{
		tokens.pop_back();
		op2 = evalRPN(tokens);
		tokens.pop_back();
		op1 = evalRPN(tokens);
	}
	if (tmp == "+")
		return op1 + op2;
	else if (tmp == "-")
		return op1 - op2;
	else if (tmp == "*")
		return op1 * op2;
	else
		return op1 / op2;
}