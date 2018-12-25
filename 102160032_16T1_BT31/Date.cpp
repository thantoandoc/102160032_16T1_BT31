#include "Date.h"


Date::Date(int d, int m, int y)
{
	this->day = d;
	this->month = m;
	this->year = y;
}

Date::Date(const Date & d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}

Date::~Date()
{
}

istream & operator>>(istream & in, Date & d)
{
	cout << "Ngay : "; in >> d.day;
	cout << "Thang : "; in >> d.month;
	cout << "Nam: "; in >> d.year;
	return in;
}
