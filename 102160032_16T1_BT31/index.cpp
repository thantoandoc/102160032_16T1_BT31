#include <iostream>
#include "NVHD.h"
#include "NVBC.h"
#include "QLNV.h"
#include "index.h"
using namespace std;

bool ascending(string o1, string o2) {
	return o1 < o2;
}
bool descending(string o1, string o2) {
	return o1 > o2;
}

void init(QLNV * ql) {
	NVHD * nv1 = new NVHD("10216032", "Le Cam", Date(8, 3, 2018), 1, 100000);
	NVHD * nv2 = new NVHD("10216033", "Nguyen Manh Cuong", Date(10, 1, 2018), 1, 100000);
	NVHD * nv3 = new NVHD("10216034", "Ngo Tri Dat", Date(13, 8, 2018), 1, 100000);
	NVBC * nv5 = new NVBC("10216035", "Nguyen Manh Dung", Date(25, 12, 2013), 1, 2.3);
	NVBC * nv4 = new NVBC("10216031", "Nguyen The An", Date(25, 12, 2014), 1, 2.3);
	
	ql->add(nv1);
	ql->add(nv2);
	ql->add(nv5);
	ql->add(nv3);
	
	ql->add(nv4);
	
	
}
void menu() {
	cout << "DANH SACH CHUC NANG: "<< endl;
	cout << "1 . HIEN THI DANH SACH NHAN VIEN" << endl;
	cout << "2 . THEM NHAN VIEN BIEN CHE (NVBC)" << endl;
	cout << "3 . THEM NHAN VIEN HOP DONG (NVHD)" << endl;
	cout << "4 . CAP NHAT THONG TIN NHAN VIEN" << endl;
	cout << "5 . XOA NHAN VIEN" << endl;
	cout << "6 . TIM KIEM THEO MA NHAN VIEN" << endl;
	cout << "7 . TIM KIEM THEO TEN NHAN VIEN" << endl;
	cout << "8 . SAP XEP NHAN VIEN THEO MA NHAN VIEN" << endl;
	cout << "9 . SAP XEP NHAN VIEN THEO TEN NHAN VIEN" << endl;
	cout << "0 . KET THUC CHUONG TRINH" << endl;
}
void xuLy(QLNV * ql) {
	int choose = 0;
	menu();
	cout << endl << "LUA CHON CUA BAN: "; cin >> choose;
	switch (choose) {
		case 1: {
			cout << ql << endl;
			break;
		}

		case 2: {
			NVBC * nv = new NVBC();
			cin >> nv;
			ql->add(nv);
			cout << ql << endl;
			break;
		}
		
		case 3: {
			NVHD * nv = new NVHD();
			cin >> nv;
			ql->add(nv);
			cout << ql << endl;
			break;
		}
		case 4: {
			int idx = -1; 
			cout << "NHAP VI TRI NHAN VIEN BAN CAN THAY DOI:";
			cin >> idx;
			ql->update(idx);
			break;
		}
		case 5: {
			int idx = -1, length = 0;
			cout << "NHAP VI TRI NHAN VIEN BAN CAN XOA:";
			cin >> idx;
			cout << "NHAP SO LUONG NHAN VIEN BAN CAN XOA TU VI TRI XOA:";
			cin >> length;
			ql->erase(idx, length);
			break;
		}
		case 6: {
			string id = "";
			cout << "NHAP MA NHAN VIEN BAN CAN TIM KIEM:";
			getline(cin, id);
			ql->searchById(id);
			break;
		}
		case 7: {
			string name = "";
			cout << "NHAP TEN NHAN VIEN BAN CAN TIM KIEM:";
			getline(cin, name);
			ql->searchByName(name);
			break;
		}
		case 8: {
			int k = 0;
			do {
				cout << "1_SAP XEP TANG DAN THEO MA NHAN VIEN: " << endl;
				cout << "2_SAP XEP GIAM DAN THEO MA NHAN VIEN: " << endl;
				cout << "Nhap che do: ";
				cin >> k;
				if (k <= 2 && k >= 1) break;
				cout << "Nhap lai che do " << endl;
			} while (true);
			cout << "BANG GHI NHAN VIEN SAP XEP TANG DAN THEO MA NHAN VIEN" << endl;
			if (k == 1) {
				ql->sortByID(ascending);
			}
			else {
				ql->sortByID(descending);
			}
			break;
		}
		case 9: {
			cout << "BANG GHI NHAN VIEN SAP XEP TANG DAN THEO TEN NHAN VIEN" << endl;
			ql->sortByName();
			break;
		}
		default:
			exit(1);
			break;
	}

}

int main() {

	QLNV * ql = new QLNV("LE CAM _ 16T1");
	init(ql);
	bool flag = true;
	while (flag) {
		xuLy(ql);
	}

	system("pause");
	return 0;
}