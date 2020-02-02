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
		friend class Array<T>;
		friend class ArrayPointer<T>;

		Array_data(int size = 0)
			: m_cnt(1), m_size(size)
		{
			if (size < 0)
				throw "Array create error";
			m_data = new T[size];
		}
		Array_data(const Array_data & array_data)
		{
			throw "array can't copy create";
		}
		Array_data& operator=(const Array_data & array_data)
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
	};

	template <class T>
	class Array
	{
	private:
		Array_data<T> *m_data;
	private:
		friend class ArrayPointer<T>;

		Array(const Array<T> & a) { }
		Array& operator=(const Array<T> & a) { }
	public:
		Array() : m_data(nullptr) { }
		Array(int size) : m_data(new Array_data<T>(size)) { }
		~Array()
		{
			if (--(m_data->m_cnt) == 0)
				delete m_data->m_data;
		}

		const T& operator[](int sub) const
		{
			return m_data[sub];
		}
		T& operator[](int sub)
		{
			return m_data[sub];
		}
	};

	template <class T>
	class ArrayPointer
	{
	private:
		int m_sub;
		Array_data<T> *m_arrayData;
	public:
		ArrayPointer() : m_sub(0), m_array(nullptr) { }
		ArrayPointer(Array<T> array, int sub = 0) : m_sub(sub), m_array(array.m_data)
		{
			if (sub < 0)
				throw "sub out of range";
			++(m_arrayData->m_cnt);
		}
		ArrayPointer(const ArrayPointer & ap)
			: m_sub(ap.m_sub), m_arrayData(ap.m_arrayData)
		{
			++(m_arrayData->m_cnt);
		}
		ArrayPointer& operator=(const ArrayPointer & ap)
		{
			if (ap.m_arrayData)
				++(ap.m_arrayData->m_cnt);
			if (m_arrayData && --(m_arrayData->m_cnt) == 0)
				delete m_arrayData;
			m_arrayData = ap.m_arrayData;
			m_sub = ap.m_sub;
			return *this;
		}
		T operator*() const
		{
			if (m_arrayData == nullptr)
				throw "* of unbound Pointer";
			return m_array[m_sub];
		}
	};
}