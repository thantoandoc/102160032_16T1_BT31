#include "QueueList.h"



QueueList::QueueList()
{
	this->front = NULL;
	this->rear = NULL;
}

QueueList::QueueList(QueueList * q)
{
	this->front = q->front;
	this->rear = q->rear;
}

void QueueList::push(NhanVien * nv)
{
	Node * temp = new Node(nv);
	if (rear == NULL) {
		rear = front = temp;
		return;
	}
	this->rear->next = temp;
	this->rear = temp;
}

NhanVien * QueueList::pop()
{
	if (this->front == NULL) {
		return NULL;
	}
	NhanVien * temp = this->front->nv;
	this->front = this->front->next;
	if (this->front == NULL) this->rear = NULL;
	return temp;
}


void QueueList::erase(int idx, int len)
{
	int n = this->size();
	for (int i = 0; i < n; i++) {
		NhanVien *nv = this->pop();
		if (i > idx + len || i < idx) {
			this->push(nv);
		}else{
			delete nv;
		}
	}
}

void QueueList::update(int idx)
{
	string name;
	bool gender;
	Date date;
	double salary;
	cout << "Thong Tin Cap Nhat  Phan Tu Thu " << idx << " :" << endl;
	cin.ignore(true);
	cout << "Nhap Ten: "; getline(cin, name);
	cout << "Gioi Tinh: (1 - Nam / 0 - Nu) "; cin >> gender;
	cout << "Ngay Bat Dau Lam Viec: " << endl; cin >> date;
	cout << "Luong: "; cin >> salary;
	(*this)[idx]->setName(name);
	(*this)[idx]->setGender(gender);
	(*this)[idx]->setBirthDay(date);
	(*this)[idx]->setSalary(salary);
}

int QueueList::size()
{
	Node * temp = front;
	int counter = 0;
	while (temp)
	{
		counter++;
		temp = temp->next;
	}
	return counter;
}

bool QueueList::empty()
{
	return this->front == this->rear && this->front == NULL;
}


QueueList::~QueueList()
{
}

NhanVien * QueueList::operator[](const int idx)
{
	QueueList *temp = new QueueList(this);
	if (idx < 0 || idx >= size()) {
		return nullptr;
	}
	for (int i = 0; i < idx; i++) {
		temp->pop();
	}
	return 	temp->pop();
}

QueueList * QueueList::operator=(QueueList *q)
{
	return new QueueList(q);
}

ostream & operator<<(ostream & o, QueueList * q)
{
	o << setw(8) << "ID" <<"|"<< setw(30) << "Name" << "|" << setw(10) << "StartAt" << "|" << setw(7) << "Gender" << "|" << setw(10) << "Salary" << "|" << endl;
	while (!q->empty())
	{
		o << q->pop() << endl;
	}
	return o;
}
