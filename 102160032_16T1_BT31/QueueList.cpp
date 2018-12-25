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
	o << setw(8) << "ID" <<"|"<< setw(30) << "Name" << "|" << setw(15) << "StartAt" << "|" << setw(7) << "Gender" << "|" << setw(10) << "Salary" << "|" << endl;
	while (!q->empty())
	{
		o << q->pop() << endl;
	}
	return o;
}
