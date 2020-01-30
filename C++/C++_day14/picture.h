#pragma once
#include "MyClass.h"
#include <iostream>

namespace lb
{
	using std::ostream;
	using std::endl;
	class Picture;

	class Pic_Node
	{
	protected:
		friend class Picture;

		static int max(int x, int y) { return x > y ? x : y; }
		static void pad(ostream & os, int x, int y) { while (x++ < y) cout << ' '; }
		virtual ~Pic_Node() { }
		virtual int height() const = 0;
		virtual int width() const = 0;
		virtual void display(ostream & os, int row, int width) const = 0;
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
		int height() const;
		int width() const;
		void display(ostream & os, int row, int width) const;
	};
	class Frame_Pic : public Pic_Node
	{
	private:
		Picture m_p;
	private:
		friend Picture frame(const Picture & p);

		Frame_Pic(const Picture & p) : m_p(p) { }
		int height() const;
		int width() const;
		void display(ostream & os, int row, int width) const;
	};
	class VCat_Pic : public Pic_Node
	{
	private:
		Picture m_top;
		Picture m_bottom;
	private:
		friend Picture operator&(const Picture & top, const Picture & bottom);

		VCat_Pic(const Picture & top, const Picture & bottom) : m_top(top), m_bottom(bottom) { }
		int height() const;
		int width() const;
		void display(ostream & os, int row, int width) const;
	};
	class HCat_Pic : public Pic_Node
	{
	private:
		Picture m_left;
		Picture m_right;
	private:
		friend Picture operator|(const Picture & left, const Picture & right);

		HCat_Pic(const Picture & left, const Picture & right) : m_left(left), m_right(right) { }
		int height() const;
		int width() const;
		void display(ostream & os, int, int) const;
	};
	class Picture
	{
	private:
		UseCount m_uc;
		Pic_Node *m_pn;
	private:
		friend Picture frame(const Picture & p);
		friend Picture operator&(const Picture & top, const Picture & bottom);
		friend Picture operator|(const Picture & left, const Picture & right);
		friend ostream& operator<<(ostream & os, const Picture & pic);

		Picture(Pic_Node * pn) : m_pn(pn) { }
		int height() const { return m_pn->height(); }
		int width() const { return m_pn->width(); }
		void display(ostream & os, int row, int col) const { return m_pn->display(); }
	public:
		Picture() : m_pn(nullptr) { }
		Picture(const Picture & p) : m_pn(p.m_pn), m_uc(p.m_uc) { }
		Picture(const char * const *data, int size);
		~Picture();
		Picture& operator=(const Picture & p);
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
	int String_Pic::height() const
	{
		return m_size;
	}
	int String_Pic::width() const
	{
		int res = strlen(m_data[0]);
		for (int i = 1; i < m_size; ++i)
			res = max(res, strlen(m_data[i]));
		return res;
	}
	void String_Pic::display(ostream & os, int row, int width) const
	{
		int start = 0;
		if (row >= 0 && row < m_size)
		{
			os << m_data[row];
			start = strlen(m_data[row]);
		}
		pad(os, start, width);
	}
	int Frame_Pic::height() const
	{
		
	}
	int Frame_Pic::width() const
	{

	}
	void Frame_Pic::display(ostream & os, int row, int width) const
	{

	}
	int VCat_Pic::height() const
	{
		
	}
	int VCat_Pic::width() const
	{

	}
	void VCat_Pic::display(ostream & os, int row, int width) const
	{

	}
	int HCat_Pic::height() const
	{

	}
	int HCat_Pic::width() const
	{

	}
	void HCat_Pic::display(ostream & os, int row, int width) const
	{

	}
	Picture frame(const Picture & p)
	{
		return (new Frame_Pic(p));
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
		int ht = pic.height();
		for (int i = 0; i < ht; ++i)
		{
			pic.display(os, i, i);
			cout << endl;
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