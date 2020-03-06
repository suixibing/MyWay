#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <memory>
#include <utility>
#include <iterator>
#include <stdexcept>
#include <algorithm>

namespace lb
{
	const int DEBUG = 0; // 调试所有的非比较行为
	const int PRIVATE_SWITCH = 0; // 调试私有函数
	const int INSERT_SWITCH = 0; // 调试插入、删除
	const int COPY_SWITCH = 0; // 调试移动语义、拷贝语义、构造函数、析构函数
	const int INSERT_DEBUG = DEBUG + INSERT_SWITCH;
	const int PRIVATE_DEBUG = DEBUG + PRIVATE_SWITCH;
	const int COPY_DEBUG = DEBUG + COPY_SWITCH;

	template <class T, class Alloc = std::allocator<T>>
	class Vector
	{
		using value_type = T;
		using size_type = size_t;
		using allocator_type = typename Alloc;
		using pointer = T * ;
		using const_pointer = const T *;
		using iterator = T * ;
		using const_iterator = const T *;
		using reference = T & ;
		using const_reference = const T &;

	private:
		static allocator_type m_s_alloc;
		pointer m_elements;
		pointer m_firstFree;
		pointer m_capacity;

	private:
		void _free()
		{
			if (PRIVATE_DEBUG)
				std::cout << "_free()" << std::endl;
			if (m_elements)
			{
				clear();
				m_s_alloc.deallocate(m_elements, m_capacity - m_elements);
			}
		}
		void _reallocate()
		{
			if (PRIVATE_DEBUG)
				std::cout << "_reallocate()" << std::endl;
			size_type newCapa = capacity() ? 2 * capacity() : 1;
			iterator newBegin = m_s_alloc.allocate(newCapa);
			iterator newEnd = std::uninitialized_copy(std::make_move_iterator(begin()),
				std::make_move_iterator(end()), newBegin); // 移动原来保存的元素到新位置
			_free();
			m_elements = newBegin;
			m_firstFree = newEnd;
			m_capacity = newBegin + newCapa;
		}
		void _check_alloc()
		{
			if (PRIVATE_DEBUG)
				std::cout << "_check_alloc()" << std::endl;
			if (m_firstFree == m_capacity)
				_reallocate();
		}
		void _check_alloc(const size_type n)
		{
			if (PRIVATE_DEBUG)
				std::cout << "_check_alloc(const size_type n)" << std::endl;
			while (capacity() < n)
				_reallocate();
		}
		std::pair<iterator, iterator>
			_alloc_n_copy(const_iterator begin, const_iterator end, size_type &n = 0)
		{
			if (PRIVATE_DEBUG)
				std::cout << "_alloc_n_copy(const_iterator begin, const_iterator end, size_type &n = 0)" << std::endl;
			if (end - begin > n)
				n = end - begin;
			iterator data = m_s_alloc.allocate(n);
			return { data, std::uninitialized_copy(begin, end, data) };
		}

