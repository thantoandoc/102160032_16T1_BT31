#pragma once
#include "NhanVien.h"
class Node
{
public:
	NhanVien * nv;
	Node * next;
public:
	Node(NhanVien * nv);
	~Node();
};

