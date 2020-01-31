#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "MyClass.h"
#include <iostream>

namespace lb
{
	using std::ostream;
	using std::endl;

	class Pic_Node
	{
	protected:
		friend class Picture;
		friend Picture reframe(const Picture & p, char corner, char sideborder, char topborder);

		static int max(int x, int y) { return x > y ? x : y; }
		static void pad(ostream & os, int x, int y) { while (x++ < y) os << ' '; }
		virtual ~Pic_Node() { }
		virtual int _height() const = 0;
		virtual int _width() const = 0;
		virtual void _display(ostream & os, int row, int width) const = 0;
		virtual Picture _reframe(char corner, char sideborder, char topborder) = 0;
	};
	class Picture
	{
	private:
		UseCount m_uc;
		Pic_Node *m_pn;
	private:
		friend class String_Pic;
		friend class Frame_Pic;
		friend class VCat_Pic;
		friend class HCat_Pic;
		friend Picture frame(const Picture & p);
		friend Picture reframe(const Picture & p, char corner, char sideborder, char topborder);
		friend Picture operator&(const Picture & top, const Picture & bottom);
		friend Picture operator|(const Picture & left, const Picture & right);
		friend ostream& operator<<(ostream & os, const Picture & pic);

		Picture(Pic_Node * pn) : m_pn(pn) { }
		int height() const { return m_pn->_height(); }
		int width() const { return m_pn->_width(); }
		void display(ostream & os, int row, int width) const { return m_pn->_display(os, row, width); }
	public:
		Picture() : m_pn(nullptr) { }
		Picture(const Picture & p) : m_pn(p.m_pn), m_uc(p.m_uc) { }
		Picture(const char * const *data, int size);
		~Picture();
		Picture& operator=(const Picture & p);
	};
	class String_Pic : public Pic_Node
	{
	private:
		char **m_data;
		int m_size;
	private:
		friend class Picture;

		String_Pic(const char* const *data, int size);
		~String_Pic();
		int _height() const;
		int _width() const;
		void _display(ostream & os, int row, int width) const;
		Picture _reframe(char corner, char sideborder, char topborder);
	};
	class Frame_Pic : public Pic_Node
	{
	private:
		Picture m_p;
		char m_corner;
		char m_sideborder;
		char m_topborder;
	private:
		friend Picture frame(const Picture & p);

		Frame_Pic(const Picture & p, char corner = '+', char sideborder = '|', char topborder = '-');
		int _height() const;
		int _width() const;
		void _display(ostream & os, int row, int width) const;
		Picture _reframe(char corner, char sideborder, char topborder);
	};
	class VCat_Pic : public Pic_Node
	{
	private:
		Picture m_top;
		Picture m_bottom;
	private:
		friend Picture operator&(const Picture & top, const Picture & bottom);

		VCat_Pic(const Picture & top, const Picture & bottom);
		int _height() const;
		int _width() const;
		void _display(ostream & os, int row, int width) const;
		Picture _reframe(char corner, char sideborder, char topborder);
	};
	class HCat_Pic : public Pic_Node
	{
	private:
		Picture m_left;
		Picture m_right;
	private:
		friend Picture operator|(const Picture & left, const Picture & right);

		HCat_Pic(const Picture & left, const Picture & right);
		int _height() const;
		int _width() const;
		void _display(ostream & os, int, int) const;
		Picture _reframe(char corner, char sideborder, char topborder);
	};

	String_Pic::String_Pic(const char* const *data, int size)
		: m_data(new char*[size]), m_size(size)
	{
		for (int i = 0; i < m_size; ++i)
		{
			m_data[i] = new char[strlen(data[i]) + 1];
			strcpy(m_data[i], data[i]);
		}
	}
	String_Pic::~String_Pic()
	{
		for (int i = 0; i < m_size; ++i)
			delete m_data[i];
		delete[] m_data;
	}
	int String_Pic::_height() const
	{
		return m_size;
	}
	int String_Pic::_width() const
	{
		int res = strlen(m_data[0]);
		for (int i = 1; i < m_size; ++i)
			res = max(res, strlen(m_data[i]));
		return res;
	}
	void String_Pic::_display(ostream & os, int row, int width) const
	{
		int start = 0;
		if (row >= 0 && row < m_size)
		{
			os << m_data[row];
			start = strlen(m_data[row]);
		}
		pad(os, start, width);
	}
	Picture String_Pic::_reframe(char corner, char sideborder, char topborder)
	{
		return this;
	}

