#include "Leetcode.h"

/*
 *
 *	79. 单词搜索
 *
 *  	执行用时:		24 ms, 在所有 C++ 提交中击败了94.48%的用户
 *  	内存消耗:		9.9 MB, 在所有 C++ 提交中击败了97.86%的用户
 *
 */
bool subExist(vector< vector<char> >& board, string& word, int pos, int x, int y)
{
	if (pos >= word.size())
		return true;
	int offx, offy;
	int offset[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
	for (int i = 0; i < 4; ++i)
	{
		offx = x + offset[i][0];
		offy = y + offset[i][1];
		if (offx >= 0 && offx < board.size() && offy >= 0 && offy < board[0].size() && board[offx][offy] == word[pos])
		{
			board[offx][offy] = ' ';
			if (pos + 1 == word.size() || subExist(board, word, pos + 1, offx, offy))
				return true;
			board[offx][offy] = word[pos];
		}
	}
	return false;
}
bool exist(vector< vector<char> >& board, string word)
{
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] == word[0])
			{
				board[i][j] = ' ';
				if (subExist(board, word, 1, i, j))
					return true;
				board[i][j] = word[0];
			}
		}
	}
	return false;
}