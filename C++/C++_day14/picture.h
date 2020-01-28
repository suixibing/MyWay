#pragma once

#include <iostream>
namespace lb
{
	using std::ostream;
	using std::endl;
	class Picture
	{
	private:
		int m_height;
		int m_width;
		char *m_data;
	private:
		char& position(int row, int col) { return m_data[row * m_width + col]; }
		char position(int row, int col) const { return m_data[row * m_width + col]; }
		static int max(int x, int y) { return x > y ? x : y; }
		void init(int height, int width);
		void clear();
		void clear(int x1, int y1, int x2, int y2);
		void copyblock(int x, int y, const Picture & p);
	public:
		Picture() : m_height(0), m_width(0), m_data(nullptr) { }
		Picture(const Picture & p);
		Picture(const char* const* data, int cnt);
		~Picture() { delete[] m_data; }
		Picture& operator=(const Picture & p);
		friend Picture frame(Picture & p);
		friend Picture operator|(Picture & p, Picture & q);
		friend Picture operator&(Picture & p, Picture & q);
		friend ostream& operator<<(ostream & os, const Picture & p);
	};
	Picture::Picture(const Picture & p) 
		: m_height(p.m_height), m_width(p.m_width), m_data(new char[m_height * m_width])
	{
		copyblock(0, 0, p);
	}
	Picture::Picture(const char* const* data, int height)
	{
		int i, j, len, width = 0;

		for (i = 0; i < height; ++i)
			width = max(width, strlen(data[i]));
		init(height, width);
		for (i = 0; i < height; ++i)
		{
			const char *p = data[i];
			len = strlen(p);
			for (j = 0; j < len; ++j)
				position(i, j) = p[j];
		}
	}
	Picture& Picture::operator=(const Picture & p)
	{
		if (&p != this)
		{
			delete[] m_data;
			init(m_height, m_width);
			copyblock(0, 0, p);
		}
		return *this;
	}
	void Picture::init(int height, int width)
	{
		m_height = height;
		m_width = width;
		m_data = new char[height * width];
		clear();
	}
	void Picture::clear()
	{
		memset(m_data, ' ', m_height * m_width);
	}
	void Picture::clear(int x1, int y1, int x2, int y2)
	{
		int i, j;
		for (i = x1; i <= x2; ++i)
		{
			for (j = y1; j <= y2; ++j)
				position(i, j) = ' ';
		}
	}
	void Picture::copyblock(int x, int y, const Picture & p)
	{
		int i, j;
		for (i = 0; i < p.m_height; ++i)
		{
			for (j = 0; j < p.m_width; ++j)
				position(i + x, j + y) = p.position(i, j);
		}
	}
	Picture frame(Picture & p)
	{
		int i, j;
		Picture ret;

		ret.init(p.m_height + 2, p.m_width + 2);
		ret.position(0, 0) = '+';
		ret.position(0, ret.m_width - 1) = '+';
		ret.position(ret.m_height - 1, 0) = '+';
		ret.position(ret.m_height - 1, ret.m_width - 1) = '+';
		for (i = 1; i < ret.m_height - 1; ++i)
		{
			ret.position(i, 0) = '|';
			ret.position(i, ret.m_width - 1) = '|';
		}
		for (j = 1; j < ret.m_width - 1; ++j)
		{
			ret.position(0, j) = '-';
			ret.position(ret.m_height - 1, j) = '-';
		}
		ret.copyblock(1, 1, p);

		return ret;
	}
	Picture operator|(Picture & p, Picture & q)
	{
		Picture ret;

		ret.init(Picture::max(p.m_height, q.m_height), p.m_width + q.m_width);
		ret.clear();
		ret.copyblock(0, 0, p);
		ret.copyblock(0, p.m_width, q);

		return ret;
	}
	Picture operator&(Picture & p, Picture & q)
	{
		Picture ret;

		ret.init(p.m_height + q.m_height, Picture::max(p.m_width, q.m_width));
		ret.clear();
		ret.copyblock(0, 0, p);
		ret.copyblock(p.m_height, 0, q);

		return ret;
	}
	ostream& operator<<(ostream & os, const Picture & p)
	{
		int i, j;
		for (i = 0; i < p.m_height; ++i)
		{
			for (j = 0; j < p.m_width; ++j)
				os << p.position(i, j);
			os << endl;
		}
		return os;
	}
}