#pragma once
#include <iostream>

namespace lb
{
	template <class T>
	class Array_data
	{
	private:
		int m_cnt;
		int m_size;
		T *m_data;
	private:
		template<class T> friend class Array;
		template<class T> friend class ArrayPtrToConst;

		Array_data(int size = 0)
			: m_cnt(1), m_size(size)
		{
			if (size < 0)
				throw "Array create error";
			m_data = new T[size];
		}
		Array_data(const Array_data<T> & array_data)
		{
			throw "array can't copy create";
		}
		Array_data<T>& operator=(const Array_data<T> & array_data)
		{
			throw "array can't =";
		}
		~Array_data()
		{
			delete[] m_data;
		}
		const T& operator[](int sub) const
		{
			if (sub >= m_size)
				throw "Array subscript out of range";
			return m_data[sub];
		}
		T& operator[](int sub)
		{
			if (sub >= m_size)
				throw "Array subscript out of range";
			return m_data[sub];
		}
		void resize(int size)
		{
			if (size <= 0)
				throw "new size error";
			else if (size == m_size)
				return;
			T *tmp = m_data;
			m_data = new T[size];
			copy(tmp, (size > m_size ? m_size : size));
			delete[] tmp;
			m_size = size;
		}
		void copy(T * data, int count)
		{
			for (int i = 0; i < count; ++i)
				m_data[i] = data[i];
		}
		void grow(int size)
		{
			if (size < 0)
				throw "reverse error";
			if (m_size == 0)
				m_size = 1;
			while (size >= m_size)
				m_size = 1.5 * m_size + 1;
			resize(m_size);
		}
		void clone(const Array_data<T> & arrayData, int size)
		{
			if (size < 0)
				throw "clone error";
			if (--m_cnt == 0)
				delete[] m_data;
			m_data = new T[size];
			copy(arrayData.m_data, size);
		}
	};

	template <class T>
	class Array
	{
	private:
		Array_data<T> *m_arrayData;
	public:
		template <class T> friend class ArrayPtrToConst;
		template <class T> friend ArrayPtr<T> operator+(Array<T> & array, int n);
		template <class T> friend ArrayPtr<T> operator+<T>(int n, Array<T> & array);
		template <class T> friend ArrayPtrToConst<T> operator+<T>(const Array<T> & array, int n);
		template <class T> friend ArrayPtrToConst<T> operator+<T>(int n, const Array<T> & array);

		Array() : m_arrayData(nullptr) { }
		Array(int size) : m_arrayData(new Array_data<T>(size)) { }
		Array(const Array<T> & array)
			: m_arrayData(new Array_data<T>(array.m_arrayData->m_size))
		{
			m_arrayData->copy(array.m_arrayData->m_data, array.m_arrayData->m_size);
		}
		~Array()
		{
			if (m_arrayData && --(m_arrayData->m_cnt) == 0)
				delete m_arrayData;
		}

		Array<T>& operator=(const Array<T> & array)
		{
			if (this != &array)
				m_arrayData->clone(*(array.m_arrayData), array.m_arrayData->m_size);
			return *this;
		}
		const T& operator[](int sub) const
		{
			return (*m_arrayData)[sub];
		}
		T& operator[](int sub)
		{
			return (*m_arrayData)[sub];
		}
		void resize(int size)
		{
			m_arrayData->resize(size);
		}
		void reserve(int size)
		{
			if (size >= m_arrayData->m_size)
				m_arrayData->grow(size);
		}
	};

	template <class T>
	class ArrayPtrToConst
	{
	protected:
		int m_sub;
		Array_data<T> *m_arrayData;
	protected:
		int& getSub()
		{
			return m_sub;
		}
		Array_data<T>* getArrayData()
		{
			return m_arrayData;
		}
	public:
		template<class T> friend ArrayPtrToConst<T> operator+(const ArrayPtrToConst<T> & ptr, int n);
		template<class T> friend ArrayPtrToConst<T> operator+(int n, const ArrayPtrToConst<T> & ptr);
		template<class T> friend int operator-(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2);
		template<class T> friend bool operator==(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2);
		template<class T> friend bool operator!=(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2);
		template<class T> friend bool operator<(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2);
		template<class T> friend bool operator>(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2);
		template<class T> friend bool operator<=(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2);
		template<class T> friend bool operator>=(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2);

		ArrayPtrToConst() : m_sub(0), m_arrayData(nullptr) { }
		ArrayPtrToConst(const Array<T> & array, int sub = 0) : m_sub(sub), m_arrayData(array.m_arrayData)
		{
			if (sub < 0)
				throw "sub out of range";
			++(m_arrayData->m_cnt);
		}
		ArrayPtrToConst(const ArrayPtrToConst<T> & ptr)
			: m_sub(ptr.m_sub), m_arrayData(ptr.m_arrayData)
		{
			++(m_arrayData->m_cnt);
		}
		~ArrayPtrToConst()
		{
			if (m_arrayData && --(m_arrayData->m_cnt) == 0)
				delete m_arrayData;
		}
		ArrayPtrToConst<T>& operator=(const ArrayPtrToConst<T> & ptr)
		{
			if (ptr.m_arrayData)
				++(ptr.m_arrayData->m_cnt);
			if (m_arrayData && --(m_arrayData->m_cnt) == 0)
				delete m_arrayData;
			m_arrayData = ptr.m_arrayData;
			m_sub = ptr.m_sub;
			return *this;
		}
		T operator*() const
		{
			if (m_arrayData == nullptr)
				throw "* of unbound Pointer";
			return (*m_arrayData)[m_sub];
		}
		ArrayPtrToConst<T>& operator++()
		{
			++m_sub;
			return *this;
		}
		ArrayPtrToConst<T>& operator--()
		{
			--m_sub;
			return *this;
		}
		ArrayPtrToConst<T>& operator++(int)
		{
			ArrayPtrToConst<T> ret = *this;
			++m_sub;
			return ret;
		}
		ArrayPtrToConst<T>& operator--(int)
		{
			ArrayPtrToConst<T> ret = *this;
			--m_sub;
			return ret;
		}
		ArrayPtrToConst<T>& operator+=(int n)
		{
			m_sub += n;
			return *this;
		}
		ArrayPtrToConst<T>& operator-=(int n)
		{
			m_sub -= n;
			return *this;
		}
		bool isPoint(const Array<T> & array)
		{
			return m_arrayData == array.m_arrayData;
		}
	};
	template <class T>
	class ArrayPtr : public ArrayPtrToConst<T>
	{
	public:
		friend ArrayPtr<T> operator+<T>(const ArrayPtr<T> & ptr, int n);
		friend ArrayPtr<T> operator+<T>(int n, const ArrayPtr<T> & ptr);

