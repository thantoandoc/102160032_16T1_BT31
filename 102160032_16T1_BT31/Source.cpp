#include <iostream>
#include "NVBC.h"
#include "NVHD.h"
using namespace std;

bool checkID(string id) {

	if (id.length() != 8 || id[0] < '1' || id[0] > '9') {
		return false;
	}
	for (int i = 1; i < 8; i++) {
		if (id[i] < '0' || id[i] > '9') {
			return false;
		}
	}
	return true;
}

istream & operator>>(istream &in, NVBC * nv)
{
	in.ignore(true);
	do
	{
		cout << "Nhap Ma Nhan Vien :";
		in.ignore(0);
		getline(in, nv->id);
	} while (!checkID(nv->id));
	in.ignore(0);
	cout << "Nhap Ten Nhan Vien :"; getline(in, nv->name);;
	in.ignore(0);
	cout << "Gioi tinh (1_Nam/0_Nu) :"; in >> nv->sex;
	in.ignore(0);
	cout << "Thoi gian bat dau lam viec :" << endl; in >> nv->startTime;
	in.ignore(0);
	cout << "He So Luong :"; in >> nv->salary;
	return in;
}

istream & operator>>(istream &in, NVHD  * nv)
{
	in.ignore(true);
	do
	{
		cout << "Nhap Ma Nhan Vien :";
		in.ignore(0);
		getline(in, nv->id);
	} while (!checkID(nv->id));
	in.ignore(0);
	cout << "Nhap Ten Nhan Vien :"; getline(in, nv->name);;
	in.ignore(0);
	cout << "Gioi tinh (1_Nam/0_Nu) :"; in >> nv->sex;
	in.ignore(0);
	cout << "Thoi gian bat dau lam viec :" << endl; in >> nv->startTime;
	in.ignore(0);
	cout << "Luong 1 ngay :"; in >> nv->salary;
	return in;
}
