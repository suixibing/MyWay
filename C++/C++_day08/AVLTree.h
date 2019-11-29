#pragma once

#include <vector>
#include <stack>

template <class T>
class TreeNode
{
	int m_bf;
	T m_data;
	TreeNode<T> *m_left;
	TreeNode<T> *m_right;
	TreeNode<T> *m_parent;
public:
	TreeNode(const T& val = T()) :
		m_bf(0),
		m_data(val),
		m_left(nullptr),
		m_right(nullptr),
		m_parent(nullptr)
	{}

	template <class T>
	friend class AVLTree;
};

template <class T>
class AVLTree
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

	void lRound(TreeNode<T>* pre)
	{
		TreeNode<T> *parent = pre->m_parent;
		TreeNode<T> *cur = pre->m_right;

		cur->m_parent = parent;
		if (parent)
		{
			if (parent->m_left == pre)
				parent->m_left = cur;
			else
				parent->m_right = cur;
		}
		else
			m_root = cur;
		
		pre->m_right = cur->m_left;
		if (pre->m_right)
			pre->m_right->m_parent = pre;

		cur->m_left = pre;
		pre->m_parent = cur;

		cur->m_bf = pre->m_bf = 0;
	}

	void rRound(TreeNode<T>* pre)
	{
		TreeNode<T> *parent = pre->m_parent;
		TreeNode<T> *cur = pre->m_left;

		cur->m_parent = parent;
		if (parent)
		{
			if (parent->m_left == pre)
				parent->m_left = cur;
			else
				parent->m_right = cur;
		}
		else
			m_root = cur;

		pre->m_left = cur->m_right;
		if (pre->m_left)
			pre->m_left->m_parent = pre;

		cur->m_right = pre;
		pre->m_parent = cur;

		cur->m_bf = pre->m_bf = 0;
	}

	void lrRound(TreeNode<T> *pre)
	{
		TreeNode<T> *left = pre->m_left;
		TreeNode<T> *newroot = left->m_right;
		int flag = newroot->m_bf;

		lRound(pre->m_left);
		rRound(pre);

		if (flag == -1)
			pre->m_bf = 1;
		else if (flag == 1)
			left->m_bf = -1;
	}

	void rlRound(TreeNode<T> *pre)
	{
		TreeNode<T> *right = pre->m_right;
		TreeNode<T> *newroot = right->m_left;
		int flag = newroot->m_bf;

		rRound(pre->m_right);
		lRound(pre);

		if (flag == -1)
			right->m_bf = 1;
		else if (flag == 1)
			pre->m_bf = -1;
	}
public:
	AVLTree() :
		m_root(nullptr)
	{}

	~AVLTree()
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
		cur->m_parent = pre;
		while (pre)
		{
			if (pre->m_left == cur)
				--pre->m_bf;
			else if (pre->m_right == cur)
				++pre->m_bf;
			if (pre->m_bf == 0)
				break;
			else if (pre->m_bf == 1 || pre->m_bf == -1)
			{
				cur = pre;
				pre = pre->m_parent;
			}
			else
			{
				if (pre->m_bf == 2)
				{
					if (cur->m_bf == 1)
						lRound(pre);
					else
						rlRound(pre);
				}
				else
				{
					if (cur->m_bf == 1)
						lrRound(pre);
					else
						rRound(pre);
				}
				break;
			}
		}
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
