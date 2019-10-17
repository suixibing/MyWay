#pragma once

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
vector< vector<int> > generateMatrix(int n) // 59. 螺旋矩阵 II
string getPermutation(int n, int k); // 60. 第k个排列

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

/*
 *
 * Vector 文件夹
 *
 */
 
vector<int> twoSum(vector<int>& nums, int target); // 1. 两数之和
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2); // 4. 寻找两个有序数组的中位数
int maxArea(vector<int>& height); // 11. 盛最多水的容器
vector< vector<int> > threeSum(vector<int>& nums); // 15. 三数之和
int threeSumClosest(vector<int>& nums, int target); // 16. 最接近的三数之和
vector< vector<int> > fourSum(vector<int>& nums, int target); // 18. 四数之和
int removeDuplicates(vector<int>& nums); // 26. 删除排序数组中的重复项
int removeElement(vector<int>& nums, int val); // 27. 移除元素
void nextPermutation(vector<int>& nums); // 31. 下一个排列
int search(vector<int>& nums, int target); // 33. 搜索旋转排序数组
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
vector< vector<int> > merge(vector< vector<int> >& intervals); // 56. 合并区间
vector< vector<int> > insert(vector< vector<int> >& intervals, vector<int>& newInterval); // 57. 插入区间
