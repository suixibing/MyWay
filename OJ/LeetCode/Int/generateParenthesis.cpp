#include "Leetcode.h"

/*
 *
 *	22. 括号生成
 *
 *  	执行用时 :		4 ms, 在所有 C++ 提交中击败了97.58%的用户
 *  	内存消耗 :		17.2 MB, 在所有 C++ 提交中击败了62.74%的用户
 *
 */
void getBracket(vector<string>& vec, string str, int lBracket, int rBracket, int aim)
{
	if (lBracket == aim && rBracket == aim)
		vec.push_back(str);
	if (lBracket < aim)
		getBracket(vec, str + '(', lBracket + 1, rBracket, aim);
	if (rBracket < lBracket)
		getBracket(vec, str + ')', lBracket, rBracket + 1, aim);
}
vector<string> generateParenthesis(int n) 
{
	vector<string> res;
	if (n > 0)
		getBracket(res, "", 0, 0, n);
	return res;
}