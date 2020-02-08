#include "Leetcode.h"

/*
 *
 *	8. 字符串转换整数 (atoi)
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了73.45%的用户
 *  	内存消耗:		8.5 MB, 在所有 C++ 提交中击败了78.70%的用户
 *
 */
int myAtoi1(string str)
{
	int i = 0, flag = 1, size = str.size();
	while (i < size && str[i] == ' ')
		i++;
	if (i >= size)
		return 0;
	switch (str[i])
	{
	case '-':
		flag = -1; // 不需要 break
	case '+':
		i++;
	default:
		break;
	}
	if (str[i] < '0' || str[i] > '9')
		return 0;
	long long res = str[i++] - '0';
	while (i < size && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (res > (long long)INT_MAX + 1)
			break;
	}
	res *= flag;
	return res > INT_MAX ? INT_MAX : (res < INT_MIN ? INT_MIN : res);
}

/*
 *
 *	8. 字符串转换整数 (atoi)
 *
 *  	执行用时:		0 ms, 在所有 C++ 提交中击败了100.00%的用户
 *  	内存消耗:		8.6 MB, 在所有 C++ 提交中击败了13.22%的用户
 *
 */
int myAtoi2(string str)
{
	double ret = 0;
	int i = 0, flag = 1;
	while (i < str.size() && isspace(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-' && (flag = -1))
		++i;
	else if (!isdigit(str[i]))
		return 0;
	while (i < str.size() && str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + str[i++] - '0';
	ret *= flag;
	return ret > INT_MAX ? INT_MAX : (ret < INT_MIN ? INT_MIN : ret);
}

int myAtoi(string str)
{
	return myAtoi1(str);
}