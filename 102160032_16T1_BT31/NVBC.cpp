#include "NVBC.h"


NVBC::NVBC()
{
}

NVBC::NVBC(string id, string name, Date d, bool sex, double coefficient) : NhanVien(id, name, d, sex, coefficient)
{
}

double seniority(Date d) {
	time_t current_time = time(NULL);
	tm local_time;
	localtime_s(&local_time, &current_time);
	double ser = 0.0;
	int year = local_time.tm_year + 1900;
	int month = local_time.tm_mon + 1;
	int day = local_time.tm_mday;
	int sY = d.getYear();
	int sM = d.getMonth();
	int sD = d.getDay();
	if (month > sM  && year - sY >= 5|| day >= sD && month == sM && year - sY >= 5) {
		return (year - sY) * 1.0 / 100;
	}
	return ser;
}

double NVBC::getSalary()
{
	double ser = seniority(startTime);
	return (salary * 1390000) * (1 + ser);
}



NVBC::~NVBC()
{
}
