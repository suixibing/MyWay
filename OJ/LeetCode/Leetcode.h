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
 * Int �ļ���
 *
 */
 
int reverse(int x); 									// 7. ������ת
bool isPalindrome(int x); 								// 9. ������

/*
 *
 * LinkList �ļ���
 *
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);	// 2. �������

/*
 *
 * String �ļ���
 *
 */
 
int lengthOfLongestSubstring(string s);					// 3. ���ظ��ַ�����Ӵ�
string longestPalindrome(string s);						// 5. ������Ӵ�
string convert(string s, int numRows);					// 6. Z ���α任
int myAtoi(string str);									// 8. �ַ���ת������ (atoi)

/*
 *
 * Vector �ļ���
 *
 */
 
vector<int> twoSum(vector<int>& nums, int target);		// 1. ����֮��
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);	// 4. Ѱ�����������������λ��
int maxArea(vector<int>& height);						// 11. ʢ���ˮ������
