#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <chrono>
#include "Date.h"
using namespace std;
class NhanVien
{
protected:
	string id;			// mã nhân viên
	string name;		// tên nhân viên
	Date startTime;		// thời gian bắt đầu làm việc
	bool sex;			// giới tính	
	double salary;		// lương
public:
	NhanVien();
	NhanVien(string, string, Date, bool, double);
	NhanVien(const NhanVien *);
	void setName(string name);
	void setGender(bool gender);
	void setBirthDay(Date d);
	void setSalary(double salary);
	string getID();
	string getName();
	bool getGender();
	virtual double getSalary();
	virtual ~NhanVien();
	friend ostream & operator << (ostream &, NhanVien *);
};

