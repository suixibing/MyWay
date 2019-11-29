#pragma once

#include <vector>
#include <stack>

template <class T>
class TreeNode
{
	T m_data;
	TreeNode<T> *m_left;
	TreeNode<T> *m_right;
public:
	TreeNode(const T& val = T()):
		m_data(val),
		m_left(nullptr),
		m_right(nullptr)
	{}

	template <class T>
	friend class BinarySortTree;
};

template <class T>
class BinarySortTree
{
	TreeNode<T> *m_root;

	void destroy(TreeNode<T> *root)
	{
		if (root)
		{
			destroy(root->m_left);
			destroy(root->m_right);
			delete root;
		}
	}
public:
	BinarySortTree():
		m_root(nullptr)
	{}

	~BinarySortTree()
	{
		destroy(m_root);
		m_root = nullptr;
	}

	bool insert(const T& val)
	{
		if (m_root == nullptr)
		{
			m_root = new TreeNode<T>(val);
			return true;
		}

		TreeNode<T> *cur = m_root;
		TreeNode<T> *pre = nullptr;
		while (cur)
		{
			if (val == cur->m_data)
				return false;
			pre = cur;
			if (val < cur->m_data)
				cur = cur->m_left;
			else
				cur = cur->m_right;
		}
		cur = new TreeNode<T>(val);
		if (val < pre->m_data)
			pre->m_left = cur;
		else
			pre->m_right = cur;
		return true;
	}

	bool erase(const T& val)
	{
		if (m_root == nullptr)
			return false;

		TreeNode<T> *cur = m_root;
		TreeNode<T> *pre = nullptr;
		while (cur)
		{
			if (val == cur->m_data)
				break;
			pre = cur;
			if (val < cur->m_data)
				cur = cur->m_left;
			else
				cur = cur->m_right;
		}

		if (cur == nullptr)
			return false;
		if (cur->m_left && cur->m_right)
		{
			TreeNode<T> *cur2 = cur->m_left;
			TreeNode<T> *pre2 = cur;

			while (cur2 && cur2->m_right)
			{
				pre2 = cur2;
				cur2 = cur2->m_right;
			}
			if (pre2 != cur)
				pre2->m_right = cur2->m_left;
			cur2->m_right = cur->m_right;
			if (cur2 != cur->m_left)
				cur2->m_left = cur->m_left;
			else
				cur2->m_left = nullptr;
			if (pre && cur->m_data < pre->m_data)
				pre->m_left = cur2;
			else if (pre)
				pre->m_right = cur2;
			else
				m_root = cur2;
		}
		else if (pre)
		{
			if (cur->m_data < pre->m_data)
				pre->m_left = cur->m_left ? cur->m_left : cur->m_right;
			else
				pre->m_right = cur->m_left ? cur->m_left : cur->m_right;
		}
		else
			m_root = cur->m_left ? cur->m_left : cur->m_right;
		delete cur;
		return true;
	}

	std::vector<T> InOrder()
	{
		std::stack<TreeNode<T>*> s;
		std::vector<T> res;
		TreeNode<T> *cur = m_root;

		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->m_left;
			}
			cur = s.top();
			res.push_back(cur->m_data);
			s.pop();
			cur = cur->m_right;
		}
		return res;
	}

};
