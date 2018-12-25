#pragma once
#include "NhanVien.h"
class NVHD : public NhanVien
{
protected:
	double salaryDay; //lương công nhật
public:
	NVHD();
	NVHD(string id, string name, Date d, bool sex, double salary);
	double getSalary();
	~NVHD();
	friend istream & operator >> (istream &, NVHD &);
	friend ostream & operator << (ostream &, NVHD &);
	friend ostream & operator << (ostream &, NVHD *);
};

