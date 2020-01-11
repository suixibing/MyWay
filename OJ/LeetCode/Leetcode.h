#ifndef _LEETCODE_H_
#define _LEETCODE_H_

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*Definition for singly-linked list.*/
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*Definition for a binary tree node.*/
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 *
 * Int 文件夹
 *
 */
 
int reverse(int x); // 7. 整数反转
bool isPalindrome(int x); // 9. 回文数
string intToRoman(int num); // 12. 整数转罗马数字
vector<string> generateParenthesis(int n); // 22. 括号生成
int divide(int dividend, int divisor); // 29. 两数相除
string countAndSay(int n); // 38. 报数
double myPow(double x, int n); // 50. Pow(x, n)
vector< vector<string> > solveNQueens(int n); // 51. N皇后
vector< vector<int> > generateMatrix(int n); // 59. 螺旋矩阵 II
string getPermutation(int n, int k); // 60. 第k个排列
int uniquePaths(int m, int n); // 62. 不同路径
int mySqrt(int x); // 69. x 的平方根
int climbStairs(int n); // 70. 爬楼梯
vector< vector<int> > combine(int n, int k); // 77. 组合
vector<int> grayCode(int n); // 89. 格雷编码
vector< vector<int> > generate(int numRows); // 118. 杨辉三角
vector<int> getRow(int rowIndex); // 119. 杨辉三角 II
uint32_t reverseBits(uint32_t n); // 190. 颠倒二进制位
int hammingWeight(uint32_t n); // 191. 位1的个数
bool isHappy(int n); // 202. 快乐数
int countPrimes(int n); // 204. 计数质数
bool isIsomorphic(string s, string t); // 205. 同构字符串
bool isPowerOfTwo(int n); // 231. 2的幂
int addDigits(int num); // 258. 各位相加
bool isUgly(int num); // 263. 丑数

/*
 *
 * LinkList 文件夹
 *
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2); // 2. 两数相加
ListNode* removeNthFromEnd(ListNode* head, int n); // 19. 删除链表的倒数第N个节点
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2); // 21. 合并两个有序链表
ListNode* mergeKLists(vector<ListNode*>& lists); // 23. 合并K个排序链表
ListNode* swapPairs(ListNode* head); // 24. 两两交换链表中的节点
ListNode* reverseKGroup(ListNode* head, int k); // 25. K 个一组翻转链表
ListNode* rotateRight(ListNode* head, int k); // 61. 旋转链表
ListNode* deleteDuplicates_82(ListNode* head); // 82. 删除排序链表中的重复元素 II
ListNode* deleteDuplicates_83(ListNode* head); // 83. 删除排序链表中的重复元素
ListNode* partition(ListNode* head, int x); // 86. 分隔链表
bool hasCycle(ListNode *head); // 141. 环形链表
ListNode* removeElements(ListNode* head, int val); // 203. 移除链表元素
bool isPalindrome(ListNode* head); // 234. 回文链表
void deleteNode(ListNode* node); // 237. 删除链表中的节点

/*
 *
 * String 文件夹
 *
 */
 
int lengthOfLongestSubstring(string s); // 3. 无重复字符的最长子串
string longestPalindrome(string s); // 5. 最长回文子串
string convert(string s, int numRows); // 6. Z 字形变换
int myAtoi(string str); // 8. 字符串转换整数 (atoi)
int romanToInt(string s); // 13. 罗马数字转整数
string longestCommonPrefix(vector<string>& strs); // 14. 最长公共前缀
vector<string> letterCombinations(string digits); // 17. 电话号码的字母组合
bool isValid(string s); // 20. 有效的括号
int strStr(string haystack, string needle); // 28. 实现 strStr()
vector<int> findSubstring(string s, vector<string>& words); // 30. 串联所有单词的子串
string multiply(string num1, string num2); // 43. 字符串相乘
int lengthOfLastWord(string s); // 58. 最后一个单词的长度
bool isNumber(string s); // 65. 有效数字
string addBinary(string a, string b); // 67. 二进制求和
string simplifyPath(string path); // 71. 简化路径
int minDistance(string word1, string word2); // 72. 编辑距离
string minWindow(string s, string t); // 76. 最小覆盖子串
bool isInterleave(string s1, string s2, string s3); // 97. 交错字符串
bool isAnagram(string s, string t); // 242. 有效的字母异位词

/*
 *
 * TreeNode 文件夹
 *
 */

