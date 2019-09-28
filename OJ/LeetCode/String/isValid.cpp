#include "Leetcode.h"

/*
 *
 *	20. 有效的括号
 *
 *  	执行用时 :		4 ms, 在所有 C++ 提交中击败了78.99%的用户
 *  	内存消耗 :		8.4 MB, 在所有 C++ 提交中击败了89.38%的用户
 *
 */
bool isValid(string s)
{
	stack<char> sta;
	int i, size = s.size();
	if (size % 2)
		return false;
	for (i = 0; i < size; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			sta.push(s[i]);
		else if (s[i] == ')' && !sta.empty() && '(' == sta.top())
			sta.pop();
		else if (s[i] == ']' && !sta.empty() && '[' == sta.top())
			sta.pop();
		else if (s[i] == '}' && !sta.empty() && '{' == sta.top())
			sta.pop();
		else
			return false;
	}
	if (!sta.empty())
		return false;
	return true;
}