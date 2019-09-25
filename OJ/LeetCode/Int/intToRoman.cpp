#include "Leetcode.h"

/*
 *
 *	12. 整数转罗马数字
 *
 *  	执行用时:		8 ms, 在所有 C++ 提交中击败了92.39%的用户
 *  	内存消耗:		8.2 MB, 在所有 C++ 提交中击败了97.89%的用户
 *
 */
string intToRoman(int num)
{
	string res;
	while (num)
	{
		if (num / 1000)
		{
			res += "M";
			num -= 1000;
		}
		else if (num / 900)
		{
			res += "CM";
			num -= 900;
		}
		else if (num / 500)
		{
			res += "D";
			num -= 500;
		}
		else if (num / 400)
		{
			res += "CD";
			num -= 400;
		}
		else if (num / 100)
		{
			res += "C";
			num -= 100;
		}
		else if (num / 90)
		{
			res += "XC";
			num -= 90;
		}
		else if (num / 50)
		{
			res += "L";
			num -= 50;
		}
		else if (num / 40)
		{
			res += "XL";
			num -= 40;
		}
		else if (num / 10)
		{
			res += "X";
			num -= 10;
		}
		else if (num / 9)
		{
			res += "IX";
			num -= 9;
		}
		else if (num / 5)
		{
			res += "V";
			num -= 5;
		}
		else if (num / 4)
		{
			res += "IV";
			num -= 4;
		}
		else
		{
			res += "I";
			num--;
		}
	}
	return res;
}