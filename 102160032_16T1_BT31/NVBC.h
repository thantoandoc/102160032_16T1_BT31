#pragma once

#include "NhanVien.h"


class NVBC : public NhanVien
{
protected:
	double coefficientSalary; // hệ số lương 
public:
	NVBC();
	NVBC(string id, string name, Date d, bool sex, double coefficient);
	double getSalary();
	~NVBC();
	friend istream & operator >> (istream &, NVBC *);
	friend ostream & operator << (ostream &, NhanVien *);
};

