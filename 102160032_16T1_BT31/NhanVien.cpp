#include "NhanVien.h"



NhanVien::NhanVien()
{
}

NhanVien::NhanVien(string ID, string Name, Date d, bool sex, double salary)
{
	this->id = ID;
	this->name = Name;
	this->startTime = d;
	this->sex = sex;
	this->salary = salary;
}

NhanVien::NhanVien(const NhanVien * nv)
{
	this->id = nv->id;
	this->name = nv->name;
	this->startTime = nv->startTime;
	this->sex = nv->sex;
	this->salary = nv->salary;
}

void NhanVien::setName(string name)
{
	this->name = name;
}

void NhanVien::setGender(bool gender)
{
	this->sex = gender;
}

void NhanVien::setBirthDay(Date d)
{
	this->startTime = d;
}

void NhanVien::setSalary(double salary)
{
	this->salary = salary;
}

string NhanVien::getID()
{
	return string(id);
}

string NhanVien::getName()
{
	return string(name);
}

bool NhanVien::getGender()
{
	return sex;
}

double NhanVien::getSalary()
{
	return salary;
}


NhanVien::~NhanVien()
{
}

ostream & operator<<(ostream & o, NhanVien *nv)
{
	o << setw(8) <<nv->id << "|" << setw(30) << nv->name << "|" << setw(10) << nv->startTime << "|" << setw(7) << (nv->sex ? "Nam" : "Nu") << "|" << setw(10) << setprecision(10)<< nv->getSalary() << "|" << endl;
	for (int i = 0; i < 70; i++) {
		cout << "-";
	}
	cout << endl;
	return o;
}
