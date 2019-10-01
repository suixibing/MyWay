#include "Leetcode.h"

/*
 *
 *	30. 串联所有单词的子串
 *
 *  	执行用时:		1672 ms, 在所有 C++ 提交中击败了5.97%的用户
 *  	内存消耗:		458.1 MB, 在所有 C++ 提交中击败了5.20%的用户
 *
 */
vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> res;
	if (words.empty() || s.empty())
		return res;
	int i, j, wordSize = words[0].size(), wordsNum = words.size(), strSize = s.size();
	sort(words.begin(), words.end());
	for (i = 0; i <= strSize - wordSize * wordsNum; i++)
	{
		vector<string> tmpVec;
		for (j = 0; j < wordSize * wordsNum; j += wordSize)
		{
			tmpVec.push_back(s.substr(i + j, wordSize));
		}
		sort(tmpVec.begin(), tmpVec.end());
		if (tmpVec == words)
			res.push_back(i);
	}
	return res;
}