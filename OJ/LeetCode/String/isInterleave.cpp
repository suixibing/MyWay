#include "Leetcode.h"

/*
 *
 *	97. 交错字符串
 *
 *  	执行用时:		176 ms, 在所有 C++ 提交中击败了5.10%的用户
 *  	内存消耗:		120 MB, 在所有 C++ 提交中击败了5.26%的用户
 *		有一个例子超长子串因为递归次数过多通过不了
 *		"bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
 *		"babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
 *		"babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
 *
 */
bool isInterleave(string s1, string s2, string s3)
{
	int i, j, k;
	for (i = j = k = 0; i < s1.size() && j < s2.size() && s1[i] != s2[j]; ++k)
	{
		if (s1[i] == s3[k])
			++i;
		else if (s2[j] == s3[k])
			++j;
		else
			return false;
	}
	if (i == s1.size())
		return s2.substr(j) == s3.substr(k);
	else if (j == s2.size())
		return s1.substr(i) == s3.substr(k);
	if (s1[i] == s2[j] && s1[i] != s3[k])
		return false;
	return isInterleave(s1.substr(i + 1), s2.substr(j), s3.substr(k + 1)) || isInterleave(s1.substr(i), s2.substr(j + 1), s3.substr(k + 1));
}