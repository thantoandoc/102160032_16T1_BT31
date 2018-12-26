#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include "QueueList.h"
using namespace std;
class QLNV
{
private:
	string name;	//ten nhan vien
	QueueList * arr;	// danh sach nhan
public:
	QLNV(string name);
	QLNV(QLNV *);
	void add(NhanVien * nv);
	int getSize();
	void sortByID(bool(*cmp)(string, string));
	void sortByName();
	void searchById(string);
	void searchByName(string);
	void erase(int idx, int length = 1);
	void update(int idx);
	~QLNV();
	friend ostream & operator << (ostream &, QLNV *);
	NhanVien * operator [] (const int idx);
	QLNV * operator = (QLNV *);
};

