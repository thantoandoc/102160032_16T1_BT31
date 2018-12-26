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

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

Date::~Date()
{
}

bool check(Date & date) {
	time_t current_time = time(NULL);
	tm local_time;
	localtime_s(&local_time, &current_time);
	
	int year = local_time.tm_year + 1900;
	
	int d = date.getDay();
	int m = date.getMonth();
	int y = date.getYear();

	if (d < 0 || y > year) return false;
	if (d <= 30 && (m == 4 || m == 6 || m == 9 || m == 11)) return true;
	if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d <= 31) return true;
	if (m == 2) {
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		{
			if (d <= 29) return true;
		}
		else if (d <= 28) return true;

	}
	return false;
}

istream & operator>>(istream & in, Date & d)
{
	do {
		cout << "Ngay : "; in >> d.day;
		cout << "Thang : "; in >> d.month;
		cout << "Nam: "; in >> d.year;
		if (check(d)) break;
		cout << "Nhap khong dung ngay thang nam. Moi nhap lai:" << endl;
	} while (true);
	return in;
}

ostream & operator<<(ostream & o, Date & d)
{
	o << setw(2)<< d.day << "/" << setw(2) << d.month << "/" << setw(4) << d.year;
	return o;
}
