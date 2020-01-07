#include <iostream>
#include <unordered_map>
#include "hashTable.h"
using namespace std;

// unordered_map 解决问题
int repeatedNTimes(vector<int> &A)
{
	unordered_map<int, int> um;
	int n = A.size() / 2;

	for (auto & e : A)
	{
		um[e]++;
	}

	for (auto & e : um)
	{
		if (e.second == n)
		{
			return e.first;
		}
	}
	return -1;
}
int test()
{
	vector<int> v{ 1, 3, 4, 2, 3, 3 };

	cout << repeatedNTimes(v) << endl;

	return 0;
}

// 测试int的处理
int main1()
{
	hashTable<int, int> ht;
	ht.insert(pair<int, int>(1, 5));
	ht.insert(pair<int, int>(2, 7));
	ht.insert(pair<int, int>(5, 6));
	ht.insert(pair<int, int>(6, 8));
	ht.insert(pair<int, int>(12, 9));
	ht.insert(pair<int, int>(16, 4));

	ht.erase(6);
	ht.erase(12);

	return 0;
}

// 测试string的处理
int main2()
{
	hashTable<string, int, dealString> ht;

	ht.insert(pair<string, int>("abc", 1));
	ht.insert(pair<string, int>("def", 2));
	ht.insert(pair<string, int>("ghi", 3));
	ht.insert(pair<string, int>("jkl", 4));


	return 0;
}

// 得到素数表
bool judgePrime(long long n)
{
	long long sn = (long long)sqrt(n);
	for (int i = 2; i <= sn; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main3()
{
	int count = 0;
	unsigned long long n = 22, i, j;

	printf("%10u, ", 11);
	for (i = n; i < 3e9; i *= 2)
	{
		for (j = i; !judgePrime(j); ++j);
		++count;
		if (count % 5 == 0)
			cout << endl;
		printf("%10lld, ", j);
	}
	for (i = 0xffffffff; !judgePrime(j); --i);
	printf("%10lld, ", i);

	return 0;
}

// 测试扩充功能
int main4()
{
	hashTable<int, int> ht;

	ht.insert(pair<int, int>(1, 5));
	ht.insert(pair<int, int>(2, 7));
	ht.insert(pair<int, int>(5, 6));
	ht.insert(pair<int, int>(6, 8));
	ht.insert(pair<int, int>(12, 9));
	ht.insert(pair<int, int>(16, 4));
	ht.insert(pair<int, int>(23, 11));
	ht.insert(pair<int, int>(27, 13));
	ht.insert(pair<int, int>(33, 42));
	
	ht.insert(pair<int, int>(55, 24));

	return 0;
}

// 测试hashSet
int main()
{
	hashSet<int> hs, hs2;

	hs.insert(1);
	hs.insert(24);
	hs.insert(36);
	hs.insert(2);
	hs.insert(6);
	hs.insert(22);
	hs.insert(37);
	hs.insert(142);
	hs2.Swap(hs);

	hs.insert(364);
	hs.insert(466);
	hs.insert(67);
	hs.insert(74);
	hs.insert(232);
	hs.insert(376);
	
	hs.erase(232);
	
	return 0;
}