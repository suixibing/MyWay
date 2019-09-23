#pragma once

#include <iostream>
#include <vector>
#include <string>

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
 
int reverse(int x); 									// 7. 整数反转

/*
 *
 * LinkList 文件夹
 *
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);	// 2. 两数相加

/*
 *
 * String 文件夹
 *
 */
 
int lengthOfLongestSubstring(string s);					// 3. 无重复字符的最长子串
string longestPalindrome(string s);						// 5. 最长回文子串
string convert(string s, int numRows);					// 6. Z 字形变换

/*
 *
 * Vector 文件夹
 *
 */
 
vector<int> twoSum(vector<int>& nums, int target);		// 1. 两数之和
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);	// 4. 寻找两个有序数组的中位数