		ArrayPtr() : ArrayPtrToConst() { }
		ArrayPtr(const Array<T> & array, int sub = 0)
			: ArrayPtrToConst(array, sub) { }
		ArrayPtr(const ArrayPtr<T> & ptr)
			: ArrayPtrToConst(ptr) { }
		ArrayPtr<T>& operator=(const ArrayPtr<T> & ptr)
		{
			if (ptr.m_arrayData)
				++(ptr.m_arrayData->m_cnt);
			if (m_arrayData && --(m_arrayData->m_cnt) == 0)
				delete m_arrayData;
			ArrayPtrToConst<T>::m_sub;
			m_arrayData = ptr.m_arrayData;
			m_sub = ptr.m_sub;
			return *this;
		}
		T& operator*() const
		{
			if (m_arrayData == nullptr)
				throw "* of unbound Pointer";
			return (*m_arrayData)[m_sub];
		}
		ArrayPtr<T>& operator++()
		{
			++m_sub;
			return *this;
		}
		ArrayPtr<T>& operator--()
		{
			--m_sub;
			return *this;
		}
		ArrayPtr<T>& operator++(int)
		{
			ArrayPoint ret(*this);
			++m_sub;
			return ret;
		}
		ArrayPtr<T>& operator--(int)
		{
			ArrayPoint ret(*this);
			--m_sub;
			return ret;
		}
		ArrayPtr<T>& operator+=(int n)
		{
			m_sub += n;
			return *this;
		}
		ArrayPtr<T>& operator-=(int n)
		{
			m_sub -= n;
			return *this;
		}
	};

	template <class T>
	ArrayPtr<T> operator+(Array<T> & array, int n)
	{
		return ArrayPtr<T>(array, n);
	}
	template <class T>
	ArrayPtr<T> operator+(int n, Array<T> & array)
	{
		return ArrayPtr<T>(array, n);
	}
	template <class T>
	ArrayPtrToConst<T> operator+(const Array<T> & array, int n)
	{
		return ArrayPtrToConst<T>(array, n);
	}
	template <class T>
	ArrayPtrToConst<T> operator+(int n, const Array<T> & array)
	{
		return ArrayPtrToConst<T>(array, n);
	}

	template <class T>
	int operator-(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2)
	{
		return ptr1.m_sub - ptr2.m_sub;
	}
	template <class T>
	ArrayPtrToConst<T> operator+(const ArrayPtrToConst<T> & ptr, int n)
	{
		ArrayPtrToConst<T> ret(ptr);
		return ret += n;
	}
	template <class T>
	ArrayPtrToConst<T> operator+(int n, const ArrayPtrToConst<T> & ptr)
	{
		return ptr + n;
	}
	template <class T>
	bool operator==(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2)
	{
		if (ptr1.m_arrayData != ptr2.m_arrayData)
			return false;
		return ptr1.m_sub == ptr2.m_sub;
	}
	template <class T>
	bool operator!=(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2)
	{
		if (ptr1.m_arrayData != ptr2.m_arrayData)
			return true;
		return ptr1.m_sub != ptr2.m_sub;
	}
	template <class T>
	bool operator<(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2)
	{
		if (ptr1.m_arrayData != ptr2.m_arrayData)
			throw "< on different Arrays";
		return ptr1.m_sub < ptr2.m_sub;
	}
	template <class T>
	bool operator>(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2)
	{
		if (ptr1.m_arrayData != ptr2.m_arrayData)
			throw "> on different Arrays";
		return ptr1.m_sub > ptr2.m_sub;
	}
	template <class T>
	bool operator<=(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2)
	{
		if (ptr1.m_arrayData != ptr2.m_arrayData)
			throw "<= on different Arrays";
		return ptr1.m_sub <= ptr2.m_sub;
	}
	template <class T>
	bool operator>=(const ArrayPtrToConst<T> & ptr1, const ArrayPtrToConst<T> & ptr2)
	{
		if (ptr1.m_arrayData != ptr2.m_arrayData)
			throw ">= on different Arrays";
		return ptr1.m_sub >= ptr2.m_sub;
	}
	template <class T>
	ArrayPtr<T> operator+(const ArrayPtr<T> & ptr, int n)
	{
		ArrayPtr<T> ret(ptr);
		return ret += n;
	}
	template <class T>
	ArrayPtr<T> operator+(int n, const ArrayPtr<T> & ptr)
	{
		return ptr + n;
	}
}