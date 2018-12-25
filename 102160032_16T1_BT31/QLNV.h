#pragma once
#include "QueueList.h";
#include <string>
#include <iostream>
#include <iomanip>
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
	void sortByID();
	void sortByName();
	void searchById(string);
	void searchByName(string);
	~QLNV();
	friend ostream & operator << (ostream &, QLNV *);
	NhanVien * operator [] (const int idx);
	QLNV * operator = (QLNV *);
};

