#include "Leetcode.h"

/*
 *
 *	8. 字符串转换整数 (atoi)
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了73.45%的用户
 *  	内存消耗:		8.5 MB, 在所有 C++ 提交中击败了78.70%的用户
 *
 */
int myAtoi(string str)
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
		break;
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
		{
			break;
		}
	}
	res *= flag;
	return res > INT_MAX ? INT_MAX : (res < INT_MIN ? INT_MIN : res);
}
