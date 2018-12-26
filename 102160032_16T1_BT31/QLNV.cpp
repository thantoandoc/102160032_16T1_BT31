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

void insert(QueueList * arr, int index) {
	NhanVien * temp = NULL;
	for (int i = 0; i <= arr->size(); i++) {
		NhanVien * cur = arr->pop();
		if (i == index) {
			temp = cur;
		}
		else {
			arr->push(cur);
		}
	}
	if (temp != NULL) {
		arr->push(temp);
	}
}

int findMinimunID(QueueList * arr ,int maxIndex, bool (*cmp)(string , string)) {
	QueueList * temp = new QueueList(arr);
	int min_index = -1;

	string minID = !cmp("99999999", "00000000") ? "99999999" : "00000000";

	for (int i = 0; i <= maxIndex; i++)
	{
		NhanVien * nv = temp->pop();
		if (!cmp(minID,nv->getID())) {
			min_index = i;
			minID = nv->getID();
		}
		
	}

	return min_index;
}

void QLNV::sortByID(bool(*cmp)(string, string))
{
	int n = arr->size();
	for (int i = 0; i < n ; i++) {
		int min_index = findMinimunID(arr, arr->size() - i - 1, cmp);
		insert(arr, min_index);
	}
	cout << "SAP XEP THEO MA NHAN VIEN: " << endl << this;
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



void QLNV::sortByName()
{
	int n = arr->size();
	for (int i = 0; i < n; i++) {
		int min_index = findMinimunName(arr, arr->size() - i - 1);
		insert(arr, min_index);
	}
	cout << "SAP XEP THEO TEN: " << endl << this;
}

void QLNV::searchById(string id)
{
	QLNV * result = new QLNV(this->name);
	QueueList * temp = new QueueList(arr);
	while (!temp->empty())
	{
		NhanVien * nv = temp->pop();
		if (id.compare(nv->getID()) == 0) {
			result->arr->push(nv);
		}
	}
	cout << "Tim kiem theo ma nhan vien :"<< id << endl;
	cout << result << endl;
}

void QLNV::searchByName(string name)
{
	QLNV * result = new QLNV(this->name);
	QueueList * temp = new QueueList(arr);
	while (!temp->empty())
	{
		NhanVien * nv = temp->pop();
		if (name.compare(nv->getName()) == 0) {
			result->arr->push(nv);
		}
	}
	cout << "Tim kiem theo ten :" << name << endl;
	cout << result << endl;
}

void QLNV::erase(int idx, int length)
{
	if (idx >= getSize() || idx < 0) {
		cout << endl << "KHONG TIM THAY NHAN VIEN O VI TRI NAY -_-" << endl << endl;
		return;
	}
	if (length > 0 && length + idx >= getSize() || length < 0) {
		cout << endl << "KHONG TIM THAY NHAN VIEN O VI TRI NAY -_-" << endl << endl;
		return;
	}
	this->arr->erase(idx, length - 1);
	cout << "BANG GHI SAU KHI XOA PHAN TU idx = " << idx << endl;
	cout << this;
}

void QLNV::update(int idx)
{
	if (idx >= getSize() || idx < 0) {
		cout << endl << "KHONG TIM THAY NHAN VIEN O VI TRI NAY -_-" << endl << endl;
		return;
	}
	this->arr->update(idx);
	cout << "BANG GHI SAU KHI CAP NHAT : " << endl << this;
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
	for (int i = 0; i < 70; i++) {
		cout << "-";
	}
	cout << endl;
	o << setw(8) << "ID" << "|" << setw(30) << "Name" << "|" << setw(10) << "StartAt" << "|" << setw(7) << "Gender" << "|" << setw(10) << "Salary" << "|" << endl;
	for (int i = 0; i < 70; i++) {
		cout << "-";
	}
	cout << endl;
	while (!temp->arr->empty()) {
		cout << temp->arr->pop();
	}
	return o;
}