	Frame_Pic::Frame_Pic(const Picture & p, char corner, char sideborder, char topborder) 
		: m_p(p), m_corner(corner), m_sideborder(sideborder), m_topborder(topborder) { }
	int Frame_Pic::_height() const
	{
		return m_p.height() + 2;
	}
	int Frame_Pic::_width() const
	{
		return m_p.width() + 2;
	}
	void Frame_Pic::_display(ostream & os, int row, int width) const
	{
		if (row < 0 || row >= _height())
			pad(os, 0, width);
		else
		{
			if (row == 0 || row == _height() - 1)
			{
				os << m_corner;
				for (int i = m_p.width(); i > 0; --i)
					os << m_topborder;
				os << m_corner;
			}
			else
			{
				os << m_sideborder;
				m_p.display(os, row - 1, m_p.width());
				os << m_sideborder;
			}
			pad(os, _width(), width);
		}
	}
	Picture Frame_Pic::_reframe(char corner, char sideborder, char topborder)
	{
		return (new Frame_Pic(reframe(m_p, corner, sideborder, topborder), corner, sideborder, topborder));
	}

	VCat_Pic::VCat_Pic(const Picture & top, const Picture & bottom) : m_top(top), m_bottom(bottom) { }
	int VCat_Pic::_height() const
	{
		return m_top.height() + m_bottom.height();
	}
	int VCat_Pic::_width() const
	{
		return max(m_top.width(), m_bottom.width());
	}
	void VCat_Pic::_display(ostream & os, int row, int width) const
	{
		if (row < 0 || row >= _height())
			pad(os, 0, width);
		else if (row < m_top.height())
			m_top.display(os, row, width);
		else
			m_bottom.display(os, row - m_top.height(), width);
	}
	Picture VCat_Pic::_reframe(char corner, char sideborder, char topborder)
	{
		return (new VCat_Pic(reframe(m_top, corner, sideborder, topborder)
				, reframe(m_bottom, corner, sideborder, topborder)));
	}

	HCat_Pic::HCat_Pic(const Picture & left, const Picture & right) : m_left(left), m_right(right) { }
	int HCat_Pic::_height() const
	{
		return max(m_left.height(), m_right.height());
	}
	int HCat_Pic::_width() const
	{
		return m_left.width() + m_right.width();
	}
	void HCat_Pic::_display(ostream & os, int row, int width) const
	{
		m_left.display(os, row, m_left.width());
		m_right.display(os, row, m_right.width());
		pad(os, _width(), width);
	}
	Picture HCat_Pic::_reframe(char corner, char sideborder, char topborder)
	{
		return (new HCat_Pic(reframe(m_left, corner, sideborder, topborder)
			, reframe(m_right, corner, sideborder, topborder)));
	}

	Picture frame(const Picture & p)
	{
		return (new Frame_Pic(p));
	}
	Picture reframe(const Picture & p, char corner, char sideborder, char topborder)
	{
		return p.m_pn->_reframe(corner, sideborder, topborder);
	}
	Picture operator&(const Picture & top, const Picture & bottom)
	{
		return (new VCat_Pic(top, bottom));
	}
	Picture operator|(const Picture & left, const Picture & right)
	{
		return (new HCat_Pic(left, right));
	}
	Picture::Picture(const char * const *data, int size)
	{
		m_pn = new String_Pic(data, size);
	}
	Picture::~Picture()
	{
		if (m_uc.only())
			delete m_pn;
	}
	Picture& Picture::operator=(const Picture & p)
	{
		if (m_uc.reattach(p.m_uc))
			delete m_pn;
		m_pn = p.m_pn;
		return *this;
	}
	ostream& operator<<(ostream & os, const Picture & pic)
	{
		int ht = pic.height(), wd = pic.width();
		for (int i = 0; i < ht; ++i)
		{
			pic.display(os, i, wd);
			os << endl;
		}
		return os;
	}
}

namespace lb_old
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