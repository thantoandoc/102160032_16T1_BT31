#include "NVHD.h"



NVHD::NVHD()
{
}

NVHD::NVHD(string id, string name, Date d, bool sex, double salary) : NhanVien(id, name, d, sex, salary)
{
	this->salaryDay = salary;
}

double NVHD::getSalary()
{
	return this->salary * 15;
}


NVHD::~NVHD()
{
}




ostream & operator<<(ostream & o, NVHD &nv)
{
	o << nv.name << endl;
	o << nv.getSalary() << endl;
	return o;
}

ostream & operator<<(ostream &o, NVHD *nv)
{
	o << nv->name << endl;
	o << nv->getSalary() << endl;
	return o;
}