	public:
		Vector() : m_elements(nullptr), m_firstFree(nullptr), m_capacity(nullptr) { }
		explicit Vector(const size_type cnt, const value_type& val = value_type())
		{
			if (COPY_DEBUG)
				std::cout << "Vector(const size_type cnt, const value_type& val = value_type())" << std::endl;
			m_elements = m_s_alloc.allocate(cnt);
			m_firstFree = m_capacity = std::uninitialized_fill_n(m_elements, cnt, val);
		}
		template<class Iter, class = std::enable_if_t<std::_Is_iterator_v<Iter>>>
		Vector(Iter itBegin, Iter itEnd) // 模仿vector实现的利用迭代器进行的构造函数
		{
			if (COPY_DEBUG)
				std::cout << "Vector(Iter itBegin, Iter itEnd)" << std::endl;
			m_elements = m_s_alloc.allocate(itEnd - itBegin);
			m_firstFree = m_capacity = std::uninitialized_copy(itBegin, itEnd, m_elements);
		}
		Vector(const Vector &v)
		{
			if (COPY_DEBUG)
				std::cout << "Vector(const Vector &v)" << std::endl;
			size_type n = 0;
			std::pair<iterator, iterator> data = _alloc_n_copy(v.begin(), v.end(), n);
			m_elements = data.first;
			m_firstFree = m_capacity = data.second;
		}
		Vector(Vector &&v) noexcept
			: m_elements(std::move(v.m_elements)), m_firstFree(std::move(v.m_firstFree)), m_capacity(std::move(v.m_capacity))
		{
			if (COPY_DEBUG)
				std::cout << "Vector(Vector &&v) noexcept" << std::endl;
			v.m_elements = v.m_firstFree = v.m_capacity = nullptr;
		}
		Vector(std::initializer_list<value_type> lst)
		{
			if (COPY_DEBUG)
				std::cout << "Vector(std::initializer_list<value_type> lst)" << std::endl;
			for (auto &i : lst)
				push_back(i);
		}
		~Vector()
		{
			if (COPY_DEBUG)
				std::cout << "~Vector()" << std::endl;
			_free();
		}
		// 拷贝赋值运算符，只允许左值进行赋值
		Vector& operator=(const Vector &v) &
		{
			if (COPY_DEBUG)
				std::cout << "operator=(const Vector &v) &" << std::endl;
			size_type n = 0;
			std::pair<iterator, iterator> data = _alloc_n_copy(v.begin(), v.end(), n);
			_free();
			m_elements = data.first;
			m_firstFree = m_capacity = data.second;
			return *this;
		}
		// 移动赋值运算符，只允许左值进行赋值且不会报错
		Vector& operator=(Vector &&v) & noexcept
		{
			if (COPY_DEBUG)
				std::cout << "operator=(Vector &&v) &" << std::endl;
			if (this != &v)
			{
				m_elements = v.m_elements;
				m_firstFree = v.m_firstFree;
				m_capacity = v.m_capacity;
				v.m_elements = v.m_firstFree = v.m_capacity = nullptr;
			}
			return *this;
		}
		void assign(const size_type cnt, const value_type& val = value_type())
		{
			if (COPY_DEBUG)
				std::cout << "assign(const size_type cnt, const value_type& val = value_type())" << std::endl;
			*this = Vector(cnt, val);
		}
		template<class Iter, class = std::enable_if_t<std::_Is_iterator_v<Iter>>>
		void assign(Iter itBegin, Iter itEnd)
		{
			if (COPY_DEBUG)
				std::cout << "assign(Iter itBegin, Iter itEnd)" << std::endl;
			*this = Vector(itBegin, itEnd);
		}
		void assign(std::initializer_list<T> lst)
		{
			if (COPY_DEBUG)
				std::cout << "assign(std::initializer_list<T> lst)" << std::endl;
			Vector tmp(lst);
			*this = std::move(tmp);
		}