vector<int> inorderTraversal(TreeNode* root); // 94. 二叉树的中序遍历
bool isSameTree(TreeNode* p, TreeNode* q); // 100. 相同的树
bool isSymmetric(TreeNode* root); // 101. 对称二叉树
int maxDepth(TreeNode* root); // 104. 二叉树的最大深度
vector< vector<int> > levelOrderBottom(TreeNode* root); // 107. 二叉树的层次遍历 II
int minDepth(TreeNode* root); // 111. 二叉树的最小深度
bool hasPathSum(TreeNode* root, int sum); // 112. 路径总和
TreeNode* invertTree(TreeNode* root); // 226. 翻转二叉树
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q); // 235. 二叉搜索树的最近公共祖先

/*
 *
 * Vector 文件夹
 *
 */
 
vector<int> twoSum_1(vector<int>& nums, int target); // 1. 两数之和
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2); // 4. 寻找两个有序数组的中位数
int maxArea(vector<int>& height); // 11. 盛最多水的容器
vector< vector<int> > threeSum(vector<int>& nums); // 15. 三数之和
int threeSumClosest(vector<int>& nums, int target); // 16. 最接近的三数之和
vector< vector<int> > fourSum(vector<int>& nums, int target); // 18. 四数之和
int removeDuplicates_26(vector<int>& nums); // 26. 删除排序数组中的重复项
int removeElement(vector<int>& nums, int val); // 27. 移除元素
void nextPermutation(vector<int>& nums); // 31. 下一个排列
int search_33(vector<int>& nums, int target); // 33. 搜索旋转排序数组
vector<int> searchRange(vector<int>& nums, int target); // 34. 在排序数组中查找元素的第一个和最后一个位置
int searchInsert(vector<int>& nums, int target); // 35. 搜索插入位置
bool isValidSudoku(vector< vector<char> >& board); // 36. 有效的数独
int firstMissingPositive(vector<int>& nums); // 41. 缺失的第一个正数
int jump(vector<int>& nums); // 45. 跳跃游戏 II
vector< vector<int> > permute(vector<int>& nums); // 46. 全排列
vector< vector<int> > permuteUnique(vector<int>& nums); // 47. 全排列 II
vector< vector<string> > groupAnagrams(vector<string>& strs); // 49. 字母异位词分组
int maxSubArray(vector<int>& nums); // 53. 最大子序和
vector<int> spiralOrder(vector< vector<int> >& matrix); // 54. 螺旋矩阵
bool canJump(vector<int>& nums); // 55. 跳跃游戏
vector< vector<int> > merge_56(vector< vector<int> >& intervals); // 56. 合并区间
vector< vector<int> > insert(vector< vector<int> >& intervals, vector<int>& newInterval); // 57. 插入区间
int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid); // 63. 不同路径 II
int minPathSum(vector< vector<int> >& grid); // 64. 最小路径和
vector<int> plusOne(vector<int>& digits); // 66. 加一
vector<string> fullJustify(vector<string>& words, int maxWidth); // 68. 文本左右对齐
void setZeroes(vector< vector<int> >& matrix); // 73. 矩阵置零
bool searchMatrix(vector< vector<int> >& matrix, int target); // 74. 搜索二维矩阵
void sortColors(vector<int>& nums); // 75. 颜色分类
vector< vector<int> > subsets(vector<int>& nums); // 78. 子集
bool exist(vector< vector<char> >& board, string word); // 79. 单词搜索
int removeDuplicates_80(vector<int>& nums); // 80. 删除排序数组中的重复项 II
bool search_81(vector<int>& nums, int target); // 81. 搜索旋转排序数组 II
int largestRectangleArea(vector<int>& heights); // 84. 柱状图中最大的矩形
int maximalRectangle(vector< vector<char> >& matrix); // 85. 最大矩形
void merge_88(vector<int>& nums1, int m, vector<int>& nums2, int n); // 88. 合并两个有序数组
void subfunc(vector<int>& nums, int pos, vector<int>& tmp, vector< vector<int> >& res); // 90. 子集 II
int maxProfit(vector<int>& prices); // 121. 买卖股票的最佳时机
vector<int> twoSum_167(vector<int>& numbers, int target); // 167. 两数之和 II - 输入有序数组
int majorityElement(vector<int>& nums); // 169. 多数元素
void rotate(vector<int>& nums, int k); // 189. 旋转数组
bool containsDuplicate(vector<int>& nums); // 217. 存在重复元素
int missingNumber(vector<int>& nums); // 268. 缺失数字

#endif /* _LEETCODE_H_ */