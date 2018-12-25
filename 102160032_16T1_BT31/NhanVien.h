#pragma once
#include <iostream>
#include <iomanip>
#include <string>
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
	string getID();
	string getName();
	bool getGender();
	double getSalary();
	~NhanVien();
	friend ostream & operator << (ostream &, NhanVien *);
};

