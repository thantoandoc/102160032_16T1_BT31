#include "Node.h"

Node::Node(NhanVien *nv)
{
	this->nv = nv;
	this->next = NULL;
}


Node::~Node()
{
}
