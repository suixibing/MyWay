#include "Leetcode.h"

/*
 *
 *	299. 猜数字游戏
 *
 *  	执行用时:		4 ms, 在所有 C++ 提交中击败了95.27%的用户
 *  	内存消耗:		9.1 MB, 在所有 C++ 提交中击败了5.30%的用户
 *
 */
string getHint(string secret, string guess)
{
	int i, cntA = 0, cntB = 0;
	char book1[10] = { 0 }, book2[10] = { 0 };
	for (i = 0; i < secret.size(); ++i)
	{
		if (secret[i] == guess[i])
			++cntA;
		else
		{
			++book1[secret[i] - '0'];
			++book2[guess[i] - '0'];
		}
	}
	for (i = 0; i < 10; ++i)
		cntB += min(book1[i], book2[i]);
	return to_string(cntA) + 'A' + to_string(cntB) + 'B';
}