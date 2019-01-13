#include "NVHD.h"

NVHD::NVHD()
{
}

NVHD::NVHD(string id, string name, Date d, bool sex, double salary) : NhanVien(id, name, d, sex, salary)
{
	this->salaryDay = salary;
}

bool leapYear(int year) {
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) return true;
	return false;
}

int countDay() {
	time_t current_time = time(NULL);
	tm local_time;
	localtime_s(&local_time, &current_time);
	int current_month = local_time.tm_mon;
	int current_year = local_time.tm_year;
	tm time_in = { 0, 0, 0, 1, current_month, current_year };
	time_t time_temp = mktime(&time_in);
	localtime_s(&local_time, &time_temp);
	int count = 20;
	int days = 0;
	int idx = local_time.tm_wday; // 0- Sun, 1_Mon, 2_Tue,/...6.Sat
	switch (current_month + 1) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
			days = 31 - 28;
			break;
		}
		case 4: case 6: case 9: case 11: {
			days = 30 - 28;
			break;
		}
		case 2: {
			days = 28 - 28 + leapYear(current_year);
			break;
		}
	}
	for (int i = 0; i < days; i++) {
		if ((idx + i) % 7 != 6 && (idx + i) % 7 != 0) {
			count += 1;
		}
	}
	return count;
}

double NVHD::getSalary()
{
	return this->salary * countDay();
}


NVHD::~NVHD()
{
	cout << "NVHD" << endl;
}

