#include<ctime>
#include<cstdlib>
#include"Test.h"

Time::Time()
{
	m_day = 0;
	m_hour = rand() % 360;
	m_minite = rand() % 3600;
	m_second = rand() % 143145;
}

void Time::TimeAdjust()
{
	if (m_second > 60)
	{
		m_minite += m_second / 60;
		m_second = m_second % 60;
	}
	if (m_minite > 60)
	{
		m_hour += m_minite / 60;
		m_minite = m_minite % 60;
	}
	if (m_hour > 24)
	{
		m_day += m_hour / 24;
		m_hour = m_hour % 24;
	}
}

int Time::Seconds()
{
	return m_day * 3600 * 24 + m_hour * 3600 + m_minite * 60 + m_second;
}

ostream& operator<<(ostream& os, Time& t)
{
	os << "day: " << t.m_day << " hour: " << t.m_hour << " minite: " << t.m_minite << " second: " << t.m_second << endl;

	return os;
}