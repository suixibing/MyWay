#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <new>
#include <string>

namespace lb
{
	class Token
	{
		friend std::ostream& operator<<(std::ostream &os, const Token &t);

	private:
		enum { INT, CHR, DBL, STR } tok; // ÅÐ±ðÊ½
		union // ÄäÃûunion
		{
			int ival;
			char cval;
			double dval;
			std::string sval;
		};

	private:
		void copyUnion(const Token &t)
		{
			switch (t.tok)
			{
			case INT: ival = t.ival; break;
			case CHR: cval = t.cval; break;
			case DBL: dval = t.dval; break;
			case STR: new(&sval) std::string(t.sval); break;
			}
		}
		void moveUnion(Token &&t)
		{
			switch (t.tok)
			{
			case INT: ival = std::move(t.ival); break;
			case CHR: cval = std::move(t.cval); break;
			case DBL: dval = std::move(t.dval); break;
			case STR: new(&sval) std::string(std::move(t.sval)); break;
			}
		}

	public:
		Token(int i = 0) : tok(INT), ival(i) { }
		Token(char ch) : tok(CHR), cval(ch) { }
		Token(double d) : tok(DBL), dval(d) { }
		Token(const std::string &str) : tok(STR)
		{
			new(&sval) std::string(str);
		}
		Token(std::string &&str) : tok(STR)
		{
			new(&sval) std::string(std::move(str));
		}
		Token(const Token &t) : tok(t.tok)
		{
			copyUnion(t);
		}
		Token(Token &&t) : tok(t.tok)
		{
			moveUnion(std::move(t));
		}
		~Token()
		{
			if (tok == STR)
				sval.~basic_string();
		}
		Token& operator=(const Token &t)
		{
			if (tok == STR && t.tok == STR)
				sval = t.sval;
			else if (tok == STR)
				sval.~basic_string();
			copyUnion(t);
			tok = t.tok;
			return *this;
		}
		Token& operator=(Token &&t)
		{
			if (tok == STR && t.tok == STR)
				sval = std::move(t.sval);
			else if (tok == STR)
				sval.~basic_string();
			moveUnion(std::move(t));
			tok = t.tok;
			return *this;
		}
		Token& operator=(int i)
		{
			if (tok == STR)
				sval.~basic_string();
			tok = INT;
			ival = i;
			return *this;
		}
		Token& operator=(char ch)
		{
			if (tok == STR)
				sval.~basic_string();
			tok = CHR;
			cval = ch;
			return *this;
		}
		Token& operator=(double d)
		{
			if (tok == STR)
				sval.~basic_string();
			tok = DBL;
			dval = d;
			return *this;
		}
		Token& operator=(const std::string &str)
		{
			if (tok == STR)
				sval = str;
			else
				new(&sval) std::string(str);
			tok = STR;
			return *this;
		}
		std::string tokType() const
		{
			switch (tok)
			{
			case INT: return "INT"; break;
			case CHR: return "CHR"; break;
			case DBL: return "DBL"; break;
			case STR: return "STR"; break;
			}
		}
		std::ostream& showVal(std::ostream &os = std::cout) const
		{
			switch (tok)
			{
			case INT: os << ival; break;
			case CHR: os << cval; break;
			case DBL: os << dval; break;
			case STR: os << sval; break;
			}
			return os;
		}
	};

	std::ostream& operator<<(std::ostream &os, const Token &t)
	{
		os << t.tokType() << ": ";
		return t.showVal(os);
	}
}

#endif /* _TOKEN_H_ */