#include "NVBC.h"

NVBC::NVBC()
{
}

NVBC::NVBC(string id, string name, Date d, bool sex, double coefficient) : NhanVien(id, name, d, sex, coefficient)
{
	this->coefficientSalary = coefficient;
}

double NVBC::getSalary()
{
	return coefficientSalary;
}



NVBC::~NVBC()
{
}


ostream & operator<<(ostream & o, NVBC &nv)
{
	o << nv.name << endl;
	o << nv.getSalary() << endl;
	return o;
}