		// 使用左值拷贝获得新元素
		void push_back(const value_type &val)
		{
			if (INSERT_DEBUG)
				std::cout << "push_back(const value_type &val)" << std::endl;
			_check_alloc();
			m_s_alloc.construct(m_firstFree++, val);
		}
		// 使用右值移动获得新元素
		void push_back(value_type &&val)
		{
			if (INSERT_DEBUG)
				std::cout << "push_back(value_type &&val)" << std::endl;
			_check_alloc();
			m_s_alloc.construct(m_firstFree++, std::move(val));
		}
		void pop_back()
		{
			if (INSERT_DEBUG)
				std::cout << "pop_back()" << std::endl;
			if (empty())
				throw std::runtime_error("pop_back() called on empty Vector");
			m_s_alloc.destroy(m_firstFree--);
		}
		// 使用左值拷贝获得新元素
		iterator insert(iterator pos, const value_type &val)
		{
			if (INSERT_DEBUG)
				std::cout << "insert(iterator pos, const value_type &val)" << std::endl;
			// 防止迭代器失效
			size_type posCnt = pos - begin();
			_check_alloc();
			pos = begin() + posCnt;

			iterator tmpBegin = m_s_alloc.allocate(end() - pos);
			iterator tmpEnd = std::uninitialized_copy(std::make_move_iterator(pos),
				std::make_move_iterator(end()), tmpBegin);
			m_s_alloc.construct(m_firstFree++, value_type());
			*pos++ = val;
			std::uninitialized_copy(std::make_move_iterator(tmpBegin),
				std::make_move_iterator(tmpEnd), pos);
			return pos - 1;
		}
		// 使用右值移动获得新元素
		iterator insert(iterator pos, value_type &&val)
		{
			if (INSERT_DEBUG)
				std::cout << "insert(iterator pos, value_type &&val)" << std::endl;
			// 防止迭代器失效
			size_type posCnt = pos - begin();
			_check_alloc();
			pos = begin() + posCnt;

			iterator tmpBegin = m_s_alloc.allocate(end() - pos);
			iterator tmpEnd = std::uninitialized_copy(std::make_move_iterator(pos),
				std::make_move_iterator(end()), tmpBegin);
			m_s_alloc.construct(m_firstFree++, value_type());
			*pos++ = std::move(val);
			std::uninitialized_copy(std::make_move_iterator(tmpBegin),
				std::make_move_iterator(tmpEnd), pos);
			return pos - 1;
		}
		iterator insert(iterator pos, const size_type cnt, const value_type& val = value_type())
		{
			if (INSERT_DEBUG)
				std::cout << "insert(iterator pos, const size_type cnt, const value_type& val = value_type())" << std::endl;
			// 防止迭代器失效
			size_type posCnt = pos - begin();
			_check_alloc(size() + cnt);
			pos = begin() + posCnt;

			iterator tmpBegin = m_s_alloc.allocate(end() - pos);
			iterator tmpEnd = std::uninitialized_copy(std::make_move_iterator(pos),
				std::make_move_iterator(end()), tmpBegin);
			for (size_type i = 0; i < cnt; ++i)
				m_s_alloc.construct(m_firstFree++, value_type());
			iterator mid = std::uninitialized_fill_n(pos, cnt, val);
			std::uninitialized_copy(std::make_move_iterator(tmpBegin),
				std::make_move_iterator(tmpEnd), mid);
			return pos;
		}
		template<class Iter, class = std::enable_if_t<std::_Is_iterator_v<Iter>>>
		iterator insert(iterator pos, Iter itBegin, Iter itEnd)
		{
			if (INSERT_DEBUG)
				std::cout << "insert(iterator pos, Iter itBegin, Iter itEnd)" << std::endl;
			// 防止迭代器失效
			size_type posCnt = pos - begin();
			_check_alloc(size() + (itEnd - itBegin));
			pos = begin() + posCnt;

			iterator tmpBegin = m_s_alloc.allocate(end() - pos);
			iterator tmpEnd = std::uninitialized_copy(std::make_move_iterator(pos),
				std::make_move_iterator(end()), tmpBegin);
			for (Iter it = itBegin; it != itEnd; ++it)
				m_s_alloc.construct(m_firstFree++, value_type());
			iterator mid = std::uninitialized_copy(itBegin, itEnd, pos);
			std::uninitialized_copy(std::make_move_iterator(tmpBegin),
				std::make_move_iterator(tmpEnd), mid);
			return pos;
		}
		iterator insert(iterator pos, std::initializer_list<T> lst)
		{
			if (INSERT_DEBUG)
				std::cout << "insert(iterator pos, std::initializer_list<T> lst)" << std::endl;
			// 防止迭代器失效
			size_type posCnt = pos - begin();
			_check_alloc(size() + lst.size());
			pos = begin() + posCnt;

			iterator tmpBegin = m_s_alloc.allocate(end() - pos);
			iterator tmpEnd = std::uninitialized_copy(std::make_move_iterator(pos), std::make_move_iterator(end()), tmpBegin);
			for (size_type i = 0; i < lst.size(); ++i)
				m_s_alloc.construct(m_firstFree++, value_type());
			iterator mid = std::uninitialized_copy(lst.begin(), lst.end(), pos);
			std::uninitialized_copy(std::make_move_iterator(tmpBegin), std::make_move_iterator(tmpEnd), mid);
			return pos;
		}
		iterator erase(iterator pos)
		{
			if (INSERT_DEBUG)
				std::cout << "erase(iterator pos)" << std::endl;
			iterator cur = pos;
			while (cur != end())
			{
				*cur = std::move(*(cur + 1));
				++cur;
			}
			m_s_alloc.destroy(--m_firstFree);
			return pos;
		}
		iterator erase(iterator dBegin, iterator dEnd)
		{
			if (INSERT_DEBUG)
				std::cout << "erase(iterator dBegin, iterator dEnd)" << std::endl;
			iterator left = dBegin, right = dEnd;
			while (right != end())
				*left++ = std::move(*right++);
			while (--m_firstFree != left)
				m_s_alloc.destroy(m_firstFree);
			return dBegin;
		}
		void clear()
		{
			if (INSERT_DEBUG)
				std::cout << "clear()" << std::endl;
			while (m_firstFree != m_elements)
				m_s_alloc.destroy(--m_firstFree);
		}

