#pragma once
#include "var.h"


void outPut() {
    cout  << "Bang don hinh thu: " << count << endl;
    cout << "c" << "\t";
    for ( size_t i=0; i<x_num; ++i ){
    	cout  << left << setw (10) << c[i] << "\t";	// hien thi he so cac bien ham muc tieu
	}
    cout << z << endl;

    cout << " " << "\t";
    
    for ( size_t i=0; i<x_num; ++i ) {
        cout << "x" << i+1 << left << setw (9) << "\t";		// cac bien
        
    }
    cout << "f(x)" << "\t" << endl;
	
    for ( size_t i=0; i<st_num; ++i ) {
        cout << "x[" << base_id[i] << "]\t";	// vecto co so J
        for( size_t j = 0 ; j < x_num ; ++j ){	// hien thi ma tran
        	cout  << left << setw (10) << setprecision(3) << a[i][j] << "\t";
		}
        cout << b[i] << "\t" << endl;	  //
    }

    cout << "Delta " << "\t";
    for (size_t i=0; i<x_num; ++i) {
        cout  << left << setw (10) << setprecision(3) << sga[i] << "\t" ;
    }
    cout << endl;
}

void _iterator() {
    size_t k_f, k_a;
    size_t mainElerow;
    double mainElevalue;

    //Delta
    sga.resize(x_num);
    for (size_t i=0; i<x_num; ++i) {    // duyet tung cot
        sga[i] = c[i]; // delta = 0
        for (size_t j=0; j<st_num; ++j){   // duyet 
        	sga[i] -= c[base_id[j]-1] * a[j][i];
		}
		
		// neu delta o cot vecto don vi thi delta == 0
        for (size_t j=0; j<st_num; ++j){
        	if (i==base_id[j]-1){
        		sga[i] = 0;		//
			}
		}
    }
	//tinh gia tri an gia 
    z = 0;
    for (size_t j=0; j<st_num; ++j){
    	z -= c[base_id[j]-1] * b[j];
	}

    outPut();  // hien thi bang don hinh

	// xet cac delta > 0
    size_t k_ = 0;
    for (; k_<x_num; ++k_){
    	if (sga[k_] > 0){
    		break;
		}
	}
    if (k_ == x_num) {  // xet k_ == so bien
        for (size_t i=0; i<x_num; ++i) {
            k_f = k_a = 0;
            for(size_t j=0; j<ar_num; ++j){
            	if(i==ar_id[j]) k_a=1;  // gia tri == 1 cua vecto donvi
			}
            if(sga[i]==0 && k_a!=1) {
                for(size_t j=0; j<st_num; ++j){
                	if(i==base_id[j]-1){
                		k_f=1;
					}
				}
                if(k_f==0) {
					status=-1; 
					return;
				}
            }
        }
        status = 1;
        return;
    }

    for(size_t i=0; i<x_num; ++i) {
        k_f = 0;
        if(sga[i] > 0) {	// delta > 0
            for(size_t j=0; j<st_num; ++j){
            	if(a[j][i]>0){		// he so > 0
            		k_f=1;
				}
			}
            if(k_f!=1) {
				status=0;	// vo han 
				return;
			}
        }
    }

    // tim cot xoay
    double sgaMax = -INT_MAX;
    for (size_t i=0; i<x_num; ++i) {
        if (sga[i]>0 && sgaMax<sga[i] ) { 	// detal > 0 va lon nhat
            in = i;
            sgaMax = sga[i];
        }
    }

    //  tim hang xoay
    double staMin = INT_MAX;// phan tu xoay	 
    for (size_t i=0; i<st_num; ++i) {
        if (b[i]/a[i][in]<=staMin && a[i][in]>0) {    // xet ti le
            bool exc = false;
            if(b[i]/a[i][in] == staMin) {
                for (size_t j=0; j<x_num; ++j) {
                    if (j == in){
                    	continue;
					}
                    if (a[i][j]/a[i][in]<a[mainElerow][j]/a[mainElerow][in]) {
                        exc = true;
                        break;
                    }
                }

            } else exc = true;
            if (exc) {
                out = base_id[i];	// hang xoay
                mainElerow = i;	// vi tri ptu xoay
                staMin = b[i]/a[i][in];	// phan tu xoay
            }
        }
    }





    cout << "Vecto co so: (";
    for (size_t i=0; i<st_num; ++i){
    	cout << " x[" << base_id[i] << "]";
	}
    cout << ")\t\t";
    cout << "Hang xoay: x[" << out << "]\t\t";
    cout << "Cot xoay: x[" << in+1 << "]" << endl << endl;

    for (size_t i=0; i<st_num; ++i){	// thay bien PA
    	if (base_id[i]==out){
    		base_id[i]=in+1;
		}
	}
	
	// tinh lai bang don hinh
    mainElevalue = a[mainElerow][in];
    // cac gia tri tren cung hang voi ptu xoay  => lay gtri / gtri ptu xoay
    b[mainElerow] /= mainElevalue;
    for (size_t i=0; i<x_num; ++i){
    	a[mainElerow][i]/=mainElevalue;
	}
    for (size_t i=0; i<st_num; ++i) {
        if (i!=mainElerow) {
            b[i] -= b[mainElerow]*a[i][in];	// tinh lai b
            mainElevalue = a[i][in];
            for (size_t j=0; j<x_num; ++j){
            	a[i][j] -= a[mainElerow][j]*mainElevalue;	// tinh lai cac he so
			}
        }
    }

    ++count;
    if (count > 200) {	// neu so lan bien doi qua lon
        status = -2;
        return;
    }

    _iterator();	// tiep tuc bien doi

}

