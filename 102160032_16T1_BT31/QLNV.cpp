#include "QLNV.h"



QLNV::QLNV(string name)
{
	this->name = name;
	this->arr = new QueueList();
}

QLNV::QLNV(QLNV * quanly)
{
	this->name = quanly->name;
	this->arr = new QueueList(quanly->arr);
}

void QLNV::add(NhanVien * nv)
{
	arr->push(nv);
}

int QLNV::getSize()
{
	return arr->size();
}

int findMinimunID(QueueList * arr ,int maxIndex) {
	QueueList * temp = new QueueList(arr);
	int min_index = -1;
	string minID = "99999999";
	int s = temp->size();
	for (int i = 0; i < s; i++)
	{
		NhanVien * nv = temp->pop();
		if (minID.compare(nv->getID()) == 1 && i <= maxIndex)
		{
			min_index = i;
			minID = nv->getID();
		}
		
	}
	return min_index;
}

int findMinimunName(QueueList * arr, int maxIndex) {
	QueueList * temp = new QueueList(arr);
	int min_index = -1;
	string minName = "{}";
	int s = temp->size();
	for (int i = 0; i < s; i++)
	{
		NhanVien * nv = temp->pop();
		if (minName.compare(nv->getName()) == 1 && i <= maxIndex)
		{
			min_index = i;
			minName = nv->getName();
		}

	}
	return min_index;
}
void insert(QueueList * arr, int index) {
	NhanVien * temp = NULL;
	for (int i = 0; i <= arr->size(); i++) {
		NhanVien * cur = arr->pop();
		if (i == index) {
			temp = new NhanVien(cur);
		}
		else {
			arr->push(cur);
		}
	}
	if (temp != NULL) {
		arr->push(temp);
	}
}

void QLNV::sortByID()
{
	for (size_t i = 0; i < arr->size(); i++) {
		int min_index = findMinimunID(arr, arr->size() - i - 1);
		insert(arr, min_index);
	}
	
}

void QLNV::sortByName()
{
	for (size_t i = 0; i < arr->size(); i++) {
		int min_index = findMinimunName(arr, arr->size() - i - 1);
		insert(arr, min_index);
	}
}

void QLNV::searchById(string id)
{
	QueueList * result = new QueueList();
	QueueList * temp = new QueueList(arr);
	while (!temp->empty())
	{
		NhanVien * nv = temp->pop();
		if (id.compare(nv->getID()) == 0) {
			result->push(nv);
		}
	}
	cout << "Tim kiem theo ID :" << endl;
	cout << result << endl;
}

void QLNV::searchByName(string name)
{
	QueueList * result = new QueueList();
	QueueList * temp = new QueueList(arr);
	while (!temp->empty())
	{
		NhanVien * nv = temp->pop();
		if (name.compare(nv->getName()) == 0) {
			result->push(nv);
		}
	}
	cout << "Tim kiem theo ID :" << endl;
	cout << result << endl;
}

QLNV::~QLNV()
{
	delete arr;
}

NhanVien * QLNV::operator[](int idx)
{
	QueueList * temp = new QueueList(arr);
	if (idx < 0 || idx >= getSize()) {
		return nullptr;
	}
	for (int i = 0; i < idx; i++) {
		temp->pop();
	}
	return temp->pop();
}

QLNV * QLNV::operator=(QLNV * quanly)
{
	return quanly;
}

ostream & operator << (ostream &o, QLNV * quanly)
{
	QLNV* temp = new QLNV(quanly);
	o << "Ten Quan Ly: "<< temp->name << endl;
	for (int i = 0; i < 75; i++) {
		cout << "-";
	}
	cout << endl;
	o << setw(8) << "ID" << "|" << setw(30) << "Name" << "|" << setw(15) << "StartAt" << "|" << setw(7) << "Gender" << "|" << setw(10) << "Salary" << "|" << endl;
	for (int i = 0; i < 75; i++) {
		cout << "-";
	}
	cout << endl;
	while (!temp->arr->empty()) {
		cout << temp->arr->pop();
	}
	return o;
}
