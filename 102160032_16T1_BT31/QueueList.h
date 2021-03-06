#pragma once
#include "Node.h"

class QueueList
{
private:
	Node * front, *rear;
public:
	QueueList();
	QueueList(QueueList *);
	void push(NhanVien *nv);
	NhanVien * pop();
	void erase(int idx, int len);
	void update(int idx);
	int size();
	bool empty();
	~QueueList();
	friend ostream & operator << (ostream &, QueueList *);
	NhanVien * operator [] (const int idx);
	QueueList * operator= (QueueList *);
};

