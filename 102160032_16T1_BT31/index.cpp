#include <iostream>
#include "NVHD.h"
#include "QLNV.h"
#include "index.h"
using namespace std;

int main() {
	NhanVien * nv1 = new NVHD("10216032", "Le Cam", Date(1, 1, 2018), 1, 10);
	NhanVien * nv2 = new NVHD("10216033", "Nguyen Manh Cuong", Date(1, 1, 2018), 1, 10);
	NhanVien * nv3 = new NVHD("10216034", "Ngo Tri Dat", Date(1, 1, 2018), 1, 10);
	QLNV * ql = new QLNV("Admin");
	ql->add(nv1);
	ql->add(nv2);
	ql->add(nv3);
	cout << ql->getSize() << endl;
	cout << ql << endl;
	ql->searchByName("Le Cam");
	ql->sortByName();
	cout << ql << endl;
	system("pause");
	return 0;
}