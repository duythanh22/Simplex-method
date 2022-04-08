
#include <iostream>
#include "normalize.h"
#include "input.h"
#include "iterator.h"
#include "show.h"

using namespace std;


void _result() {
    x.resize(x_num);
    cout << " *x = (";
    for (size_t i=0; i<x_num; ++i) {
        for (size_t j=0; j<st_num; ++j) {
            if (i==base_id[j]-1) {
                x[i] = b[j];
                break;
            } 
			else{
				x[i] = 0;
			}
        }
        cout << "  " << x[i] ;
    }
    cout << ")\t";
    if(min_max == 1){
    	z *= -1;
	}
	else{
		z *= 1;
	}
    cout << " *f = " << z << endl << endl;
}


void dataClear() {
    a.clear();  b.clear();  c.clear();
    ct.clear(); sga.clear();    x.clear();
    eql.clear();
    ar_id.clear();  base_id.clear();
    add_num = 0;    ba_num = 0;     ar_num = 0;
    step = 1;       section = 1;    count = 1;
    z = 0;
}

int main()
{
    while(1){
		inPut();

        showOr();

        normalize();

        ct.resize(x_num);

        for (size_t i=0; i<x_num; ++i) {
            size_t j = 0;
            for (; j<ar_num; ++j){
            	if (ar_id[j]-1 == i) break;
			}
            if (j == ar_num){
            	ct[i] = 0;
			}
            else{
            	ct[i] = -1;
			}
        }
        swap(c, ct);	// hoan doi ham muc tieu
        cout << "Bien doi lan 1 : " << endl;
        cout << "Ket qua : " ;
        showPr();
        _iterator();
        if (status == -2) {
            cout << "Lap qua gioi han. Bai toan khong co loi giai huu han!" << endl;
            exit(0);
        }
        _result();

        if (z != 0) {	// neu an gia > 0 thi bai toan khong co PA
            cout << "Bai toan khong co phuong an." << endl;
            exit(0);
        }

        swap(c, ct);
        x_num -= ar_num;
        ar_num = 0;
        cout << "Bien doi lan 2 : " << endl;
        showPr();
        ++step;
        _iterator();
        cout << endl;

        switch (status) {
        case 1:
            cout << "Phuong an toi uu cua bai toan : " << endl;
            _result();
            break;
        case 0:
            cout << "Thuar toan lap vo han." << endl;
            break;
        case -1:
            cout << "Phuong an thay the." << endl;
            _result();
            break;
        case -2:
            cout << "Bai toan khong co loi giai huu han." << endl;
            break;
        }
      
     	size_t st = 0;
        while (1) {
        	cout << "\t\t\t\t ---MENU--- \t\t\t";
            cout << "\nLua chon : 1.Nhap du lieu bai toan moi.\t 2.Dung chuong trinh - (1/2): ";
            cin >> st ;
            if (st!=1 && st!=2) {
                cout << "\n *** Loi! Vui long nhap dung lua chon." << endl;
                continue;
            } else  break;
        }
        if (st == 1) {
            dataClear();
            continue;
        }
        else{
			cout << "\n\n\tCAM ON BAN DA SU DUNG CHUONG TRINH! HEN GAP LAI.\n";
		 	return 0;
		}
	}

    return 0;
}