		// 对右值直接进行排序并返回
		Vector sorted() &&
		{
			if (DEBUG)
				std::cout << "sorted() &&" << std::endl;
			std::sort(begin(), end());
			return *this;
		}
		// 对左值的副本进行排序并返回
		Vector sorted() &
		{
			if (DEBUG)
				std::cout << "sorted() &" << std::endl;
			Vector ret(*this); // 拷贝一个副本
			std::sort(ret.begin(), ret.end()); // 对副本进行排序
			return ret; // 返回副本
		}
		void show() const
		{
			if (DEBUG)
				std::cout << "show()" << std::endl;
			for (auto &i : *this)
				std::cout << i << ' ';
			std::cout << std::endl;
		}
		void swap(Vector &v)
		{
			if (DEBUG)
				std::cout << "swap(Vector &v)" << std::endl;
			using std::swap;
			swap(m_elements, v.m_elements);
			swap(m_firstFree, v.m_firstFree);
			swap(m_capacity, v.m_capacity);
		}
		void resize(const size_type n, const value_type val = value_type())
		{
			if (DEBUG)
				std::cout << "resize(const size_type n, const value_type val = value_type())" << std::endl;
			if (size() < n)
			{
				_check_alloc(n);
				while (size() < n)
					m_s_alloc.construct(m_firstFree++, val);
			}
			else
			{
				while (size() != n)
					m_s_alloc.destroy(--m_firstFree);
			}
		}
		void reserve(size_type n)
		{
			if (DEBUG)
				std::cout << "reserve(size_type n)" << std::endl;
			if (capacity() < n)
			{
				std::pair<iterator, iterator> data = _alloc_n_copy(begin(), end(), n);
				m_elements = data.first;
				m_firstFree = data.second;
				m_capacity = m_elements + n;
			}
		}

		Vector* operator&()
		{
			return this;
		}
		const Vector* operator&() const
		{
			return this;
		}
		bool operator==(const Vector &v) const
		{
			if (size() != v.size())
				return false;
			for (int i = 0; i < size(); ++i)
			{
				if (m_elements[i] != v.m_elements[i])
					return false;
			}
			return true;
		}
		bool operator!=(const Vector &v) const
		{
			return (*this == v);
		}
		bool operator<(const Vector &v) const
		{
			for (int i = 0; i < size(); ++i)
			{
				if (i >= v.size())
					break;
				if (m_elements[i] < v.m_elements[i])
					return true;
			}
			return false;
		}
		bool operator<=(const Vector &v) const
		{
			return (*this < v) || (*this == v);
		}
		bool operator>(const Vector &v) const
		{
			return !(*this <= v);
		}
		bool operator>=(const Vector &v) const
		{
			return !(*this < v);
		}
		reference operator[](const size_type n)
		{
			return m_firstFree[n];
		}
		const_reference operator[](const size_type n) const
		{
			return m_firstFree[n];
		}
		reference at(const size_type n)
		{
			if (n >= size())
				throw std::out_of_range("invalid subscript");
			return m_elements[n];
		}
		const_reference at(const size_type n) const
		{
			if (n >= size())
				throw std::out_of_range("invalid subscript");
			return m_elements[n];
		}

		bool empty() const
		{
			return m_firstFree == m_elements;
		}
		size_type size() const
		{
			return m_firstFree - m_elements;
		}
		size_type max_size() const
		{
			return static_cast<size_type>(-1);
		}
		size_type capacity() const
		{
			return m_capacity - m_elements;
		}
		iterator begin()
		{
			return m_elements;
		}
		const_iterator begin() const
		{
			return m_elements;
		}
		const_iterator cbegin()
		{
			return m_elements;
		}
		iterator end()
		{
			return m_firstFree;
		}
		const_iterator end() const
		{
			return m_firstFree;
		}
		const_iterator cend()
		{
			return m_firstFree;
		}
		reference front()
		{
			if (empty())
				throw std::out_of_range("front() called on empty Vector");
			return *m_elements;
		}
		const_reference front() const
		{
			if (empty())
				throw std::out_of_range("front() called on empty Vector");
			return *m_elements;
		}
		reference back()
		{
			if (empty())
				throw std::out_of_range("back() called on empty Vector");
			return *(m_firstFree - 1);
		}
		const_reference back() const
		{
			if (empty())
				throw std::out_of_range("back() called on empty Vector");
			return *(m_firstFree - 1);
		}
		pointer data()
		{
			return m_elements;
		}
		const_pointer data() const
		{
			return m_elements;
		}
	};

	template <class T, class Alloc>
	typename Vector<T, Alloc>::allocator_type Vector<T, Alloc>::m_s_alloc;

	template <class T, class Alloc = std::allocator<T>>
	void swap(Vector<T, Alloc> &v1, Vector<T, Alloc> &v2)
	{
		if (DEBUG)
			std::cout << "swap(Vector<T, Alloc> &v1, Vector<T, Alloc> &v2)" << std::endl;
		v1.swap(v2);
	}
}

#endif /* _VECTOR_H_ */