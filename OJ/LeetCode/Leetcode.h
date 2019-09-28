#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*Definition for singly-linked list.*/
struct ListNode {
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

/*
 *
 * LinkList 文件夹
 *
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2); // 2. 两数相加

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

/*
 *
 * Vector 文件夹
 *
 */
 
vector<int> twoSum(vector<int>& nums, int target); // 1. 两数之和
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2); // 4. 寻找两个有序数组的中位数
int maxArea(vector<int>& height); // 11. 盛最多水的容器
vector<vector<int>> threeSum(vector<int>& nums); // 15. 三数之和
int threeSumClosest(vector<int>& nums, int target); // 16. 最接近的三数之和
