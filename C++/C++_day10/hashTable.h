#pragma once

// ��ɢ��ʵ��
#include <map>
#include <vector>
using namespace std;

enum State
{
	EMPTY,
	EXIST,
	DELETE
};

class dealInt
{
public:
	int operator()(int n)
	{
		return n;
	}

class dealString
{
public:
	int operator()(const string & s)
	{
		int sum = 0, seed = 131;
		for (const char & c : s)
		{
			sum = sum * seed + c;
		}
		return sum & 0x7FFFFFFF;
	}
};

template<class K, class V, class SWITCH = dealInt>
class hashTable
{
	struct elem
	{
		pair<K, V> m_val;
		State m_state;

		elem(const K & key = K(), const V & val = V(), State state = EMPTY) :
			m_val(key, val),
			m_state(state)
		{}
	};
private:
	vector<elem> m_table;
	size_t m_size;
	static const unsigned int s_m_primeTable[30];
	int m_primePos;
public:
	hashTable(size_t capacity = s_m_primeTable[0]) :
		m_table(capacity),
		m_size(0),
		m_primePos(0)
	{}

	bool insert(const pair<K, V> & val)
	{
		if ((long long)m_size * 100 / capacity() > 75)
			reserve();

		int n = hashFunc(val.first);

		while (m_table[n].m_state == EXIST)
		{
			if (m_table[n].m_val.first == val.first)
				return false;
			++n;
			if (n == capacity())
				n = 0;
		}
		m_table[n].m_val = val;
		m_table[n].m_state = EXIST;
		++m_size;
		return true;
	}

	size_t find(const K & key)
	{
		int n = hashFunc(key);

		while (m_table[n].m_state != EMPTY)
		{
			if (m_table[n].m_state == EXIST && m_table[n].m_val.first == key)
				return n;
			++n;
			if (n == capacity())
				n = 0;
		}
		return -1;
	}

	bool erase(const K & key)
	{
		int n = find(key);
		if (n < 0)
			return false;
		m_table[n].m_state = DELETE;
		--m_size;
		return true;
	}

	size_t capacity()
	{
		return m_table.size();
	}

	size_t size()
	{
		return m_size;
	}

	size_t empty()
	{
		return m_size == 0;
	}

	void Swap(hashTable<K, V> & ht)
	{
		m_table.swap(ht.m_table);
		swap(m_size, ht.m_size);
		swap(m_primePos, ht.m_primePos);
	}

private:
	int hashFunc(const K & key)
	{
		SWITCH func;
		return func(key) % capacity();
	}

	void reserve()
	{
		vector<elem> tmp(m_table);
		m_table.clear();
		m_table.resize(s_m_primeTable[++m_primePos]);
		m_size = 0;
		for (auto & e : tmp)
		{
			if (e.m_state == EXIST)
				insert(e.m_val);
		}
	}
};

template<class K, class V, class SWITCH>
const unsigned int hashTable<K, V, SWITCH>::s_m_primeTable[30] = {
		11,         23,         47,         89,        179,
	   353,        709,       1409,       2819,       5639,
	 11273,      22531,      45061,      90121,     180233,
	360457,     720899,    1441807,    2883593,    5767169,
  11534351,   23068673,   46137359,   92274737,  184549429,
 369098771,  738197549, 1476395029, 2952790033,	4294967295,
};

// ��ɢ��ʵ��
template<class T>
class hashBucketNode
{
private:
	T m_val;
	hashBucketNode<T> *m_next;

public:
	hashBucketNode(const T & val = T()) :
		m_val(val),
		m_next(nullptr)
	{}

	template<class T, class SWITCH>
	friend class hashSet;
};

template<class T, class SWITCH = dealInt>
class hashSet
{
	vector<hashBucketNode<T>*> m_data;
	size_t m_bucketNum;
	size_t m_size;
public:
	hashSet(size_t capacity = 11) :
		m_data(11, nullptr),
		m_bucketNum(capacity),
		m_size(0)
	{}

	bool insert(const T & val)
	{
		int hashnum = hashFunc(val);
		hashBucketNode<T> *tmp;

		if (m_data[hashnum])
		{
			for (tmp = m_data[hashnum]; tmp; tmp = tmp->m_next)
			{
				if (tmp->m_val == val)
					return false;
			}
		}
		tmp = new hashBucketNode<T>(val);
		tmp->m_next = m_data[hashnum];
		m_data[hashnum] = tmp;
		++m_size;
		return true;
	}

	bool erase(const T & val)
	{
		int hashnum = hashFunc(val);
		hashBucketNode<T> *tmp;

		if (!m_data[hashnum])
			return false;

		if (m_data[hashnum]->m_val == val)
		{
			tmp = m_data[hashnum];
			m_data[hashnum] = tmp->m_next;
			delete tmp;
			--m_size;
			return true;
		}
		else
		{
			for (tmp = m_data[hashnum]; tmp->m_next; tmp = tmp->m_next)
			{
				if (tmp->m_next->m_val == val)
				{
					hashBucketNode<T> *cur = tmp->m_next;
					tmp->m_next = cur->m_next;
					delete cur;
					--m_size;
					return true;
				}
			}
			return false;
		}
	}

	size_t capacity()
	{
		return m_bucketNum;
	}

	size_t size()
	{
		return m_size;
	}

	size_t empty()
	{
		return m_size == 0;
	}

	void Swap(hashSet<T> & hs)
	{
		m_data.swap(hs.m_data);
		swap(m_size, hs.m_size);
		swap(m_bucketNum, hs.m_bucketNum);
	}

private:
	int hashFunc(const T & val)
	{
		SWITCH func;
		return func(val) % m_bucketNum;
	}
};