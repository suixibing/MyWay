#include "Poker.h"

Poker::Poker(char point, char suit)
{
	if (suit == JOKER && (point == 1 || point == 2))
	{
		m_suit = JOKER;
		m_point = point + K;
	}
	else if (point >= A && point <= K && suit >= SPADE && suit <= CLUB)
	{
		m_suit = suit;
		m_point = point;
	}
	else
	{
		m_suit = m_point = BLANK;
	}
}

Poker::~Poker()
{
}

void Poker::SetPoker(char point, char suit)
{
	if (suit == JOKER && (point == 1 || point == 2))
	{
		m_suit = JOKER;
		m_point = point + K;
	}
	else if (point >= A && point <= K && suit >= SPADE && suit <= CLUB)
	{
		m_suit = suit;
		m_point = point;
	}
	else
	{
		m_suit = m_point = BLANK;
	}
}

bool Poker::operator>(const Poker& p)const
{
	return m_point > p.m_point || m_point == p.m_point && p.m_suit > p.m_suit;
}

bool Poker::operator<(const Poker& p)const
{
	return p > *this;
}

bool Poker::operator==(const Poker& p)const
{
	return m_point == p.m_point && m_suit == p.m_suit;
}

std::ostream& operator<<(std::ostream& os, const Poker& p)
{
	const char* str[7] = { "无效", "黑桃", "红桃", "方块", "梅花", "小王", "大王" };

	if (p.m_point == 14 || p.m_point == 15)
	{
		os << str[p.m_suit + p.m_point / 15];
	}
	else
	{
		os << str[p.m_suit] << p.m_point;
	}

	return os;
}