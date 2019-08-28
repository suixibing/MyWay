#include<ctime>
#include<cstdlib>
#include"Test.h"

Time::Time()
{
	_day = 0;
	_hour = rand() % 360;
	_minite = rand() % 3600;
	_second = rand() % 143145;
}

void Time::TimeAdjust()
{
	if (_second > 60)
	{
		_minite += _second / 60;
		_second = _second % 60;
	}
	if (_minite > 60)
	{
		_hour += _minite / 60;
		_minite = _minite % 60;
	}
	if (_hour > 24)
	{
		_day += _hour / 24;
		_hour = _hour % 24;
	}
}

int Time::Seconds()
{
	return _day * 3600 * 24 + _hour * 3600 + _minite * 60 + _second;
}

ostream& operator<<(ostream& os, Time& t)
{
	os << "day: " << t._day << " hour: " << t._hour << " minite: " << t._minite << " second: " << t._second << endl;

	return os;
}